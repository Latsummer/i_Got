#include <iostream>
using namespace std;

static int days[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
static int earn[] = { 0,62,28,31,60,31,60,31,62,60,62,30,62 };

bool isSushu(int month)
{
	if (month == 2 || month == 3 || month == 5 || month == 7 || month == 11)
		return true;
	else
		return false;
}

bool isRun(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return true;
	else
		return false;
}

int getDays(int month, int day1, int day2)
{
	int sum = day2 - day1 + 1;
	if (!isSushu(month))
		sum += sum;
	return sum;
}

int getMonth(int year, int month1, int month2)
{
	int sum = 0;
	for (int i = month1; i <= month2; i++)
	{
		sum += earn[i];
		if (i == 2 && isRun(year))
			sum++;
	}
	return sum;
}

int getYear(int year1, int year2)
{
	int sum = 0;
	for (int i = year1; i <= year2; i++)
	{
		sum += getMonth(1, 12, i);
	}
	return sum;
}

/*int main()
{
	int year1, month1, day1;
	int year2, month2, day2;
	while (cin >> year1 >> month1 >> day1 >> year2 >> month2 >> day2)
	{
		int ret = 0;
		//int year = year2 - year1;
		if (year1 == year2)
		{
			if (month1 == month2)
			{
				ret = getDays(month1, day1, day2);
			}
			else
			{
				ret += getMonth(year1, month1, month2);
				ret += getDays(month1, day1, days[month1]);
				ret += getDays(month2, 1, day2);
			}
		}
		else
		{
			ret += getYear(year1 + 1, year2 - 1);
			ret += getMonth(year1, month1 + 1, 12);
			ret += getMonth(year2, 1, month2 - 1);
			ret += getDays(month1, day1, days[month1]);
			ret += getDays(month2, 1, day2);
		}

		cout << ret << endl;

	}
	return 0;
}*/

// write your code here cpp
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> arr(1000001, 0);
	arr[0] = 1;
	arr[1] = 1;
	for (int i = 2; i < arr.size(); i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
		arr[i] %= 1000000;
	}
	int n = 0;
	while (cin >> n)
	{
		if (n > 29)
			printf("%06d\n", arr[n]);
		else
			cout << arr[n] << endl;
	}
}