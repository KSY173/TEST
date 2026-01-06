#include <stdio.h>

/*
void swap(int num[]);

int main(void)
{
    int num[2];
    num[0] = 10;
    num[1] = 20;

    swap(num);

    printf("a:%d, b:%d\n", num[0], num[1]);

    return 0;
}

void swap(int num[])
{
    int temp;

    temp = num[0];
    num[0] = num[1];
    num[1] = temp;

}
*/





/*
int main(void)
{
    int a = 10;
    int *p = &a;
    double *pd;

    pd = p;
    printf("%lf\n", *pd);
    //printf("%d\n", *(int *)pd);

    return 0;
}
*/



/*
void input_ary(double *pa, int size);
double find_max(double *pa, int size);

int main(void)
{
    double ary[5];
    double max;
    int size = sizeof(ary) / sizeof(ary[0]); //배열의 크기 구하는 것

    input_ary(ary, size);
    max = find_max(ary, size);
    printf("max of array : %.1lf\n", max);

    return 0;
}

void input_ary(double *pa, int size)
{
    int i;

    printf("%d개의 실수값 입력 : ", size);
    for (i = 0; i < size; i++)
    {
        scanf("%lf", pa + i);
    }
}

double find_max(double *pa, int size)
{
    double max;
    int i;

    max = pa[0];
    for(i = 1; i < size; i++)
    {
        if (pa[i] > max) max = pa[i];
    }

    return max;
}
*/



void print_month(int *mp)
{
    int i;

    for(i=0; i<12; i++)
    {
        int mth = mp[i];

        printf("%5d", mth);
        if((i + 1) % 5 == 0)
        {
            printf("\n");
        }
    }
}

int main(void)
{
    int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    print_month(month);

    return 0;
}

