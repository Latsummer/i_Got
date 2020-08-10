//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//
//int main()
//{
//	int n = 0;
//	while (cin >> n)
//	{
//		vector<int> arr(n, 0);
//		vector<char> ids(n, ' ');
//		vector<char> ret(n, ' ');
//		n--;
//		string id, cao;
//		int i = 0;
//		while (cin >> id >> cao && n--)
//		{
//			ids[i] = id[0];
//			if (cao == "connect")
//				arr[i] = 1;
//			else
//				arr[i] = 0;
//			i++;
//		}
//		int max = 0;
//		int tmp = 0;
//		for (int i = 0; i < ids.size(); i++)
//		{
//			if (arr[i] == 1)
//				tmp++;
//			else
//				tmp--;
//			if (tmp >= max)
//				max = tmp;
//		}
//		cout << max << endl;
//	}
//	return 0;
//}


// write your code here cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n = 0;
	while (cin >> n)
	{
		vector<string> make;
		vector<bool> flag(n, true);
		while (n--)
		{
			string tmp;
			cin >> tmp;
			make.push_back(tmp);
		}
		sort(make.begin(), make.end());
		for (int i = 0; i < make.size() - 1; i++)
		{
			if (make[i] == make[i + 1])
				flag[i] = false;
			else if (make[i].size() < make[i + 1].size() && make[i] == make[i + 1].substr(0, make[i].size())
				&& make[i + 1][make[i].size()] == '/')
				flag[i] = false;
		}
		for (int i = 0; i < make.size(); i++)
		{
			if (flag[i] == true)
				printf("mkdir -p %s\n", make[i].c_str());
		}
		cout << endl;
	}
	return 0;
}