#include <stdio.h>

int main(void){

    int i=1;
    int j=1;

    for(i=1;i<6;i++)
    {
        for(j=1;j<6;j++)
        {
            if (i==j || (i+j)==6){
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}