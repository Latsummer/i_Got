#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

//int main()
//{
//	//int x = 1;
//	//do {
//	//	printf("%2d\n", x++);
//	//} while (x--);
//	string s1;
//	string s2;
//	cin >> s1 >> s2;
//	cout << s1.size() << endl;
//	return 0;
//}


//bool is_huiwen(const string& s)
//{
//	int begin = 0;
//	int end = s.size() - 1;
//	while (end > begin)
//	{
//		if (s[begin] == s[end])
//		{
//			begin++;
//			end--;
//		}
//		else
//			return false;
//	}
//	return true;
//}
//
//int main()
//{
//	string s1;
//	string s2;
//	cin >> s1 >> s2;
//	int count = 0;
//
//	for (int i = 0; i <= s1.size(); i++)
//	{
//		string tmp = s1;
//		tmp.insert(i, s2);
//		if (is_huiwen(tmp))
//			count++;
//	}
//	cout << count << endl;
//	return 0;
//}

int GetMax(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int n = 0;
	vector<int> arr;
	cin >> n;
	arr.resize(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int Max = arr[0];
	int sum = Max;
	for (int i = 1; i < arr.size(); i++)
	{
		sum = GetMax(sum + arr[i], arr[i]);

		if (sum >= Max)
			Max = sum;
	}
	cout << Max << endl;
	return 0;
}
