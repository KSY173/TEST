#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*int main(void)
{
    //10개 직접 입력하기 
    
    int vel[10];
    int acc = 0, dec = 0;
    int i;
    

    printf("vel [km/h]:");
    scanf("%d", vel);

    for(i = 0; i < 10; i++)
    {
        int delta = vel[i+1]-vel[i];
        
        if (delta >= 10)
        {
            acc += 1;
        }
        else if (delta >= -10)
        {
            dec += 1;
        }
    }

    printf("ac : %d\n", acc);
    printf("st : %d\n", dec);
    */

    //100개 난수로 입력
    /*
    int vel[101];
    int i,j;
    int acc = 0, dec = 0;

    srand(time(NULL));

    vel[0] = 0;

    for(i==1; i<100; i++)
    {
        vel[i] = rand() % 100;
    }

    for(j= 0; j < 100; j++)
    {
        int delta = vel[j+1]-vel[j];
        
        if (delta >= 10)
        {
            acc += 1;
        }
        else if (delta >= -10)
        {
            dec += 1;
        }
    }

    printf("acc : %d\n", acc);
    printf("dec : %d\n", dec);
    

    //증감 방향성 고정
    int vel[101];
    int i, j, k, l;
    int acc = 0, dec = 0, cnt = 0;

    vel[0] = 0;

    for(i = 1; i < 100; i++)
    {
        vel[i] = rand() % 101;
    }
        
    for(j=0; j<100; j++)
    {
        int delta = vel[j+1] - vel[j];

        if (((vel[j+1] > vel[j]) && (vel[j+1] > vel[j+2]))
        ||((vel[j+1] < vel[j]) && (vel[j+1] < vel[j+2])))
        {
            cnt += 1;
        }

        if(delta > 0)
        {
            vel[j+1] = vel[j] + rand()%10;
            acc += 1;
        }
        else if (delta < 0)
        {
            vel[j+1] = vel[j] - rand()%10;
            dec += 1;
        }

        if(cnt != 0 && acc < 10 && delta > 0)
            {
                vel[j+1] = vel[j] + rand()%10;
                acc += 1;
            }
            else if (cnt != 0 && dec < 10 && delta < 0)
            {
                vel[j+1] = vel[j] - rand()%10;
                dec += 1;
            }
    }
    
    for(k = 0; k<100; k++)
        {
            printf("%d\n", vel[k]);
        }

    return 0;
}*/

//delta를 +-20으로 제한
int main(void)
{
    int speed[100];
    int i;

    speed[0] = 0;

    for(i=1; i<100; i++)
    {
        speed[i] = rand()%101;
        int delta = speed[i+1]-speed[i];

        if (delta > 20)
        {
            speed[i+1] = speed[i] + rand()%21;
        }
        else if (delta < -20)
        {
            speed[i+1] = speed[i] - rand()%21;
        }
    }
}

// 무한 반복해서 0되면 프로그램 종료