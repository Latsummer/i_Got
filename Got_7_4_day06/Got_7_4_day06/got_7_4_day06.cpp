#include <vector>
#include <iostream>
#include <string>
using namespace std;


//int main()
//{
//	int W, H;
//	cin >> W >> H;
//	int count = 0;
//	vector<vector<int>> arr;
//	arr.resize(H);
//	for (auto& ch : arr)
//		ch.resize(W, 1);
//	for (int i = 0; i < H; i++)
//	{
//		for (int j = 0; j < W; j++)
//		{
//			if (arr[i][j] == 1)
//			{
//				count++;
//				if (i + 2 < H)
//					arr[i + 2][j] = 0;
//				if (j + 2 < W)
//					arr[i][j + 2] = 0;
//			}
//		}
//	}
//	cout << count;
//}
int StrToInt(string str) {
	int flag = 0;
	if (str[0] == '+') {
		flag = 1;
	}
	else if (str[0] == '-') {
		flag = -1;
	}
	else {
		return 0;
	}
	for (int i = 1; i < str.size(); i++)
	{
		if (str[i] < '0' && str[i] > '9')
			return 0;
	}
	int num = 0;

	string::iterator it = str.begin();
	while (it != str.end())
	{
		if (*it == '+' || *it == '-')
		{
			it++;
			continue;
		}
		num = 10*num + (*it - '0');
		it++;
	}
	num *= flag;
	return num;
}

int StrToInt2(string str) {
	if (str.length() == 0)
		return 0;
	int flag = 0;
	if (str[0] == '+') {
		flag = 1;
	}
	else if (str[0] == '-') {
		flag = -1;
	}
	else {
		return 0;
	}

	long num = 0;
	for (size_t i = 1; i < str.size(); i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return 0;
		num = 10 * num + (str[i] - '0');
	}
	return flag == 1 ? (int)num : -(int)num;
	/*if (flag == 1)
		return (int)num;
	if (flag == -1)
		return -(int)num;*/
	/*for(int i = 1; i < str.size(); i++)
	{
		if(str[i] < '0' && str[i] > '9')
			return 0;
	}
	long num = 0;

	string::iterator it = str.begin();
	while(it != str.end())
	{
		if(*it == '+' || *it == '-')
		{
			it++;
			continue;
		}
		num = 10*num + (*it - '0');
		it++;
	}
	num *= flag;
	return (int)num;*/
}


int main()
{
	string s1; 
	cin >> s1;
	int ret = StrToInt2(s1);
	cout << ret;
	return 0;
}