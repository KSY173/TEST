#include <stdio.h>

int main(void)
{
    int i, range;
    int select;
    int arr[20];

    while(!0)
    {
        printf("select = ");
        scanf("%d", &select);

        if(select==1)
        {
            printf("numbers : ");
            scanf("%d", &range);

            printf("Enter numbers: ");
            for(i-0; i<range; i++)
            {
                scanf("%d", (arr+i));
            }
            for(i = range -1; i>=0; i--)
            {
                printf("%d", *(arr+i));
            }
            printf("\n");
        }
        else{
            break;
        }
    }

    return 0;
}