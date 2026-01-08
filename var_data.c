#include <stdio.h>

/*
void assign10(void);
void assign20(void);

int a; // 전역변수는 자동으로 0을 초기화

int main(void)
{
    printf("함수 호출 전 a 값 : %d\n", a);

    assign10();
    assign20();

    printf("함수 호출 후 a 값 : %d\n", a);
    
    return 0;
}

void assign10(void)
{
    a = 10;
}

void assign20(void)
{
    int a;

    a = 20;
}
*/






/*
void auto_func(void);
void static_func(void);

int main(void)
{
    int i;

    printf("일반 지역 변수(auto)를 사용한 함수...\n");
    for(i = 0; i < 3; i++)
    {
        auto_func();
    }

    printf("정적 지역 변수(static)를 사용한 함수...\n");
    for(i = 0; i < 3; i++)
    {
        static_func();
    }

    return 0;
}

void auto_func(void)
{
    auto int a = 0;         //다시 함수 호출할 때마다 a값이 0으로 초기화 

    a++;
    printf("%d\n", a);
}

void static_func(void)
{
    static int a;           //함수 내에서 a값이 메모리에 기억됨, 0으로 초기화되고 시작

    a++;
    printf("%d\n", a);
}
*/





/*
void static_func(void)
{
    static int x = 1;   //다시 호출해도 이전 값을 기억하기 때문에 초기화 되지 않고 유지됨
    x += 2;
    printf("%d\n", x);
}

int main(void)
{
    static_func();
    static_func();
    static_func();
    static_func();

    return 0;
}
*/





//register 있을 때 없을 때 실행 시간 확인해보기
/*
int main(void)
{
    register int i;             //컴파일러가 알아서 처리해줘서 쓸 일 거의 없음
    auto int sum = 0;

    for (i = 1; i < 1000000; i++)
    {
        sum += i;
    }

    printf("%d\n", sum);

    return 0;
}
*/







/*
int *sum(int a, int b);     //포인터라서 주소를 반환하는데 이 주소가 가리키는 값이 int형이다

int main(void)
{
    int *resp;

    resp = sum(10, 20);
    printf("두 정수의 합 : %d\n", *resp);

    return 0;
}

int *sum(int a, int b)
{
    static int res;

    res = a + b;

    return &res;
}
*/