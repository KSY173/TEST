#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *fp;
    int ch, i, j;
    int size = 0;
    int ping = 0;
    int ping6 = 0;
    int ping4 = 0;
    int col = 0;

    fp = fopen("fast.log.txt", "r");
    if (fp == NULL)
    {
        printf("파일이 열리지 않았습니다.\n");
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
            size++;
        }
    }

    rewind(fp);

    char str[size+1];

    for(i = 0; i < size; i++)
    {
        str[i] = fgetc(fp);

        if(str[i] == EOF)
        {
            str[i] = '\0';
            break;
        }
        else if (str[i] == '\n')
        {
            ping++;
        }
    }

    char *p6 = str;
    while((p6 = strstr(p6, "IPv6-ICMP")) != NULL)
    {
        ping6++;
        p6 += 9;
    }

    ping4 = (ping - ping6)/2;

    char address[ping][40];
    
    for(i = 0; i < size; i++)
    {
        if(str[i] == '}')
        {
            if(str[i+2] != 'f')
            {
                for(j = 0; j < 36; j++)
                {
                    address[col][j] = str[i+2+j];
                }
                address[col][j] = '\0';
                col++;
            }
            else
            {
                for(j = 0; j < 39; j++)
                {
                    address[col][j] = str[i+2+j];
                }
                address[col][j] = '\0';
                col++;
            }
        }
    }

    int max_count = 0;
    int max = 0;

    for(i = 0; i < col; i++)
    {
        int count = 1;

        for(j = 0; j < col; j++)
        {
            if (strcmp(address[max], address[j]) == 0)
            {
                ++count;
            }          
        }
        if(count > max_count)
        {
            max_count = count;
            max = i;
        }
    }

    char time[col][3];
    
    for(i = 0; i < col; i++)
    {
        for(j = 0; j < 40; j++)
        {
            if(address[i][j] == '-')
            {
                time[i][0] = address[i][j+1];
                time[i][1] = address[i][j+2];
                time[i][2] = '\0';
            }
            else if (address[i][j] == '\0')
            {
                continue;
            }
        }
    }

    for(i = 0; i < col; i++)
    {
        int time_count = 1;

        for(j = i+1; j < col; j++)
        {
            while(time[i] == time[j])
            {
                
            }
        }
    }
    
    printf("max index : %d\n", max);
    printf("max address: %s\n", address[max]);

    printf("총 ping 요청 횟수: %d\n", ping6 +ping4);
    printf("가장 많은 Ping을 요청한 주소 : %s\n", address[max]);

    fclose(fp);

    return 0;
}