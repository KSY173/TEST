#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
int main(void)
{
    //10개 직접 입력하기 
    
    int vel[10];
    int acc = 0, dec = 0;
    int i, j, k;
    

    printf("vel [km/h]:");
    for(i=0; i<10; i++)
    {
        scanf("%d", &vel[i]);
    }

    for(j = 0; j <9; j++)
    {
        int delta = vel[j+1]-vel[j];
        
        if (delta >= 10)
        {
            acc += 1;
        }
        else if (delta <= -10)
        {
            dec += 1;
        }
    }

    printf("acc : %d\n", acc);
    printf("dec : %d\n", dec);

    return 0;
}

*/
    

//100개 난수로 입력
/*
int main(void)
{
    int vel[100];
    int i,j,k;
    int acc = 0, dec = 0;

    srand((unsigned)time(NULL));

    vel[0] = 0;

    for(i=1; i<100; i++)
    {
        vel[i] = rand() % 121; //0~120
    }

    for(j= 0; j < 99; j++)
    {
        int delta = vel[j+1]-vel[j];
        
        if (delta >= 10)
        {
            acc += 1;
        }
        else if (delta <= -10)
        {
            dec += 1;
        }
    }

    printf("acc : %d\n", acc);
    printf("dec : %d\n", dec);

    for(k=0; k<100; k++)
    {
        printf("%d\n", vel[k]);
    }

    return 0;
}
*/
    


//증감 방향성 고정
/*
#define N 100
#define MAXV 120
#define RUN_MIN 10   // 최소 유지 개수 -> delta 개수
#define STEP_MAX 9   // delta의 절대값 급제동 급가속 방지

int main(void)
{
    int vel[N];
    int i;

    srand((unsigned)time(NULL));

    vel[0] = 0;

    int remaining = N - 1; // 총 delta 개수 99개

    int dir = +1; // +1: 증가, -1: 감소 , 처음에는 증가로 유지

    int idx = 0;  // 현재 vel 인덱스

    while (remaining > 0) {
    
        int run_len; //현재 run의 길이, 최소 10개, 너무 길어지진 않도록 10~20 랜덤
        if (remaining <= RUN_MIN) {
            run_len = remaining; // 마지막에 10개 이하로 몇 개 안 남았으면 동일 범위 run으로 처리
        } else { //일반적인 상황
            int upper = 20; //너무 많아지지 않도록 상한선 20개 
            if (upper > remaining) upper = remaining; //20개보다 적으면 적은 거로 처리

            // 현 run에서 많이 쓰면 다음 run에서 최소 10개 유지 불가능
            if (remaining > RUN_MIN * 2) {
                int max_run = remaining - RUN_MIN; // 다음 run 최소 10 남기기
                if (upper > max_run) upper = max_run;
            }

            // RUN_MIN <= run_len <= upper
            run_len = RUN_MIN + (rand() % (upper - RUN_MIN + 1));
        }

        // run_len 동안 같은 방향으로 vel 생성
        for (i = 0; i < run_len; i++) {
            int step = rand() % (STEP_MAX + 1); // 0~9

            if (dir == +1) { // 증가일 때
                if (vel[idx] + step > MAXV) step = MAXV - vel[idx]; // 0~9로 조절
            } else { // 감소일 때
                if (vel[idx] - step < 0) step = vel[idx]; // 0~9로 조절
            }

            vel[idx + 1] = vel[idx] + dir * step;
            idx++;
        }

        remaining -= run_len; // 남은 delta개수 조정

        if (remaining > 0) dir = -dir; //다음 run이 남아있으면 방향 전환
    }

    int acc = 0, dec = 0;
    for (i = 0; i < N - 1; i++) {
        int delta = vel[i + 1] - vel[i];
        if (delta >= 10) acc++;
        else if (delta <= -10) dec++;
    }

    printf("vel[0..99]:\n");
    for (i = 0; i < N; i++) {
        printf("%3d ", vel[i]);
        if ((i + 1) % 20 == 0) printf("\n");
    }

    printf("\nacc(>=+10): %d\n", acc);
    printf("dec(<=-10): %d\n", dec);

    return 0;
}
*/

/*
//delta를 +-20으로 제한
int main(void)
{
    int speed[100];
    int i, j;

    speed[0] = 0;

    srand((unsigned)time(NULL));

    for(i=1; i<100; i++)
    {
         speed[i] = rand()%121;
    }

    for(j=0; j<99; j++)
    {

        if (speed[j+1]-speed[j] > 20)
        {
            speed[j+1] = speed[j] + (rand()%21+1);
        }
        else if (speed[j+1]-speed[j] < -20)
        {
            speed[j+1] = speed[j] - (rand()%21+1);
        }

        if (speed[j+1]>120) speed[j+1] = 120;
        if (speed[j+1]<0) speed[j+1] = 0;
    }

    return 0;
}
*/

// 무한 반복해서 0되면 프로그램 종료
int main(void)
{
    int speed[100];
    speed[0] = 0;
    int new_speed, i;
    int count = 1;

    srand((unsigned)time(NULL));

    while(1)
    {
        new_speed = rand()%121;

        if (new_speed == 0)
        {
            break;
        }
        
        if (count >= 100)
        {
            printf("배열이 가득 찼습니다.\n");
            break;
        }

        speed[count]=new_speed;
        count++;
    }

    for (i = 0; i < 100; i++) {
        printf("%3d ", speed[i]);
        if ((i + 1) % 20 == 0) printf("\n");
    }

    return 0;
}