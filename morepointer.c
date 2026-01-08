#include <stdio.h>

/*
void swap_ptr(char **ppa, char **ppb);

int main(void)
{
    char *pa = "success";
    char *pb = "failure";

    printf("pa -> %s, pb -> %s\n", pa, pb);
    swap_ptr(&pa, &pb);                     //ppa에 pa의 주소값, ppb에 pb의 주소값을 받은 것
    printf("pa -> %s, pb -> %s\n", pa, pb);

    return 0;
}

void swap_ptr(char **ppa, char **ppb)
{
    char *pt;

    pt = *ppa;
    *ppa = *ppb;
    *ppb = pt;
}
*/












/*
int sum(int, int);                  //sum은 함수명 = 주소값

int main(void)
{
    int (*fp)(int, int);            //int (int, int)형 함수를 가리키는 포인터 fp, 함수가 아니라 포인터 fp를 선언한 것
    int res;

    fp = sum;                       //주소
    res = fp(10, 20);               //함수 포인터로 함수를 호출
    printf("result :%d\n", res);


    return 0;
}

int sum(int a, int b)
{
    return (a + b);
}
*/














