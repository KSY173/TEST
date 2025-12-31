#include <stdio.h>

int avg(int x, int y)
{
    int average;

    average = (x + y)/2;

    return average;
}

int main(void)
{
    int a, b;
    int result = 0;

    printf("Insert the first number:");
    scanf("%d", &a);
    printf("Insert the second number:");
    scanf("%d", &b);

    result = avg(a, b);
    printf("Average of two numbers : %d\n", result);

    return 0;
}

