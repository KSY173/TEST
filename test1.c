#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
int main(void){

    int i=1;
    int j=1;

    for(i=1;i<6;i++)
    {
        for(j=1;j<6;j++)
        {
            if (i==j || (i+j)==6){
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
*/













/*
int main(void)
{
    srand(time(NULL));

    int min_index, i;
    int data = 360;
    double dist[360];

    for(i = 0; i < data; i++)
    {
        dist[i] = (rand() % 501);             //0 ~ 500cm
    }

    for(i = 0; i < (data-1); i++)
    {
        int step = (rand() % 20);
        int delta = dist[i+1] - dist[i];

        if (delta > 20)
        {
            dist[i+1] = dist[i] + step;
        }
        else if (delta < -20)
        {
            dist[i+1] = dist[i] - step;
        }

        if (dist[i] < 0)
        {
            dist[i] == 0;
        }
        else if (dist[i] > 500)
        {
            dist[i] == 500;
        }
    }

    int min = dist[0];

    for(i = 0; i < data; i++)
    {
        if(dist[i] < min)
        {
            min = dist[i];
            min_index = i;
        }
    }

    printf("min : %d\n", min);
    printf("min_index[degree] : %d\n", min_index);

    printf("%lf %lf %lf %lf %lf", dist[min_index - 2], dist[min_index-1], dist[min_index], dist[min_index+1], dist[min_index+2]);

    return 0;
}
*/










//10hz 일 때 1초 동안 distance 데이터 메모리에 저장, 1초만 메모리 할당하는 코드

int main(void)
{
    srand(time(NULL));

    int min_index, i;
    int data = 360;
    int *pd;
    int hz = 10;
    int time = 0;

    for(i = 0; i < data * hz; i++)
    {
        pd = (int *)malloc(sizeof(int)*data);

        if(pd == NULL)
        {
            printf("# 메모리가 부족합니다.\n");
            exit(1);
        }

        for(i = 0; i < data; i++)
        {
            pd[i] = (rand() % 501);
        }

        for(i = 0; i < (data-1); i++)
        {
            int step = (rand() % 20);
            int delta = pd[i+1] - pd[i];

            if (delta > 20)
            {
                pd[i+1] = pd[i] + step;
            }
            else if (delta < -20)
            {
                pd[i+1] = pd[i] - step;
            }

            if (pd[i] < 0)
            {
                pd[i] == 0;
            }
            else if (pd[i] > 500)
            {
                pd[i] == 500;
            }
        }

        int min = pd[0];

        for(i = 0; i < data; i++)
        {
            if(pd[i] < min)
            {
                min = pd[i];
                min_index = i;
            }
        }

        //1초 동안 작동했을 때의 최소값
        printf("min : %d\n", min);
        printf("min_index[degree] : %d\n", min_index);

        time++;

        free(pd);

        if(time == 10)      //10초 작동
        {
            break;
        }
    }

    return 0;
}
