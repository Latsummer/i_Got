#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n = 0;
	while (cin >> n) {
		int count = 0;
		while (n)
		{
			if (n & 1)
				count++;
			n = n >> 1;
		}
		cout << count << endl;
	}
	return 0;
}

int getMin(int a, int b)
{
	return a < b ? a : b;
}
int findMinimum(int n, vector<int> left, vector<int> right) {
	// write code here
	int sum = 0, leftSum = 0, rightSum = 0;
	int leftMin = 26, rightMin = 26;
	for (int i = 0; i < n; i++)
	{
		if (left[i] * right[i] == 0)
		{
			sum += left[i];
			sum += right[i];
		}
		else
		{
			leftSum += left[i];
			rightSum += right[i];

			leftMin = getMin(leftMin, left[i]);
			rightMin = getMin(rightMin, right[i]);
		}
	}
	sum += getMin((leftSum - leftMin + 1), (rightSum - rightMin + 1)) + 1;
	return sum;
}