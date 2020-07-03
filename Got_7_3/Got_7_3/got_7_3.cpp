#include <iostream>
#include <string>
#include <vector>
using namespace std;

//int main()
//{
//	int nums[4] = { 0 };
//	int A, B, C;
//	A = B = C = 0;
//	for (int i = 0; i < 4; i++)
//	{
//		cin >> nums[i];
//	}
//	A = nums[0] + nums[2];
//	B = nums[1] + nums[3];
//	C = nums[3] - B;
//	cout << A << " " << B << " " << C << endl;
//	return 0;
//}
//int main()
//{
//	int nums[4] = { 0 };
//	int A, B, C;
//	A = B = C = 0;
//	for (int i = 0; i < 4; i++)
//	{
//		cin >> nums[i];
//	}
//	A = (nums[0] + nums[2]) / 2;
//	B = (nums[1] + nums[3]) / 2;
//	C = nums[3] - B;
//	if ((A - B) == nums[0] && (B - C) == nums[1]
//		&& (A + B) == nums[2] && (B + C) == nums[3]) {
//		cout << A << " " << B << " " << C << endl;
//	}
//	else {
//		cout << "No" << endl;
//	}
//	return 0;
//}

//void fun(int& M, int& N, vector<char>& arr)
//{
//	while (M != 0)
//	{
//		int step = M % N;
//		char c = 0;
//		if (step >= 10)
//			c = step - 10 + 'A';
//		else
//			c = step + '0';
//		arr.push_back(c);
//		M /= N;
//	}
//}
//
//int main()
//{
//	int M, N;
//	string s;
//	vector<char> arr;
//	cin >> M >> N;
//	if (M < 0)
//	{
//		M = -M;
//		cout << "-";
//	}
//	fun(M, N, arr);
//	for (int i = arr.size() - 1; i >= 0; i--)
//		s += arr[i];
//	cout << s << endl;
//	return 0;
//}

int main()
{
	string ret = "", Hash = "0123456789ABCDEF";
	int M, N;
	cin >> M >> N;
	if (M == 0)
		cout << M << endl;
	while (M)
	{
		if (M < 0) {
			M = -M;
			cout << "-";
		}
		ret = Hash[M % N] + ret;
		M /= N;
	}
	cout << ret << endl;
}