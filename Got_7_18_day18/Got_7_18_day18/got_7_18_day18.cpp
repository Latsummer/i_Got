#include <iostream>
#include <stack>
#include <string>
using namespace std;

/*int main()
{
	int month = 0;
	while(cin >> month){
	int i = 0;
	long x = 1;
	long y = 1;
	long sum = 1;
	if(month > 2)
	{
		for(int i = 3; i <= month; i++)
		{
			sum = x + y;
			x = y;
			y = sum;
		}
	}
	cout << sum << endl;}
	return 0;
}*/

//int sum(int month)
//{
//	if (month == 0)
//		return 0;
//	if (month == 1 || month == 2)
//		return 1;
//	else
//		return sum(month - 1) + sum(month - 2);
//}
//
//int main()
//{
//	int month;
//	while (cin >> month)
//	{
//		cout << sum(month) << endl;
//	}
//	return 0;
//}


bool isnumOrstr(char a)
{
	if (a >= '0' && a <= '9')
		return true;
	if (a >= 'A' && a <= 'Z')
		return true;
	if (a >= 'a' && a <= 'z')
		return true;
	return false;
}

/*bool fun(string& pei, string& str)
{
	int pei_idx = 0;
	int str_idx = 0;

	while(pei[pei_idx] == str[str_idx])//去掉前边的相同部分
	{
		pei_idx++;
		str_idx++;
	}

	if(isnumOrstr(pei[pei_idx]))//第一个相同部分不是* ｜｜ ？ 匹配不成功
		return false;

	while(pei_idx < pei.size() || str_idx < str.size())
	{
		if(pei[pei_idx] == '?')
		{
			if(isnumOrstr(str[str_idx]))
			{
				if(pei_idx < pei.size())
					pei_idx++;
				if(str_idx < str.size())
					str_idx++;
				if(pei_idx == pei.size() && str_idx < str.size())//最后一个为？的情况
					return false;
			}
		}
		else if(pei[pei_idx] == '*')
		{
			pei_idx++;
			while(str_idx < str.size() && str[str_idx] != pei[pei_idx])
				str_idx++;
			if(str_idx == str.size() && pei_idx != pei.size())
				return false;
		}
	}
	return true;
}*/

bool fun(stack<char>& pei, stack<char>& str)
{
	while (!pei.empty() && !str.empty() && pei.top() != str.top())
	{
		pei.pop();
		str.pop();
	}
	if (pei.size() == 1 && pei.top() == '?' && str.size() > 1)
		return false;
	if(pei.top() != str.top() && (pei.top() != '?' && pei.top() != '*'))
		return false;
	while (!pei.empty() && !str.empty())
	{
		if (pei.top() == '?')
		{
			if (isnumOrstr(str.top()))
				str.pop();
			else
				return false;
		}
		else if (pei.top() == str.top())
		{
			pei.pop();
			str.pop();
		}
		else if (pei.top() == '*')
		{
			while (isnumOrstr(str.top()) && !str.empty())
				str.pop();
		}
	}
}

int main()
{
	string pei;
	string str;
	cin >> pei >> str;
	stack<char> _pei;
	stack<char> _str;
	/*if(pei.size() == 1 && pei[0] == '*')
		cout << "true" << endl;
	if(pei.size() == 1 && pei[0] == '?' && str.size() == 1)
		cout << "true" << endl;
	if(pei.size() == 1 && pei[0] == '?' && str.size() > 1)
		cout << "false" << endl;*/
	for (const auto& ch : pei)
		_pei.push(ch);
	for (const auto& ch : str)
		_str.push(ch);
	cout << fun(_pei, _str) << endl;
	return 0;
}