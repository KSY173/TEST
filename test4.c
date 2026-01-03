#include <stdio.h>

int main(void) {
    
    int N, i;
    double battery[100];
    int warning = 0;  // 0: OFF, 1: ON

    printf("배터리로그개수입력: ");
    scanf("%d", &N);
    printf("배터리잔량입력(%% 단위)\n");

    for (i = 0; i < N; i++) 
    {
        printf("%d번째잔량: ", i + 1);
        scanf("%lf", &battery[i]);
    }

    printf("\n[배터리히스테리시스경보결과]\n");
    for (i = 0; i < N; i++) 
    {
        if (warning == 0 && battery[i] <= 30.0) 
        {
            warning = 1; // 경고ON
        } 
        else if (warning == 1 && battery[i] >= 35.0) 
        {
            warning = 0; // 경고OFF
        }   
        printf("%2d번째→ 잔량: %5.1f%%  |  경고상태: %s\n", i + 1, battery[i], (warning == 1) ? "ON" : "OFF");
    }
    
    return 0;
}
