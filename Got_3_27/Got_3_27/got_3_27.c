#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//int A1(int* p, int size)
//{
//	int sum = 0;
//	for (int i = 0; i < size; i++)
//	{
//		if (p[i] % 5 == 0)
//		{
//			if (p[i] % 2 == 0)
//			{
//				sum += p[i];
//			}
//		}
//	}
//	return sum;
//}
//
//int A2(int* p, int size)
//{
//	int sum = 0;
//	int n = 1;
//	for (int i = 0; i < size; i++)
//	{
//		if (p[i] % 5 == 1)
//		{
//			if (n % 2 == 0)
//				sum -= p[i];
//			else
//				sum += p[i];
//			n++;
//		}
//	}
//	return sum;
//}
//
//int A3(int* p, int size)
//{
//	int num = 0;
//	for (int i = 0; i < size; i++)
//	{
//		if (p[i] % 5 == 2)
//			num++;
//	}
//	return num;
//}
//
//float A4(int* p, int size)
//{
//	float n = 0;
//	float sum = 0.0;
//	for (int i = 0; i < size; i++)
//	{
//		if (p[i] % 5 == 3)
//		{
//			sum += (float)p[i];
//			n++;
//		}
//	}
//	if (sum  < 0.001 && sum > -0.001)
//		return 0;
//	return (sum / n);
//}
//
//int A5(int* p, int size)
//{
//	int max = 0;
//	for (int i = 0; i < size; i++)
//	{
//		if (p[i] % 5 == 4)
//		{
//			if (p[i] > max)
//				max = p[i];
//		}
//	}
//	return max;
//}
//
//int main()
//{
//	int size = 0;
//	scanf("%d", &size);
//	int* p = (int*)malloc(4 * size);
//	for (int i = 0; i < size; i++)
//		scanf("%d", &p[i]);
//	int a1 = A1(p, size);
//	int a2 = A2(p, size);
//	int a3 = A3(p, size);
//	float a4 = A4(p, size);
//	int a5 = A5(p, size);
//	free(p);
//	if (a1 == 0)
//		printf("N ");
//	else
//		printf("%d ", a1);
//	if (a2 == 0)
//		printf("N ");
//	else
//		printf("%d ", a2);
//	if (a3 == 0)
//		printf("N ");
//	else
//		printf("%d ", a3);
//	if (a4 == 0)
//		printf("N ");
//	else
//		printf("%.1f ", a4);
//	if (a5 == 0)
//		printf("N ");
//	else
//		printf("%d ", a5);
//	return 0;
//}

int num(int n)
{
	int alone = n;
	for (int i = 2; i < (int)(sqrt(n) + 1); i++)
	{
		if (n%i == 0)
		{
			return 0;
		}
	}
	return alone;
	/*int num = 0;
	for (int i = 2; i < n; i++)
	{
		if (n % i == 0)
			num++;
	}
	if (num == *//*0)
		return n;
	else
	{
		return 0;
	}*/
}

void git_p(int* p, int right)
{
	int full = 0;
	while (1)
	{
		for (int i = 1; ; i++)
		{
			int n = num(i);
			if (n != 0)
			{
				if (full > right)
					return;
				p[full++] = n;
			}
		}
	}
}

int main()
{
	int left = 0;
	int right = 0;
	scanf("%d", &left);
	scanf("%d", &right);

	int* p = (int*)malloc((right + 1)*sizeof(int));

	git_p(p, right);

	while (left < right)
	{
		for (int i = 0; i < 10; i++)
		{
			if (left >= right)
				break;
			printf("%d ", p[left]);
			left++;
		}
		if (left >= right)
			break;
		printf("\n");
	}
	if (right % 10 == 0)
		printf("\n");
	printf("%d", p[right]);

	//for (int i = left; i <= right; i++)
		//printf("%d ", p[i]);
	return 0;
}