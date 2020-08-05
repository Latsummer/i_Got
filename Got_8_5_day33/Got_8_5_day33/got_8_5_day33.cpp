#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		int len1 = s1.size();
		int len2 = s2.size();
		if (len2 > len1)
			cout << 0 << endl;
		else
		{
			int ret = 0;
			for (int i = len1 - len2; i >= 0; )
			{
				string tmp;
				tmp = s1.substr(i, len2);
				if (tmp == s2)
				{
					ret++;
					i -= len2;
				}
				else
					i--;
			}
			cout << ret << endl;
		}
	}
}

// write your code here cpp
#include <iostream>
#include <vector>
using namespace std;

void Fib(vector<long long int>& arr)
{
	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 1;
	for (int i = 3; i < 81; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
	}
}

int main()
{
	int a, b;
	vector<long long int> arr(81, 0);
	Fib(arr);
	while (cin >> a >> b)
	{
		long long int ret = 0;
		for (int i = a; i <= b; i++)
			ret += arr[i];
		cout << ret << endl;
	}
}