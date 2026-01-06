#include <stdio.h>

void line_detect(int value[], int label[], int N, int threshold);

int count(int label[], int black_count, int N);

double average(int line, int label[], int N);

int main(void)
{
    int N, i, j;
    int threshold;

    printf("센서 개수 입력(0~16): ");
    scanf("%d", &N);

    int value[N];
    int label[N];

    for(i=0; i<N; i++)
    {
        printf("%d번째 센서로부터 입력되는 값: ", i+1);
        scanf("%d", &value[i]);
        printf("\n");
    }

    printf("threshold = ");
    scanf("%d", &threshold);

    line_detect(value, label, N, threshold);

    int black_count = 0;

    int line;
    double index_average;

    line = count(label, black_count, N);
    index_average = average(line, label, N);

    printf("label = ");
    for(j = 0; j < N; j++)
    {
        printf("%3d", label[j]);
    }
    printf("\n");

    printf("black_count = %d\n", line);
    printf("index_avg = %.2lf\n", index_average);

    return 0;
}

//line 판별 함수
void line_detect(int value[], int label[], int N, int threshold)
{
    int i;
    for(i=0; i<N; i++)
    {
        if (value[i]<threshold)
        {
            label[i] = 1;
        }
        else if (value[i]>=threshold)
        {
            label[i] = 0;
        }
    }
}

//black_count 개수 세는 함수
int count(int label[], int black_count, int N)
{
    int j;

    for(j=0; j < N; j++)
    {
        if(label[j] == 1)
        {
            black_count++;
        }
    }

    return black_count;
}

//index_avg 계산 함수
double average(int line, int label[], int N)
{
    int sum_index = 0;
    double index_avg = 0;
    int k;

    for(k=0; k<N; k++)
    {
        sum_index += k*label[k];
    }

    if(line > 0)
    {
        index_avg = sum_index/line;
    }
    else if(line == 0)
    {
        printf("라인 없음\n");
    }

    return index_avg;
}