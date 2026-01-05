#include <stdio.h>

//함수 만들기 예제
const double pi = 3.141592;

double conv_deg_to_rad(double x)
{
    double radian;

    radian = x * pi / 180;

    return radian;
}

double conv_rad_to_deg(double y)
{
    double degree;

    degree = y * 180 / pi;

    return degree;

}

int main(void)
{
    int num, a;

    printf("1. degree -> radian, 2. radian -> degree");
    scanf("%d", &num);
    printf("Type the number:");
    scanf("%d", &a);

    if(num == 1)
    {
        double result;
        result = conv_deg_to_rad(a);
        printf("result = %.2lf", result);
    }
    else
    {
        double result;
        result = conv_rad_to_deg(a);
        printf("result = %.2lf", result);
    }

    return 0;
}