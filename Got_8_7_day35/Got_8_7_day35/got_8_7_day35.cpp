// write your code here cpp
#include <iostream>
#include <math.h>
#include <vector>
#include <string>
using namespace std;

//int mul(int num)
//{
//	int ret = 1;
//	for (int i = 1; i <= num; i++)
//		ret *= i;
//	return ret;
//}
//
//int main()
//{
//	int n = 0;
//	while (cin >> n)
//	{
//		int flag = -1;
//		float ret = 1;
//		for (int i = 1; i <= n; i++)
//			ret += pow(flag, i) * (1.00000 / mul(i));
//		printf("%.2f%%\n", ret * 100);
//	}
//	return 0;
//}

// write your code here cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	string list, name;
	while (getline(cin, list) && cin >> name)
	{
		vector<string> arr;
		for (int i = 0; i < list.size(); i++)
		{
			string tmp;
			if (list[i] == '\"')
			{
				i++;
				while (list[i] != '\"' && i < list.size())
				{
					tmp += list[i];
					i++;
				}
				i++;
				arr.push_back(tmp);
			}
			else if (list[i] == ',')
			{
				i++;
			}
			else
			{
				while (list[i] != ',' && i < list.size())
				{
					tmp += list[i];
					i++;
				}
				arr.push_back(tmp);
			}
		}
		int flag = 0;
		for (int i = 0; i < arr.size(); i++)
		{
			if (name == arr[i])
			{
				//cout << "Ignore" << endl;
				printf("Ignore\n");
				flag = 1;
			}
		}
		if (flag == 0)
			printf("Important!\n");
		//cout << "Important!" << endl;
		string s;
		getline(cin, s);
	}
	return 0;
}