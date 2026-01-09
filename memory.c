#include <stdio.h>
#include <stdlib.h>                         //malloc() 쓸 때 추가 필요
#include <string.h>

/*
int main(void)
{
    int *pi;
    double *pd;

    pi = (int *)malloc(sizeof(int));        //int형 크기만큼 heap영역에 메모리 공간을 생성 후 그 주소를 int형 주소로 변환
    
    if(pi == NULL)                          //메모리 공간이 없을 경우 NULL, 제대로 할당되었는지 확인
    {
        printf("# 메모리가 부족합니다.\n");
        exit(1);                            //프로그램 종료
    }
    
    pd = (double *)malloc(sizeof(double));

    *pi = 10;
    *pd = 3.4;

    printf("정수형으로 사용 : %d\n", *pi);
    printf("실수형으로 사용 : %.1lf\n", *pd);

    //메모리 사용 후 삭제 필수, malloc() 쓸 경우 무조건 free() 같이 사용
    free(pi);
    free(pd);

    return 0;
}
*/











/*
int main(void)
{
    int *pi;
    int size = 5;
    int count = 0;
    int num;
    int i;

    pi = (int *)calloc(size, sizeof(int));

    while (1)
    {
        printf("양수만 입력하세요 => ");
        scanf("%d", &num);

        if (num <= 0) break;                                //음수를 입력하면 for문에 있는 프린트로 이동

        if(count == size)                                   //할당한 크기를 다 쓰면 5개씩 더 추가해서 다시 할당
        {
            size += 5;
            pi = (int *)realloc(pi, size * sizeof(int));    //주소가 바뀌어도 다시 포인터로 주소 지정
        }

        pi[count++] = num;
    }

    for(i = 0; i < count; i++)
    {
        printf("%5d", pi[i]);                               //입력한 숫자들 순서대로 출력
    }

    free(pi);

    return 0;
}
*/












/*
int main(void)
{
    char temp[80];
    char *str[3];
    int i;

    for (i = 0; i< 3; i++)
    {
        printf("문자열을 입력하세요 : ");
        gets(temp);
        str[i] = (char *)malloc(strlen(temp) + 1);      
        strcpy(str[i], temp);
    }

    for (i = 0; i < 3; i++)
    {
        printf("%s\n", str[i]);
    }

    for (i = 0; i < 3; i++)
    {
        free(str[i]);
    }

    return 0;
}
*/
