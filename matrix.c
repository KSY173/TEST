#include <stdio.h>

/*
int main(void)
{
    int score[2][3][4] = {
        {{72, 80, 95, 60},  {68, 98, 83, 90},   {75, 72, 84, 90}},
        {{66, 85, 90, 88},  {95, 92, 88, 95},   {43, 72, 56, 75}}
    };

    int i, j, k;                                //3차원 배열

    for(i = 0; i < 2; i++)
    {
        printf("%d반 점수...\n", i + 1);
        for(j = 0; j < 3; j++)
        {
            for(k = 0; k < 4; k++)
            {
                printf("%5d", score[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}
*/






/*
int main(void)
{
    int ary1[4] = {1, 2, 3, 4};
    int ary2[4] = {11, 12, 13, 14};
    int ary3[4] = {21, 22, 23, 24};
    int *pary[3] = {ary1, ary2, ary3};
    int i, j;

    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 4; j++)
        {
            printf("%5d", pary[i][j]);      //포인터를 2차원 배열로 사용
        }
        printf("\n");
    }

    return 0;
}
*/








int main(void)
{
    int ary[5][6] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20}
    };

    int i, j;

    for(i = 0; i < 4; i++)
    {
        int sum1 = 0; 

        for(j = 0; j < 5; j++)
        {
            sum1 += ary[i][j];
        }
        ary[i][j] = sum1;
    }

    for(i = 0; i < 5; i++)
    {
        int sum2 = 0;

        for(j = 0; j < 4; j++)
        {
            sum2 += ary[j][i];
        }
        ary[j][i] = sum2;
    }

    int sum = 0;

    for(i = 0; i < 4; i++)
    {
        sum += ary[i][5];

        ary[4][5] = sum;
    }
    

    for(i = 0; i < 5; i++)
    {        
        for(j = 0; j < 6; j++)
        {
            printf("%5d", ary[i][j]);
        }
        printf("\n");
    }

    return 0;
}