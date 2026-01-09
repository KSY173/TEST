#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
//구조체 선언 후 마지막 중괄호 뒤에 ; 붙이기
struct student
{
    int num;
    double grade;
};

int main(void)
{
    struct student s1;

    s1.num = 2;
    s1.grade = 2.7;
    printf("학번 : %d\n", s1.num);
    printf("학점 : %.1lf\n", s1.grade);

    return 0;
}
*/








/*
struct student
{
    char ch1;
    short num;
    char ch2;
    char ch3;
    int score;
    double grade;
    
};

int main(void)
{
    struct student s1;
    
    char *pc = &s1.ch1;

    printf("%c\n", *pc + 1);

    printf("%d", sizeof(s1));           //맨 밑에 char ch3를 넣으면 32바이트, ch2 밑에 넣으면 24바이트

    return 0;
}
*/









/*
struct profile 
{
    char name[20];
    int age;
    double height;
    char *intro;
};

int main(void)
{
    struct profile yuni;
    strcpy(yuni.name, "서하윤");
    yuni.age = 17;
    yuni.height = 164.5;

    int N = 80;

    yuni.intro = (char *)malloc(N);
    printf("자기소개 (%d글자 이내로 입력) : ", N/2);        //영어는 1byte, 한글은 2byte
    fgets(yuni.intro, N, stdin);

    printf("이름 : %s\n", yuni.name);
    printf("나이 : %d\n", yuni.age);
    printf("키 : %.1lf\n", yuni.height);
    printf("자기소개 : %s\n", yuni.intro);

    free(yuni.intro);

    return 0;
}
*/











/*
//구조체 안에서 다른 구조체 사용
struct profile
{
    int age;
    double height;
};

struct student
{
    struct profile pf;
    int id;
    double grade;
};

int main(void)
{
    struct student yuni;

    yuni.pf.age = 17;
    yuni.pf.height = 164.5;
    yuni.id = 315;
    yuni.grade = 4.3;

    printf("나이 : %d\n", yuni.pf.age);
    printf("키 : %.1lf\n", yuni.pf.height);
    printf("학번 : %d\n", yuni.id);
    printf("학점 : %.1lf\n", yuni.grade);

    return 0;    
}
*/













/*
struct vision
{
    double left;
    double right;
};

struct vision exchange (struct vision robot);               //구조체를 반환하고 구조체를 매개변수로 가짐

int main(void)
{
    struct vision robot;

    printf("시력 입력 :");
    scanf("%lf%lf", &(robot.left), &(robot.right));
    robot = exchange(robot);
    printf("바뀐 시력 : %.1lf  %.1lf\n", robot.left, robot.right);

    return 0;
}

struct vision exchange(struct vision robot)
{
    double temp;

    temp = robot.left;
    robot.left = robot.right;
    robot.right = temp;

    return robot;
}
*/











/*
//교재 문제
struct profile
{
    int num;
    char name[20];
    char *skill;
};

struct sports
{
    char *event;
    struct profile player;
};

struct sports a;

strcpy(a.event, "figure skating");          //
a.player.name = "Yuni Seo";                 // strcpy(name, "Yuni Seo"); name은 주소 상수
a.num = 19;                                 // a.player.num = 19;
scanf("%s", a.player.skill);                //
*/













/*
struct score
{
    int kor;
    int eng;
};

int main(void)
{
    struct score yuni = {90, 80};
    struct score *ps = &yuni;

    printf("%d\n", (*ps).kor);      //ps -> kor랑 같은 표현
    printf("%d\n", ps -> eng);      //포인터 화살표로 사용 가능, 이걸 더 많이 씀

    return 0;
}
*/











/*
struct list
{
    int num;
    struct list *next;
};

int main(void)
{
    struct list a = {10, 0}, b = {20, 0}, c = {30, 0};      //포인터 주소 next는 NULL로 초기화
    struct list *head = &a, *current;

    a.next = &b;
    b.next = &c;

    printf("head->num : %d\n", head->num);
    printf("head->next->num : %d\n", head->next->num);

    printf("list all : ");
    current = head;
    while (current != NULL)
    {
        printf("%d ", current->num);
        current = current->next;
    }
    printf("\n");

    return 0;
}
*/









/*
//공용체 union은 크기가 더 큰 바이트를 기준으로 공용으로 사용함 여기선 8바이트 사용
union student
{
    int num;
    double grade;
};

int main(void)
{
    union student s1 = {315};

    printf("학번 : %d\n", s1.num);          
    s1.grade = 4.4;                             //num 저장했던 거 지우고 grade 입력
    printf("학점 : %.1lf\n", s1.grade);         
    printf("학번 : %d\n", s1.num);

    return 0;
}
*/













/*
//열거형 enum
enum season {SPRING, SUMMER, FALL, WINTER};

int main(void)
{
    enum season ss;
    char *pc = NULL;

    ss = SPRING;

    switch (ss)
    {
        case SPRING:
            pc = "inline"; break;
        case SUMMER:
            pc = "swimming"; break;
        case FALL:
            pc = "trip"; break;
        case WINTER:
            pc = "skiing"; break;
    }
    printf("%s\n", pc);

    return 0;
}
*/










/*
// 구조체 재정의 하는 법, 실제로는 이렇게 안 씀
struct student
{
    int num;
    double grade;
};
typedef struct student Student;
void print_data(Student *ps);

int main(void)
{
    Student s1 = {315, 4.2};

    print_data(&s1);

    return 0;
}

void print_data(Student *ps)
{
    printf("학번 : %d\n", ps->num);
    printf("학점 : %.1lf\n", ps->grade);
}
*/









/*
//실제로 구조체 정의하는 법
typedef struct{
    int num;
    double grade;
}Student;

void print_data(Student *ps);

int main(void)
{
    Student s1 = {315, 4.2};

    print_data(&s1);

    return 0;
}

void print_data(Student *ps)
{
    printf("학번 : %d\n", ps->num);
    printf("학점 : %.1lf\n", ps->grade);
}
*/


/*
void bubble_sort(int list[], int n)
{
    int i, j, temp;

    for(i = n-1; i>0; i--)
    {
        for (j = 0; j<i; j++)
        {
            if(list[j]<list[j+1])
            {
                temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
            }
        }
    }
}
*/









/*
typedef struct{
    int num;
    char name[80];
    int grade[3];
}student;

int main(void)
{
    int i, j;
    int N = 5;
    int sum[5];
    double avg[N];
    char g[5];
    int max_avg[N];

    student list[5];


    for(i = 0; i < N; i++)
    {
        printf("학번 : ");
        scanf("%d", &list[i].num);
        printf("이름 : ");
        scanf("%s", list[i].name);
        printf("국어, 영어, 수학 점수 : ");
        for(j = 0; j < 3; j++)
        {
            scanf("%d", &list[i].grade[j]);
        }
    }

    for(i = 0; i < N; i++)
    {
        sum[i] = 0;

        for(j = 0; j < 3; j++)
        {
            sum[i] += list[i].grade[j];
        }

        avg[i] = sum[i]/3;
        max_avg[i] = sum[i]/3;

        if(avg[i] >= 90)
        {
            g[i] = 'A';
        }
        else if(avg[i] >= 80)
        {
            g[i] = 'B';
        }
        else if(avg[i] >= 70)
        {
            g[i] = 'C';
        }
        else
        {
            g[i] = 'F';
        }
    }    
    
    printf("# 정렬 전 데이터...\n");
    for(i = 0; i < N; i++)
    {
        printf("%d %s %d %d %d %d %.1lf    %c\n", list[i].num, list[i].name, list[i].grade[0], list[i].grade[1], list[i].grade[2], sum[i], avg[i], g[i]);

    }

    int temp, temp1, temp2, temp5, temp6, temp7;
    char temp3;
    char temp4[80];

    for(i = N-1; i > 0; i--)
    {
        for(j=0; j<i; j++)
        {
            if(max_avg[j] < max_avg[j+1])
            {
                temp = max_avg[j];
                max_avg[j] = max_avg[j+1];
                max_avg[j+1] = temp;

                temp1 = list[j].num;
                list[j].num = list[j+1].num;
                list[j+1].num = temp1;

                temp2 = sum[j];
                sum[j] = sum[j+1];
                sum[j+1] = temp2;

                temp3 = g[j];
                g[j] = g[j+1];
                g[j+1] = temp3;

                strcpy(temp4, list[j].name);
                strcpy(list[j].name, list[j+1].name);
                strcpy(list[j+1].name, temp4);

                temp5 = list[j].grade[0];
                list[j].grade[0] = list[j+1].grade[0];
                list[j+1].grade[0] = temp5;

                temp6 = list[j].grade[1];
                list[j].grade[1] = list[j+1].grade[1];
                list[j+1].grade[1] = temp6;

                temp7 = list[j].grade[2];
                list[j].grade[2] = list[j+1].grade[2];
                list[j+1].grade[2] = temp7;
            }
        }
    }

    printf("# 정렬 후 데이터...\n");
    for(i = 0; i < N; i++)
    {
        printf("%d %s %d %d %d %d %d    %c\n", list[i].num, list[i].name, list[i].grade[0], list[i].grade[1], list[i].grade[2], sum[i], max_avg[i], g[i]);
    }
        

    return 0;
}
*/











/*
typedef struct{
    int x;
    int y;
}Position;

void move(Position *p, int dx, int dy);

int main(void)
{
    int dx, dy, i;

    Position pos = {0, 0};

    for(i = 0; i < 2; i++)
    {
        printf("x좌표 이동하는 dx : ");
        scanf("%d", &dx);
        printf("y좌표 이동하는 dy : ");
        scanf("%d", &dy);

        move(&pos, dx, dy);
    }
    

    printf("최종 위치 : (%d, %d)", pos.x, pos.y);
    
    return 0;
}

void move(Position *p, int dx, int dy)
{
    p->x += dx;
    p->y += dy;
}
*/












typedef struct{
    double left;
    double right;    
}WheelSpeed;

typedef struct{
    double linear;
    double angular;
}RobotSpeed;