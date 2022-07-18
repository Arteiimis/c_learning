#include <stdio.h>
#include <math.h>

int main()
{
    double sum = 0;
    int i = 0, sign = 1;

    for (i = 0; (1.0 / (2 * i + 1)) > 1e-6; i++)
    {
        sum += sign * 1.0 / (2 * i + 1);
        sign *= -1;
    }

    printf("%.4lf\n", sum * 4.0);

    return 0;
}