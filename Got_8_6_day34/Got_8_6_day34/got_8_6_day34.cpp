//// write your code here cpp
//#include <iostream>
//#include <string>
//using namespace std;
//
//int main()
//{
//	int n = 0;
//	while (cin >> n)
//	{
//		string str;
//		while (getline(cin, str))
//		{
//			n--;
//			int flag = 0;
//			for (auto ch : str)
//			{
//				if (ch == ' ' || ch == ',')
//				{
//					flag = 1;
//					break;
//				}
//			}
//			if (flag == 0)
//			{
//				if (n == 1)
//					printf("%s\n", str.c_str());
//				else
//					printf("%s, ", str.c_str());
//			}
//			else
//			{
//				string tmp;
//				tmp += '"';
//				for (auto ch : str)
//					tmp += ch;
//				tmp += '"';
//				if (n == 1)
//					printf("%s\n", tmp.c_str());
//				else
//					printf("%s, ", tmp.c_str());
//			}
//		}
//	}
//	return 0;
//}


// write your code here cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int n = 0;
	while (cin >> n)
	{
		vector<string> arr;
		arr.resize(n);
		string la;
		getline(cin, la);
		for (int i = 0; i < arr.size(); i++)
			getline(cin, arr[i]);
		for (int i = 0; i < arr.size(); i++)
		{
			int flag = 0;
			for (auto ch : arr[i])
			{
				if (ch == ' ' || ch == ',')
				{
					flag = 1;
					break;
				}
			}
			if (flag == 0)
			{
				if (i == arr.size() - 1)
					printf("%s\n", arr[i].c_str());
				else
					printf("%s, ", arr[i].c_str());
			}
			else
			{
				//string tmp;
				//tmp += '"';
				//for (auto ch : arr[i])
				//	tmp += ch;
				//tmp += '"';
				if (i == arr.size() - 1)
					printf("\"%s\"\n", arr[i].c_str());
				else
					printf("\"%s\", ", arr[i].c_str());
			}
		}
	}
	return 0;
}