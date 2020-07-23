#include<iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;
//
//int getYue(int a, int b)
//{
//	for (int i = a; i > 0; i--)
//	{
//		if (a % i == 0 && b % i == 0)
//			return i;
//	}
//}
//
//int update(int power, vector<int>& monster)
//{
//	for (const auto& e : monster)
//	{
//		if (e <= power)
//			power += e;
//		else
//			power += getYue(power, e);
//	}
//	return power;
//}
//
//int main()
//{
//	int power, n;
//	while (cin >> power >> n) {
//		vector<int> monster;
//		monster.resize(n);
//		while (n--)
//		{
//			int tmp = 0;
//			cin >> tmp;
//			monster.push_back(tmp);
//		}
//		power = update(power, monster);
//		cout << power << endl;
//	}
//	return 0;
//}


int main()
{
	string str;

	while (cin >> str) {
		unordered_map<char, int> um;
		vector<char> arr;
		for (auto ch : str)
			um[ch]++;
		for (auto u : um)
		{
			if (u.second == 1)
				arr.push_back(u.first);
		}
		if (arr.size() == 0)
			cout << -1 << endl;
		else
		{
			size_t min = str.find(arr[0]);
			for (int i = 0; i < arr.size(); i++)
			{
				size_t pos = str.find(arr[i]);
				if (pos < min)
					min = pos;
			}
			cout << str[min] << endl;
		}
	}
	return 0;
}