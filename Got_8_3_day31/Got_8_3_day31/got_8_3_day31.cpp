// write your code here cpp
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int get_week(int year, int month, int day)
{
	if (month == 1 || month == 2)
	{
		month += 12;
		year--;
	}
	int c = year / 100;
	year %= 100;
	int week = (c / 4) - 2 * c + year + (year / 4) + (26 * (month + 1) / 10) + day - 1;
	week = (week % 7 + 7) % 7;
	if (week == 0)
		week = 7;

	return week;
}
int get_day(int year, int month, int week, int day_week)
{
	int weekDay = get_week(year, month, 1);
	int day = 1 + (week - 1) * 7 + ((7 - weekDay) + day_week) % 7;
	return day;
}

void newyear(int year)
{
	printf("%d-01-01\n", year);
}
void mading(int year)
{
	printf("%d-01-%02d\n", year, get_day(year, 1, 3, 1));
}
void zongtong(int year)
{
	printf("%d-02-%02d\n", year, get_day(year, 2, 3, 1));
}
void zhenwang(int year)
{
	int week = get_week(year, 6, 1);
	int d = (week == 1) ? 6 : (week - 2);
	int day = 31 - d;
	printf("%d-05-%02d\n", year, day);
}
void guoqing(int year)
{
	printf("%d-07-04\n", year);
}
void laodong(int year)
{
	printf("%d-09-%02d\n", year, get_day(year, 9, 1, 1));
}
void ganen(int year)
{
	printf("%d-11-%02d\n", year, get_day(year, 11, 4, 4));
}
void shengdan(int year)
{
	printf("%d-12-25\n", year);
}

void printDay(int year)
{
	newyear(year);
	mading(year);
	zongtong(year);
	zhenwang(year);
	guoqing(year);
	laodong(year);
	ganen(year);
	shengdan(year);
}

//int main()
//{
//	int year = 0;
//	while (cin >> year)
//	{
//		printDay(year);
//		cout << endl;
//	}
//	return 0;
//}


int main()
{
	int num = 0;
	while (cin >> num)
	{
		vector<int> ret;
		printf("%d = ", num);
		int tmp = sqrt(num);
		for (int i = 2; i <= tmp; i++)
		{
			while (num % i == 0)
			{
				if (num == i)
					break;
				ret.push_back(i);
				num /= i;
			}
		}
		ret.push_back(num);
		for (int i = 0; i < ret.size() - 1; i++)
			printf("%d * ", ret[i]);
		printf("%d\n", ret[ret.size() - 1]);
	}
	return 0;
}