#include <iostream>
#include <string>
#include <math.h>
#include <vector>
using namespace std;

//bool is_prefect(int x)
//{
//	vector<int> arr;
//	for (int i = 1; i <= sqrt(x); i++)
//	{
//		if (x % i == 0)
//		{
//			arr.push_back(i);
//			if (x != i * i)
//				arr.push_back(x / i);
//		}
//	}
//	int sum = 0;
//	for (const auto& a : arr)
//	{
//		if (a != x)
//			sum += a;
//	}
//	if (x == sum)
//		return true;
//	else
//		return false;
//}
//
//int main()
//{
//	int n = 0;
//	cin >> n;
//	int count = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		if (is_prefect(i))
//			count++;
//	}
//	cout << count << endl;
//	return 0;
//}

void get_hash(int h[], string& s)
{
	string::reverse_iterator rit = s.rbegin();
	while (rit != s.rend())
	{
		if ((*rit) == 'r')
		{
			h[14]++;
			rit++;
			rit++;
			rit++;
			rit++;
			rit++;
			continue;
		}
		if ((*rit) == 'R')
		{
			h[15]++;
			rit++;
			rit++;
			rit++;
			rit++;
			rit++;
			continue;
		}
		if ((*rit) >= '2' && (*rit) <= '10')
		{
			char tmp = *rit;
			h[(tmp - '0')]++;
		}
		else if ((*rit) == 'A')
			h[1]++;
		else if ((*rit) == 'J')
			h[11]++;
		else if ((*rit) == 'Q')
			h[12]++;
		else if ((*rit) == 'K')
			h[13]++;
		rit++;
	}

}

bool whoWin(int h_l[], int h_r[], string& l, string& r)
{
	//王炸
	if (h_l[14] == 1 && h_l[15] == 1)
	{
		cout << l << endl;
		return true;
	}
	if (h_r[14] == 1 && h_r[15] == 1)
	{
		cout << r << endl;
		return true;
	}

	//炸弹
	int i = 0;
	for (i = 0; i < 16; i++)
	{
		if (h_l[i] == 4)
		{
			h_l[0] = 1;
			break;
		}
	}

	int j = 0;
	for (j = 0; j < 16; j++)
	{
		if (h_r[j] == 4)
		{
			h_r[0] = 1;
			break;
		}
	}

	if (h_l[0] == 1 && h_r[0] == 1)
	{
		if (i > j)
			cout << l << endl;
		else
			cout << r << endl;
		return true;
	}
	else if (h_l[0] == 1 && h_r[0] == 0)
	{
		cout << l << endl;
		return true;
	}
	else if (h_l[0] == 0 && h_r[0] == 1)
	{
		cout << r << endl;
		return true;
	}


	h_l[0] = 0;
	h_r[0] = 0;
	i = 0;
	j = 0;
	//三个
	for (i = 0; i < 16; i++)
	{
		if (h_l[i] == 3)
		{
			h_l[0] = 1;
			break;
		}
	}

	for (j = 0; j < 16; j++)
	{
		if (h_r[j] == 3)
		{
			h_r[0] = 1;
			break;
		}
	}

	if (h_l[0] == 1 && h_r[0] == 1)
	{
		if (i == 2)
			cout << l << endl;
		else if (j == 2)
			cout << r << endl;
		else if (i == 1)
			cout << l << endl;
		else if (j == 1)
			cout << r << endl;
		else if (i > j)
			cout << l << endl;
		else
			cout << r << endl;
		return true;
	}
	/*else if (h_l[0] == 1 && h_r[0] == 0)
	{
		cout << l << endl;
		return true;
	}
	else if (h_l[0] == 0 && h_r[0] == 1)
	{
		cout << r << endl;
		return true;
	}*/

	//顺子
	h_l[0] = 0;
	h_r[0] = 0;
	i = 0;
	j = 0;
	for (i = 5; i <= 13; i++)
	{
		if (h_l[i] > 0 && h_l[i - 1] > 0 && h_l[i - 2] > 0
			&& h_l[i - 3] > 0 && h_l[i - 4] > 0)
		{
			h_l[0] = i - 4;
			break;
		}
	}

	for (j = 5; j <= 13; j++)
	{
		if (h_r[j] > 0 && h_r[j - 1] > 0 && h_r[j - 2] > 0
			&& h_r[j - 3] > 0 && h_r[j - 4] > 0)
		{
			h_r[0] = j - 4;
			break;
		}
	}

	if (h_l[0] != 0 && h_r[0] != 0)
	{
		if (h_l[0] == 2)
			cout << l << endl;
		else if (h_r[0] == 2)
			cout << r << endl;
		else if (h_l[0] == 1)
			cout << l << endl;
		else if (h_r[0] == 1)
			cout << r << endl;
		else if (h_l[0] > h_r[0])
			cout << l << endl;
		else
			cout << r << endl;
		return true;
	}
	//对子
	h_l[0] = 0;
	h_r[0] = 0;
	i = 0;
	j = 0;

	for (i = 0; i <= 13; i++)
	{
		if (h_l[i] == 2)
			h_l[0] = i;
	}
	for (j = 0; j <= 13; j++)
	{
		if (h_r[j] == 2)
			h_r[0] = j;
	}

	if (h_l[0] != 0 && h_r[0] != 0)
	{
		if (h_l[0] == 2)
			cout << l << endl;
		else if (h_r[0] == 2)
			cout << r << endl;
		else if (h_l[0] == 1)
			cout << l << endl;
		else if (h_r[0] == 1)
			cout << r << endl;
		else if (h_l[0] > h_r[0])
			cout << l << endl;
		else
			cout << r << endl;
		return true;
	}
	//个子
	return false;

}

int main()
{
	string input("4 4 4 4-joker JOKER");
	//getline(cin, input);
	string left;
	string right;
	int i = 0;
	for (i = 0; i < input.size(); i++)
	{
		if (input[i] != '-')
			left += input[i];
		else
			break;
	}
	for (++i; i < input.size(); i++)
		right += input[i];

	string ret_l(left);
	string ret_r(right);

	int hash_left[16] = { 0 };
	int hash_right[16] = { 0 };
	int fin = 0;
	while ((fin = left.find(' ', fin)) != string::npos)
		left.erase(fin, 1);
	fin = 0;
	while ((fin = right.find(' ', fin)) != string::npos)
		right.erase(fin, 1);
	get_hash(hash_left, left);
	get_hash(hash_right, right);

	if (!whoWin(hash_left, hash_right, ret_l, ret_r))
		cout << "ERROR" << endl;
}