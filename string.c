#include <stdio.h>
#include <stdlib.h>

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