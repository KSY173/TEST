#include <stdio.h>
#include <string.h>

/*
int main(void)
{
    FILE *fp;

    fp = fopen("a.txt", "r");               //현재 내 워크스페이스에 있는 파일만 가능, 아니면 풀주소 입력
    if (fp == NULL)
    {
        printf("파일이 열리지 않았습니다.\n");
        return 1;
    }

    printf("파일이 열렸습니다.\n");
    fclose(fp);

    return 0;
}
*/











/*
int main(void)
{
    FILE *fp;
    int ch;

    fp = fopen("a.txt", "r");
    if (fp == NULL)
    {
        printf("파일이 열리지 않았습니다.\n");
        return 1;
    }

    while(1)
    {
        ch = fgetc(fp);
        if (ch == EOF)
        {
            break;
        }
        putchar(ch);
    }
    fclose(fp);

    return 0;
}
*/












/*
int main(void)
{
    FILE *fp;
    char str[] = "banana";
    int i;

    fp = fopen("b.txt", "w");               //파일이 없으면 자동으로 생성됨
    if (fp == NULL)
    {
        printf("파일을 만들지 못했습니다.\n");
        return 1;
    }
    else
    {
        printf("파일이 열렸습니다.\n");
    }

    i = 0;
    while (str[i] != '\0')
    {
        fputc(str[i], fp);
        i++;
    }
    fputc('\n', fp);                        //마지막에 줄바꿈 포함
    fclose(fp);

    return 0;
}
*/









/*
int main(void)
{
    int ch;

    while (1)
    {
        ch = getchar();                 //문자열이 아닌 문자를 하나씩 받는 것
        if (ch == EOF)                  //직접 EOF 입력해줘야 함
        {
            break;
        }
        putchar(ch);                    //banana 한 번에 입력하면 버퍼에 저장되고 다 끌어와서 출력
    }

    return 0;
}
*/








/*
int main(void)
{
    int ch;

    while (1)
    {
        ch = fgetc(stdin);
        if (ch == EOF)
        {
            break;
        }
        fputc(ch, stdout);
    }

    return 0;
}
*/









/*
int main(void)
{
    FILE *fp;
    char str[] = "apple";
    int i;

    fp = fopen("b.txt", "w");                   //앞에서 썼던 banana가 지워지고 apple이 적힘
    if (fp == NULL)
    {
        printf("파일을 만들지 못했습니다.\n");
        return 1;
    }
    else
    {
        printf("파일이 열렸습니다.\n");
    }

    i = 0;
    while (str[i] != '\0')
    {
        fputc(str[i], fp);
        i++;
    }
    fputc('\n', fp);
    fclose(fp);

    return 0;
}
*/










/*
int main(void)
{
    FILE *fp;
    char str[] = "apple";
    int i;

    fp = fopen("b.txt", "a");                   //앞에 써둔 내용 그대로 두고 뒤에 추가 입력, 파일이 없다면 새로 만들고 입력
    if (fp == NULL)
    {
        printf("파일을 만들지 못했습니다.\n");
        return 1;
    }
    else
    {
        printf("파일이 열렸습니다.\n");
    }

    i = 0;
    while (str[i] != '\0')
    {
        fputc(str[i], fp);
        i++;
    }
    fputc('\n', fp);
    fclose(fp);

    return 0;
}
*/