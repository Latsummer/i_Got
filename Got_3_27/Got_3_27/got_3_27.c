#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int A1(int* p, int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		if (p[i] % 5 == 0)
		{
			if (p[i] % 2 == 0)
			{
				sum += p[i];
			}
		}
	}
	return sum;
}

int A2(int* p, int size)
{
	int sum = 0;
	int n = 1;
	for (int i = 0; i < size; i++)
	{
		if (p[i] % 5 == 1)
		{
			if (n % 2 == 0)
				sum -= p[i];
			else
				sum += p[i];
			n++;
		}
	}
	return sum;
}

int A3(int* p, int size)
{
	int num = 0;
	for (int i = 0; i < size; i++)
	{
		if (p[i] % 5 == 2)
			num++;
	}
	return num;
}

float A4(int* p, int size)
{
	float n = 0;
	float sum = 0.0;
	for (int i = 0; i < size; i++)
	{
		if (p[i] % 5 == 3)
		{
			sum += (float)p[i];
			n++;
		}
	}
	if (sum  < 0.001 && sum > -0.001)
		return 0;
	return (sum / n);
}

int A5(int* p, int size)
{
	int max = 0;
	for (int i = 0; i < size; i++)
	{
		if (p[i] % 5 == 4)
		{
			if (p[i] > max)
				max = p[i];
		}
	}
	return max;
}

int main()
{
	int size = 0;
	scanf("%d", &size);
	int* p = (int*)malloc(4 * size);
	for (int i = 0; i < size; i++)
		scanf("%d", &p[i]);
	int a1 = A1(p, size);
	int a2 = A2(p, size);
	int a3 = A3(p, size);
	float a4 = A4(p, size);
	int a5 = A5(p, size);
	free(p);
	if (a1 == 0)
		printf("N ");
	else
		printf("%d ", a1);
	if (a2 == 0)
		printf("N ");
	else
		printf("%d ", a2);
	if (a3 == 0)
		printf("N ");
	else
		printf("%d ", a3);
	if (a4 == 0)
		printf("N ");
	else
		printf("%.1f ", a4);
	if (a5 == 0)
		printf("N ");
	else
		printf("%d ", a5);
	return 0;
}