#include <iostream>
using namespace std;

int Add(int num1, int num2)
{
	if (num1 == 0)
		return num2;
	if (num2 == 0)
		return num1;
	int sum = 0;
	int step = 0;
	while (num2 != 0)
	{
		sum = num1 ^ num2;
		step = (num1 & num2) << 1;

		num1 = sum;
		num2 = step;
	}
	return sum;
}

int main()
{
	double a, b, c;
	while (cin >> a >> b >> c)
	{
		if (a + b > c && a + c > b && b + c > a)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}