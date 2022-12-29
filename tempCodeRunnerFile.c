void DispHCode(HTNode ht[], HCode hcd[], int n)
{
	int i, k;
	char codes[N];

	printf("输出哈夫曼编码：\n");
	for (i = 0; i < n; i++)
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

	printf("\nHuffman codes:\n");
	for (i = 0; i < n; i++)
		printf("%s: %s\n", ht[i].data, codes);

	printf("\n");
}