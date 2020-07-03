//#include <iostream>
//#include <string>
//using namespace std;
//
//int main()
//{
//	int Hash[256] = { 0 };
//	string s1;
//	cin >> s1;
//	Hash[s1[0]] = 1;
//	cout << (char)97 << endl;
//	cout << (int)'Z' << endl << (int)'z' << endl;;
//	return 0;
//}

#include <iostream>
#include <string>
#include<vector>
using namespace std;

//int main()
//{
//	int Hash[256] = { 0 };
//	int count = 1;
//	string input;
//	cin >> input;
//	string::iterator it = input.begin();
//	while (it != input.end())
//	{
//		if (Hash[*it] == 0)
//		{
//			Hash[*it] = count;
//			count++;
//
//		}
//		it++;
//	}
//	int out = 1;
//	while (out < count)
//	{
//		for (int i = 64; i < 123; i++)
//		{
//			if (Hash[i] == out)
//			{
//				cout << (char)i;
//				out++;
//			}
//		}
//	}
//
//	cout << endl;
//	return 0;
//}


int findElement(vector<int> A, int n, int x) {
	// write code here
	int left = 0;
	int right = n - 1;
	int mid = 0;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (A[mid] == x)
			return mid;
		if (A[mid] < x)
		{
			if (A[mid] < A[left] && x > A[right])
				right = mid - 1;
			else
				left = mid + 1;
		}
		else
		{
			if (A[mid] > A[left] && x < A[left])
				left = mid + 1;
			else
				right = mid - 1;
		}
	}
}

int main()
{
	string s1, s2;
	cin >> s1;
	int Hash[256] = { 0 };
	string::iterator it = s1.begin();
	while (it != s1.end())
	{
		if (Hash[*it] == 0)
		{
			Hash[*it] = 1;
			s2.push_back(*it);
		}
		if (Hash[*it] == 1)
		{
			it++;
		}
		//it++;
	}
	cout << s2;
	return 0;
}