#include <stdio.h>
#include <stdlib.h>
int sum_recursion(int *array, int size);
int count(int *array, int size);
int max(int *array, int size);

int main(void)
{
    int array[5] = {1, 2, 3, 4, 5};
    int sum = 0;
    sum = sum_recursion(array, 5);
    printf("sum  of list is %d \n", sum);
    printf("number of element is %d \n", count(array, 5));
    printf("maximum element is %d \n", max(array, 5));
    return 0;
}

int sum_recursion(int *array, int size)
{
    if (size == 0)
        return 0;
    return array[0] + sum_recursion(array + 1, size - 1);
}

int count(int *array, int size)
{
    if (size == 0)
        return 0;
    return 1 + count(array + 1, size - 1);
}

int max(int *array, int size)
{
    if (size == 1)
        return array[0];
    int rest_max = max(array + 1, size - 1);
    return array[0] > rest_max ? array[0] : rest_max;
}