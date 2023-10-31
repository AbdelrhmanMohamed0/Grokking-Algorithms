#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void binary_search(int *array, int size, int num, int **result);

int main(void)
{
    int array[] = {1, 3, 5, 9, 11, 20, 22};
    int num, *result = NULL;
    printf("enter number you need to search about it \n");
    if (scanf("%d", &num) == 1)
    {
        binary_search(array, sizeof(array) / sizeof(array[0]), num, &result);
        if (result != NULL)
        {
            printf("position of %d is %d\n", num, result - array);
        }
        else
        {
            printf("%d is not in the array\n", num);
        }
    }
    else
    {
        printf("invalid input\n");
    }
    return 0;
}

void binary_search(int *array, int size, int num, int **result)
{
    int low, high, mid;
    low = 0;
    high = size - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (num == array[mid])
        {
            *result = &array[mid];
            break;
        }
        else
        {
            if (array[mid] > num)
            {
                high = mid - 1;
            }
            else if (array[mid] < num)
            {
                low = mid + 1;
            }
        }
    }
}
