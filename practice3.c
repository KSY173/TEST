#include <stdio.h>

void line_detect();

int main(void)
{
    int N, i;
    int threshold;

    printf("센서 개수 입력(0~16): ");
    scanf("%d", &N);

    int value[N];

    for(i=0; i<N; i++)
    {
        printf("%d번째 센서로부터 입력되는 값: ", i+1);
        scanf("%d", &value[i]);
        printf("\n");
    }

    printf("threshold = ");
    scanf("%d", &threshold);

    //line 판별 함수
    void line_detect(int value[i])
    {
        int i;

        for(i=0; i<N; i++)
        {
            if (value[i]<threshold)
            {
                label[i] = 1;
            }
            else if ()
        }

    }

    //black_count 개수 세는 함수

    //index_avg 계산 함수
}