#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100
#define MAXV 120
#define RUN_MIN 10 
#define STEP_MAX 9

int main(void)
{
    int vel[N];
    int i;

    srand((unsigned)time(NULL));

    vel[0] = 0;

    int remaining = N - 1; // vel[0] 빼고 시작할 때는 99개 남음

    int dir = +1; 

    int idx = 0; // 지금 인덱스는 0

    while(remaining > 0)
    {
        int run_len; // 10개 이상 되도록 조절해야 함

        if (remaining <= RUN_MIN) // 남은 게 10개 이하면 한 번에 처리
        {
            run_len = remaining;
        }
        else
        {
            int upper = 20; //너무 많아지지는 않도록 20개까지 조절

            if (upper > remaining) //남은 게 20개보다 적으면 최대를 현재 남은 개수로 하기
            {
                upper = remaining;
            }

            if (remaining > 20) //남은 게 20개 넘으면 다음 턴을 위해서 최소 10개는 남기기
            {
                int max_run = remaining - RUN_MIN;

                if (upper > max_run)
                {
                    upper = max_run;
                }

                run_len = RUN_MIN + (rand() % (upper - RUN_MIN + 1)); // 10<= run_len <= upper
            }
        }

        for (i=0; i < run_len; i++)
        {
            int step = rand() % (STEP_MAX + 1); // 델타는 0~9로 조절
            
            //속도는 0~120으로 범위 제한
            if (dir == +1)
            {
                if ((vel[idx] + step) > MAXV)
                {
                    step = MAXV - vel[idx];
                }
            }
            else 
            {
                if ((vel[idx] - step) < 0)
                {
                    step = vel[idx];
                }
            }

            vel[idx+1] = vel[idx] + dir * step;

            idx++;
        }

        //속도 계산한 만큼 남은 개수 조절
        remaining -= run_len;

        //계산 다 하고도 남았으면 방향 전환
        if (remaining > 0)
        {
            dir = -dir;
        }
    }

    int acc = 0, dec = 0;

    for ( i=0; i < N -1; i++)
    {
        int delta = vel[i+1] - vel[i];

        if ( delta>= 10)
        {
            acc++;
        }
        else if (delta <= -10)
        {
            dec++;
        }
    }

    printf("vel[0..99]:\n");
    for (i = 0; i < N; i++) 
    {
        printf("%3d ", vel[i]);
        
        if ((i + 1) % 20 == 0) 
        {
            printf("\n");
        }
    }

    //급가속, 급제동은 0이어야 함
    printf("\nacc(>=+10): %d\n", acc);
    printf("dec(<=-10): %d\n", dec);

    return 0;
}