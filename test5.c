#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int N;
    int i, j, k;
    int threshold;

    printf("센서 개수 입력(0~16): ");
    scanf("%d", &N);

    int value[N];
    int label[N];

    for(i = 0; i < N; i++)
    {
        printf("%d번째 센서로부터 입력되는 값: ", i+1);
        scanf("%d", &value[i]);
        printf("\n");
    }

    printf("threshold = ");
    scanf("%d", &threshold);

    int black_count = 0;
    int sum_index = 0;


    //함수
    for(j = 0; j < N; j++)
    {
        if(value[j] < threshold)
        {
            label[j] = 1;
            black_count++;
        }
        else
        {
            label[j] = 0;
        }

        sum_index += j*label[j];
    }

    double index_avg = 0;

    // index_avg 반환하는 함수
    if(black_count > 0)
    {
        index_avg = sum_index/black_count;
    }
    else if(black_count == 0)
    {
        printf("라인 없음\n");
    }

    printf("label = ");
    for(k = 0; k < N; k++)
    {
        printf("%3d", label[k]);
    }
    printf("\n");

    printf("black_count = %d\n", black_count);
    printf("index_avg = %.2lf\n", index_avg);

    return 0;
}
