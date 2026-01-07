#include <stdio.h>
#include <string.h>

/*
int main(void)
{
    printf("Initial address of the place "apple" is saved : %p\n", "apple"); //프린트문에서 선언하는 형태, 어딘가에 자동으로 저장됨, 그 시작하는 주소 값을 출력
    printf("Address of second character : %p\n", "apple" + 1);
    printf("First character : %c\n", *"apple");
    printf("Second character : %c\n", *("apple" + 1));
    printf("Third character expressed by array : %c\n", "apple"[2]);

    return 0;
}
*/      



/*
int main(void)
{
    char str[80];

    printf("Enter the string : ");
    scanf("%s", str);                   //사용자가 직접 입력
    printf("First word : %s\n", str);
    scanf("%s", str);                   //버퍼에 남아있던 것을 입력, 사용자가 입력하지 않음
    printf("Remaining second word in the buffer : %s\n", str);

    return 0;
}
*/



/*
int main(void)
{
    char str[80];

    printf("Blank included String : ");
    gets(str);

    printf("Entered string is %s.\n", str);

    printf("%c", str[0]);  //엔터만 쳤을 때 어떤 거 뜨는지 확인

    return 0;
}
*/





/*
int main(void)
{
    char str[80];                               //10으로 바꿔도 엔터 자리에 자동으로 널문자 포함, fgets로 받으면 무조건 마지막은 널문자로 채워짐

    printf("Blank included string : ");
    fgets(str, sizeof(str), stdin);
    str[strlen(str) - 1] = '\0';                // 입력 마지막에 치는 엔터를 널문자로 변환해서 출력 이상해지지 않도록 조정

    printf("Entered string is %s.\n", str);     //fgets는 엔터까지 포함해서 apple jam\n\0으로 저장됨

    return 0;
}
*/




/*
int main(void)
{
    int age;
    char name[20];

    printf("Enter the age : ");
    scanf("%d", &age);
    getchar();                          //gets(name)하기 전에 age 뒤에 남아있는 엔터 지워주기 
    
    printf("Enter the name : ");
    fgets(name, sizeof(name), stdin);   //getchar() 안 하면 age 입력 후의 엔터가 버퍼에 남아서 엔터가 name으로 출력됨

    printf("Age: %d, name: %s\n", age, name);

    return 0;
}
*/






/*
int main(void)
{
    char str[80] = "apple juice";
    char *ps = "banana";

    puts(str);          //apple juice\n
    fputs(ps, stdout);  //banana 뒤에 줄바꿈 없음
    puts("milk");       //banana 바로 뒤에 출력 

    return 0;
}
*/






/*아래 코드를 알맞게 수정하기 
int main(void)
{
    char ani[20];
    char why[80];

    printf("좋아하는 동물 : ");
    scanf("%s", ani);

    printf("좋아하는 이유 : ");
    fgets(why, sizeof(why), stdin);  //why에 ani 받고 누른 엔터가 자동으로 들어감

    printf("%s is %s", ani, why);   //버퍼에 남아있던 엔터가 why로 출력됨

    return 0;
}
*/





/*
int main(void)
{
    char ani[20];
    char why[80];

    printf("좋아하는 동물 : ");
    scanf("%s", ani);
    getchar();              // 버퍼에 남아있던 엔터 삭제

    printf("좋아하는 이유 : ");
    fgets(why, sizeof(why), stdin);

    printf("%s is %s", ani, why);

    return 0;
}
*/






/*
int main(void)
{
    char str1[80], str2[80];
    char *resp;

    printf("2개의 과일 이름 입력 : ");
    scanf("%s%s", str1, str2);
    if (strlen(str1) > strlen(str2))
        resp = str1;
    else   
        resp = str2;
    printf("이름이 긴 과일은 : %s\n", resp);

    return 0;
}
*/






//strcpy

/*
void copy(char *ps1, char *ps2);

int main(void)
{
    
    char str1[80] = "strawberry";
    char str2[80] = "apple";
    char *ps1 = str1;
    char *ps2 = str2;
    

    printf("최초 문자열 : %s\n", str1);

    copy(ps1, ps2);

    printf("바뀐 문자열 : %s\n", str1);

    return 0;
}

void copy(char *ps1, char *ps2)
{
    int i;

    for(i = 0; i < sizeof(ps2); i++)
    {
        if(*(ps2 + i) == '\0')
        {
            *(ps1 + i) = '\0';
        }
        else
        {
            *(ps1 + i) = *(ps2 + i);
        }
    }
}
*/

//strcat
/*
void strattach(char *ps1, char *ps2, int size1, int size2);

int main(void)
{
    char str1[80] = "straw";
    char str2[80] = "berry";
    char *ps1 = str1;
    char *ps2 = str2;
    int size1 = sizeof(str1);
    int size2 = sizeof(str2);

    strattach(ps1, ps2, size1, size2);

    printf("%s\n", str1);

    return 0;
}

void strattach(char *ps1, char *ps2, int size1, int size2)
{
    int i, j;
    int count=0;

    for(j = 0; j < size1; j++)
    {
        if(*(ps1 + j) != '\0')
        {
            count++;
        }
        else if(*(ps1 + j) == '\0') break;
    }


    for(i = 0; i < size2; i++)
    {
        if((*ps2 + i) != '\0')
        {
            *(ps1 + count + i) = *(ps2 + i);
        }
        else break;
    }
}
*/

//strncat
/*
void strnattach(char *ps1, char *ps2, int size1, int N);

int main(void)
{
    char str1[80] = "straw";
    char str2[80] = "piece";
    char *ps1 = str1;
    char *ps2 = str2;
    int size1 = sizeof(str1);
    int N = 3;

    strnattach(ps1, ps2, size1, N);

    printf("%s\n", str1);

    return 0;
}

void strnattach(char *ps1, char *ps2, int size1, int N)
{
    int i, j;
    int count=0;

    for(j = 0; j < size1; j++)
    {
        if(*(ps1 + j) != '\0')
        {
            count++;
        }
        else if(*(ps1 + j) == '\0') break;
    }


    for(i = 0; i < N; i++)
    {
        if((*ps2 + i) != '\0')
        {
            *(ps1 + count + i) = *(ps2 + i);
        }
        else break;
    }
}
*/


//strlen
/*
int cntlen(int size1, int size2, char *ps1, char *ps2);

int main(void)
{
    char str1[80], str2[80];
    int res;
    int size1 = sizeof(str1);
    int size2 = sizeof(str2);
    char *ps1 = str1;
    char *ps2 = str2;

    printf("2개의 과일 이름 입력 : ");
    scanf("%s%s", str1, str2);

    res = cntlen(size1, size2, ps1, ps2);

    if(res == 1)
    {
        printf("이름이 긴 과일은 : %s\n", str1);
    }
    else if(res == 2)
    {
        printf("이름이 긴 과일은 : %s\n", str2);
    }

    return 0;
}

int cntlen(int size1, int size2, char *ps1, char *ps2)
{
    int i, j, res;
    int count1 = 0;
    int count2 = 0;

    for (i=0; i < size1; i++)
    {
        if (*(ps1 + i) != '\0')
        {
            count1++;
        }
        else if(*(ps1 + i) == '\0')
        break;
    }

    for (j=0; j < size2; j++)
    {
        if (*(ps2 + i) != '\0')
        {
            count2++;
        }
        else if(*(ps2 + i) == '\0')
        break;
    }

    if(count1 > count2)
    {
        res = 1;
    }
    else if (count1 < count2)
    {
        res = 2;
    }

    return res;
}
*/

//strcmp
/*
int strcompare(char *ps1, char *ps2, int size1, int size2);

int main(void)
{
    char str1[80] = "pear";
    char str2[80] = "peach";
    char *ps1 = str1;
    char *ps2 = str2;
    int size1 = sizeof(str1);
    int size2 = sizeof(str2);
    int res;

    res = strcompare(ps1, ps2, size1, size2);

    printf("사전에 나중에 나오는 과일 이름 : ");
    if(res > 0)
    {
        printf("%s\n", str1);
    }
    else
        printf("%s\n", str2);

    return 0;
}

int strcompare(char *ps1, char *ps2, int size1, int size2)
{
    int size, i, res;
    int a, b;

    if(size1 > size2)
    {
        size = size2;
    }
    else if(size1 < size2)
    {
        size = size1;
    }
    else if(size1 == size2)
    {
        size = size1;
    }

    for(i = 0; i < size; i++)
    {
        a = *(int *)ps1 + i;
        b = *(int *)ps2 + i;

        if((a == '\0') || (b == '\0'))
        {
            break;
        }

        if(a > b)
        {
            res = 1;
        }
        else if(a < b)
        {
            res = -1;
        }
    }

    return res;
}
*/



//strncmp
/*
int strncompare(char *ps1, char *ps2);

int main(void)
{
    char str1[80] = "pear";
    char str2[80] = "peach";
    char *ps1 = str1;
    char *ps2 = str2;
    int size1 = sizeof(str1);
    int size2 = sizeof(str2);
    int res;

    res = strncompare(ps1, ps2);
    printf("%d\n", res);

    printf("사전에 나중에 나오는 과일 이름 : ");
    if(res > 0)
    {
        printf("%s\n", str1);
    }
    else
        printf("%s\n", str2);

    return 0;
}

int strncompare(char *ps1, char *ps2)
{
    int size, i, res;
    int a, b;

    for(i = 0; i < 2; i++)
    {
        a = *(int *)ps1 + i;
        b = *(int *)ps2 + i;

        if(a > b)
        {
            res = 1;
        }
        else if(a < b)
        {
            res = -1;
        }
    }

    return res;
}
*/