#include <iostream>
#include <set>
#include <vector>
#include <queue>
using namespace std;

//int Get_Month_Day(int year, int month)
//{
//	int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//	int day = days[month];
//	if (month == 2 && ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
//		day++;
//	return day;
//}
//
//int main()
//{
//	int year, month, day;
//	cin >> year >> month >> day;
//	int days = 0;
//	for (int i = 0; i < month; i++)
//		days += Get_Month_Day(year, i);
//	days += day;
//	cout << days;
//	return 0;
//}



//int main()
//{
//	int n = 0;
//	cin >> n;
//	priority_queue<int> pq;
//	int lucks = 0;
//	long long sum = 0;
//	long long mul = 1;
//	while (n--)
//	{
//		int tmp;
//		cin >> tmp;
//		sum += tmp;
//		mul *= tmp;
//		pq.push(tmp);
//	}
//	if (sum > mul)
//		lucks++;
//	while (pq.size() != 1)
//	{
//		int tmp = pq.top();
//		sum -= tmp;
//		mul /= tmp;
//		if (sum > mul)
//			lucks++;
//		pq.pop();
//	}
//	cout << lucks;
//	return 0;
//}

//int main()
//{
//	int n = 0;
//	cin >> n;
//	vector<int> arr;
//	while (n--)
//	{
//		int tmp = 0;
//		cin >> tmp;
//		arr.push_back(tmp);
//	}
//	int lucks = 0;
//	int sum = 0;
//	int mul = 1;
//	sort(arr.begin(), arr.end());
//	for (size_t i = 0; i < arr.size(); i++)
//	{
//		sum += arr[i];
//		mul *= arr[i];
//		if (sum > mul)
//		{
//			lucks++;
//			continue;
//		}
//		else if (arr[i] == 1)
//			continue;
//		else
//			break;
//	}
//	cout << lucks;
//	return 0;
//}


int Get_Lucks(vector<int>& arr, size_t n, size_t idx, int sum, int mul)
{
	int lucks = 0;
	for (size_t i = idx; i < n; i++)
	{
		sum += arr[i];
		mul *= arr[i];
		if (sum > mul)
			lucks += 1 + Get_Lucks(arr, n, i + 1, sum, mul);
		else if (arr[i] == 1)
			lucks += Get_Lucks(arr, n, i + 1, sum, mul);
		else
			break;
		sum -= arr[i];
		mul /= arr[i];

		while (i < n - 1 && arr[i] == arr[i + 1])
			i++;
	}
	return lucks;
}

int main()
{
	int n = 0;
	cin >> n;
	vector<int> arr;
	int n2 = n;
	while (n2--)
	{
		int tmp = 0;
		cin >> tmp;
		arr.push_back(tmp);
	}
	sort(arr.begin(), arr.end());
	int ret = Get_Lucks(arr, n, 0, 0, 1);
	cout << ret;
	return 0;
}