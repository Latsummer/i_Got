#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

//int fib(int n)
//{
//	int first = 1;
//	int second = 1;
//	int third = 2;
//	for (int i = 1; i <= n; i++)
//	{
//		third = first + second;
//		second = third;
//		first = second;
//	}
//	return third;
//}
//
//int main()
//{
//	int n = 0;
//	cin >> n;
//	int i = 0;
//	while (n--)
//	{
//		cin >> i;
//		printf("%4d", fib(i));
//	}
//}

int main()
{
	string str;
	while (cin >> str)
	{
		int num = 0;
		for (int i = 0; i < str.size(); i++)
			num += (str[i] - '0');
		//stringstream s;
	/*	string snum;
		s << num;
		s >> snum;*/
		string snum = to_string(num);
		while (snum.size() != 1)
		{
			int tmp = 0;
			for (int i = 0; i < snum.size(); i++)
				tmp += (snum[i] - '0');
			snum = to_string(tmp);
		}
		cout << snum << endl;
	}
	return 0;
}