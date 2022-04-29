#include<stdio.h>
#include<math.h>

int main()
{
    float a,b,c;
    float area,temp_area;
    float s;

    scanf("%f,%f,%f",&a, &b, &c);
    s = (a+b+c)/2;
    temp_area = s * (s-a) * (s-b) * (s-c);
    area = sqrt(temp_area);
    printf("三角形面积：%.0f\n",area);
    return 0;
} 