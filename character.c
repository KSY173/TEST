#include <stdio.h>

/*
int main(void)
{
    char small, cap = 'B';

    if ((cap >= 'A') && (cap <= 'Z'))
    {
        small = cap + ('a' - 'A');
    }

    printf("capital letter: %c %c", cap, '\n');
    printf("small letter : %c", small);

    return 0;
}
*/


/*
int main(void)
{
    char ch1, ch2;
 
    scanf(" %c %c", &ch1, &ch2); // 공백, 엔터 등 무시하고 문자만 출력

    printf("[%c%c]", ch1, ch2);
    printf("%d", ch1);

    return 0;  
}
*/


/*
int main(void)
{
    char ch;
    int i;

    for(i = 0; i<3; i++)
    {
        scanf("%c", &ch);
        printf("%c\n", ch); //엔터까지 버퍼에 저장돼서 하나씩 입력하면 엔터 제외 문자 2개만 가능
        printf("%d\n", i);
    }

    return 0;
}
*/


/*
void my_gets(char *str, int size);

int main(void)
{
    char str[7];

    my_gets(str, sizeof(str));
    printf("입력한 문자열 : %s\n", str);

    return 0;
}

void my_gets(char *str, int size)
{
    int ch;
    int i = 0;

    ch = getchar();

    while ((ch != '\n') && (i < size- 1)) //문자열이니까 마지막에 널문자 때문에 배열 길이보다 -1
    {
        str[i] = ch;
        i++;
        ch = getchar();
    }

    str[i] = '\0';
}
*/



/*
int main(void)
{
    char str[9] = "Be happy!";

    printf("%s", str); //%s는 널문자 있는 곳까지 계속 읽는 것

    return 0;
}
*/



int main(void)
{
    int num;
    char grade;

    printf("학번 입력: ");
    scanf("%d", &num);
    //getchar();

    printf("학점 입력: ");
    //grade = getchar(); //이전의 getchar()를 지우면 이번 getchar()에서 버퍼에 남아있던 엔터를 받음
    scanf(" %c", &grade); //공백%c 로 받으면 이전 엔터도 다 날림, getchar()없어도 가능
    printf("학번 : %d, 학점 : %c", num, grade);

    return 0;
}