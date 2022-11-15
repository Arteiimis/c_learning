#include <stdio.h>
#include <math.h>

int scape(int x, int L)
{
	int sum1;
	if (L == 1)
	{
		sum1 = x * (x + 1) / 2;
	}
	else if (L == 2)
	{
		if (x >= 1 && x <= 2)
		{
			sum1 = x;
		}
		else if (x == 3)
		{
			sum1 = x + 1;
		}
		else
		{
			sum1 = 6;
		}
	}
	return sum1;
}

int main()
{
	int x, t, y, f, L, sum, a, b, cnt = 0, t1, t2, sum2, sum3, binggo = 0;
	scanf("%d %d", &x, &L);

	f = x / 2;
	t = x;
	do
	{
		if (f % 2 == 1)
		{
			binggo = 1;
		}
		if (x % 2 == 1)
		{
			a = x / 2;
			b = a + 1;
		}
		else
		{
			a = x / 2;
			b = a;
		}
		x /= 2;
		cnt++;

	} while (x > 4);
	int total = pow(2, cnt);
	printf("cnt=%d,total=%d\n", cnt, total);
	if (binggo == 1)
	{
		sum2 = 2;
	}
	else
	{
		sum2 = total / 2;
	}

	sum3 = total - sum2;
	printf("a=%d,b=%d", a, b);
	sum = cnt * t;
	printf("sum=%d,sum2=%d,sum3=%d\n", sum, sum2, sum3);
	t1 = scape(a, L);
	t2 = scape(b, L);
	printf("t1=%d,t2=%d\n", t1, t2);
	sum = t1 * sum2 + t2 * sum3 + sum;
	printf("药片污染的最小次数为%d", sum);
	return 0;
}
