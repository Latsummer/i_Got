#include <string>
#include <iostream>
using namespace std;

int main()
{
	string duan;
	string chang;
	cin >> duan >> chang;
		if (duan.size() > chang.size())
			swap(duan, chang);
		for (auto& ch : duan)
		{
			if (ch >= 'A' && ch <= 'Z')
				ch += 32;
		}
		for (auto& ch : chang)
		{
			if (ch >= 'A' && ch <= 'Z')
				ch += 32;
		}

		size_t max = 0;
		for (size_t i = duan.size(); i > 1; i--)
		{
			for (size_t j = 0; j <= duan.size() - i; j++)
			{
				string tmp;
				int fin = 0;
				tmp = duan.substr(j, i);
				fin = chang.find(tmp);
				if ((fin != -1) && max < tmp.size())
				{
					max = tmp.size();
				}
			}
		}
		cout << max << endl;
	return 0;
}