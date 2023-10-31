#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void selection_sort(int *array, int size);

int main(void)
{
    int array[] = {88, 5, 22, 10, 1, 15};
    int size;
    size = sizeof(array) / sizeof(array[0]);
    printf("array before sorting using selection sort algorithm \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d \t", array[i]);
    }
    selection_sort(array, size);
    printf("\n array after sorting  ascending  \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d \t", array[i]);
    }
    return 0;
}

void selection_sort(int *array, int size)
{
    int temp;
    int min_index;
    for (int i = 0; i < size - 1; i++)
    {
        min_index = i;
        for (int j = i + 1; j < size; j++)
        {
            if (array[j] < array[min_index])
            {
                min_index = j;
            }
        }
        temp = array[i];
        array[i] = array[min_index];
        array[min_index] = temp;
    }
}

/*  // bad because it compares and swaps elements that are already sorted //
   // which makes the time complexity for algorithm O(n^3)

for (int i = 0; i < size; i++)
    {
        for (int j = size - i - 1; j >= 0; j--)
        {
            for (int k = 0; k <j; k++)
            {
                if (array[k+1] < array[k])
                {
                    temp = array[k];
                    array[k] = array[k+1];
                    array[k+1] = temp;
                }
            }
        }
    }
*/
