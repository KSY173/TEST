#include <stdio.h>

int main(void){

    double I_load, vel, R, V, C, eta;

    printf("평균 전류 I_load [A] (부하측):");
    if (scanf("%lf", &I_load)!=1) return 1;
    printf("평균 속도 vel [km/h]:");
    scanf("%lf", &vel);
    printf("예비율 R (0~1) :");
    scanf("%lf", &R);
    printf("공칭 전압 V [V]:");
    scanf("%lf", &V);
    printf("용량 C [Ah]:");
    scanf("%lf", &C);
    printf("시스템 효율 eta (0~1) :");
    scanf("%lf", &eta);

    if (V<=0 || C<=0 ||I_load<=0 || vel<0 || R<0 || R>=0 || eta<=0 || eta>100){
        printf("입력값 범위를 확인하세요\n");
        return 1;
    }
    
    const double E_usable = V * C * eta * (1-R);
    const double P = (V * I_load)/eta * 2;
    const double t = E_usable/P;
    const double d = vel * t;

    printf("사용 가능 에너지: %.2lf[Wh]\n", E_usable);
    printf("소비 전력: %.2lf[W]\n", P);
    printf("런타임: %.2lf[h]\n", t);
    printf("주행 거리: %.2lf[km]\n", d);

    return 0;
}