// write your code here cpp
#include <iostream>
#include <string>
#include <map>
using namespace std;

//int main()
//{
//	string mi("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
//	string yu("VWXYZABCDEFGHIJKLMNOPQRSTU");
//	map<char, char> m;
//	for (int i = 0; i < mi.size(); i++)
//		m[mi[i]] = yu[i];
//	string str;
//	getline(cin, str);
//	string ret;
//	for (auto ch : str)
//	{
//		if (ch == ' ')
//		{
//			ret += ch;
//			continue;
//		}
//		else
//		{
//			ret += m[ch];
//		}
//	}
//	cout << ret << endl;
//	return 0;
//}



#include <math.h>


int main()
{
	int num = 0;
	while (cin >> num)
	{
		int count = 0;
		int tmp = sqrt(num);
		for (int i = 2; i <= tmp && num != 1; i++)
		{
			if (num % i == 0)
			{
				count++;
				while (num % i == 0)
					num /= i;
			}
		}
		int ret = num > 1 ? count + 1 : count;
		cout << ret << endl;
	}
}