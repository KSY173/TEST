#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *fp;
    int ch, i;
    int count = 1;
    int error = 0;
    int error_s = 0;
    int error_m = 0;
    
    fp = fopen("log.txt", "r");

    if (fp == NULL)
    {
        printf("파일을 열지 못했습니다.\n");
        return 1;
    }
    
    while(1)
    {
        ch = fgetc(fp);
        if(ch == EOF)
        {
            break;
        }
        else
        {
            count++;
        }
    }

    rewind(fp);

    char str[count+1];

    for(i = 0; i < count; i++)
    {
        str[i] = fgetc(fp);

        if(str[i] == EOF)
        {
            str[i] = '\0';
            break;
        }
    } 

    char *p = str;
    while((p = strstr(p, "ERROR")) != NULL)
    {
        error++;
        p += 5;
    }

    printf("ERROR: %d\n", error);
    printf("Sensor failed: %d\n", error_s);
    printf("Motor overload: %d\n", error_m);

    fclose(fp);

    return 0;
}
