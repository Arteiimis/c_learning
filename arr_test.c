#include <stdio.h>
#include <string.h>

#define N 50
#define M 2 * N - 1

typedef struct
{
	char data[5];
	int weight;
	int parent;
	int lchild;
	int rchild;
} HTNode;

typedef struct
{
	char cd[N];
	int start;
} HCode;

void CreatHT(HTNode ht[], int n)
{
	int i, k, lnode, rnode;
	int min1, min2;

	for (i = 0; i < 2 * n - 1; i++)
		ht[i].parent = ht[i].lchild = ht[i].rchild = 0;

	for (i = n; i < 2 * n - 1; i++)
	{
		min1 = min2 = 32767;
		lnode = rnode = 0;
		for (k = 0; k <= i - 1; k++)
		{
			if (ht[k].parent == 0)
			{
				if (ht[k].weight < min1)
				{
					min2 = min1;
					rnode = lnode;
					min1 = ht[k].weight;
					lnode = k;
				}
				else if (ht[k].weight < min2)
				{
					min2 = ht[k].weight;
					rnode = k;
				}
			}
		}

		ht[lnode].parent = i;
		ht[rnode].parent = i;
		ht[i].weight = ht[lnode].weight + ht[rnode].weight;
		ht[i].lchild = lnode;
		ht[i].rchild = rnode;
	}
}

void CreatHCode(HTNode ht[], HCode hcd[], int n)
{
	int i, f, c;
	HCode hc;

	for (i = 0; i < n; i++)
	{
		hc.start = n;
		c = i;
		f = ht[i].parent;
		while (f != 0)
		{
			if (ht[f].lchild == c)
				hc.cd[hc.start--] = '0';
			else
				hc.cd[hc.start--] = '1';
			c = f;
			f = ht[f].parent;
		}
		hc.start++;
		hcd[i] = hc;
	}
}

//逆序输出编码
void DispHCode(HTNode ht[], HCode hcd[], int n)
{
	int k;
	char codes[N];

	printf("输出哈夫曼编码：\n");
	for (int i = n - 1; i >= 0; i--)
	{
		strcpy(codes, ""); // reset the codes array
		printf("    %s:\t", ht[i].data);
		for (k = hcd[i].start; k <= n; k++)
		{
			codes[k - hcd[i].start] = hcd[i].cd[k];
			printf("%c", hcd[i].cd[k]);
		}
		printf("\n");
	}
}


int main()
{
	int n = 8;
	char *str[] = {"a", "b", "c", "d", "e", "f", "g", "h"};
	int fnum[] = {7, 19, 2, 6, 32, 3, 21, 10};
	HTNode ht[M];
	HCode hcd[N];

	for (int i = 0; i < n; i++)
	{
		strcpy(ht[i].data, str[i]);
		ht[i].weight = fnum[i];
	}

	printf("\n");
	CreatHT(ht, n);
	CreatHCode(ht, hcd, n);
	DispHCode(ht, hcd, n);
	printf("\n");

	return 0;
}
