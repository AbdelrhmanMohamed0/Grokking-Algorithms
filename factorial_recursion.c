#include <stdio.h>
#include <stdlib.h>
unsigned long long factorial(int num);
int main(void)
{
    int num = 0;
    unsigned long long fact = 0;
    printf("please enter positive number you need to get factorial for it \n");
    scanf("%d", &num);
    fact = factorial(num);
    printf("factorial for %d is %llu\n", num, fact);
    return 0;
}

unsigned long long factorial(int num)
{
    if (num == 1)
        return 1;
    else
        return num * factorial(num - 1);
}