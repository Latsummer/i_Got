#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//int main()
//{
//	int nums[7] = { 1, 2, 3, 4, 5, 6, 7 };
//	int numsSize = 7;
//	int k = 3;
//	while (k)
//	{
//		int tmp = nums[numsSize - 1];
//		for (int i = numsSize - 2; i >= 0; i--)
//		{
//			nums[i + 1] = nums[i];
//		}
//		nums[0] = tmp;
//		k--;
//	}
//	for (int i = 0; i < 7; i++)
//	{
//		printf("%d ", nums[i]);
//	}
//	printf("\n");
//	return 0;
//}

int* addToArrayForm(int* A, int ASize, int K, int* returnSize){
	int numA = 0;
	for (int i = 0; i < ASize; i++)
	{
		numA *= 10;
		numA += A[i];
	}
	K += numA;
	int mal = 0;//此处两个变量计算K的数字个数
	int k_2 = K;
	while (k_2)
	{
		k_2 /= 10;
		mal++;
	}
	returnSize = (int*)malloc(mal * sizeof(int));
	for (int i = mal - 1; i > 0; i--)
	{
		returnSize[i] = K % 10;
	}
	return returnSize;

}

int main()
{
	int A[4] = { 1, 2, 0, 0 };
	int K = 34;
	return 0;
}