#include <iostream>
#include <string>
using namespace std;

int toInt(char ch)
{
	return ch - '0';
}

int main()
{
	string add;
	string unadd;
	cin >> add >> unadd;
	string ret;
	int step = 0;

	string::reverse_iterator radd = add.rbegin();
	string::reverse_iterator rund = unadd.rbegin();

	while (radd != add.rend() || rund != unadd.rend())
	{
		int tmp = 0;
		if (radd != add.rend() && rund != unadd.rend())
			tmp = toInt(*radd) + toInt(*rund) + step;
		else if(radd != add.rend() && rund == unadd.rend())
			tmp = toInt(*radd) + step;
		else if (radd == add.rend() && rund != unadd.rend())
			tmp = toInt(*rund) + step;
		if (tmp >= 10)
		{
			tmp -= 10;
			step = 1;
			ret += (char)(tmp + '0');
		}
		else
		{
			step = 0;
			ret += (char)(tmp + '0');
		}

		if (radd != add.rend())
			radd++;
		if (rund != unadd.rend())
			rund++;
	}
	if (step == 1)
		ret += '1';
	reverse(ret.begin(), ret.end());
	cout << ret;
	return 0;
}