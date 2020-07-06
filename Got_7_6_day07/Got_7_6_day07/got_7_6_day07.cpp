#include <iostream>
#include <stack>
#include <string>
using namespace std;

//template<class T>
//class A {
//	long n;
//public:
//	A(T i) :n(i) {};
//	A operator+(A a)
//	{
//		return A(n + a.n);
//	}
//};
//
//int mina()
//{
//	A<int> a(1);
//	A<int> b(1);
//
//	a = a + 3;
//	a = 3 + a;
//
//	return 0;
//}

#include <iostream>
using namespace std;

int Fib(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return Fib(n - 1) + Fib(n - 2);
}

bool chkParenthesis(string A, int n) {
	//// write code here
	//if (n == 0 || n % 2 != 0)
	//	return false;
	//stack<char> st;
	//int i = 0;
	//while (i < A.size())
	//{
	//	if (A[i] != '(' && A[i] != ')')
	//		return false;
	//	while (A[i] == '(' && i < A.size())
	//	{
	//		st.push(A[i]);
	//		i++;
	//	}
	//	while (A[i] == ')' && i < A.size())
	//	{
	//		st.pop();
	//		i++;
	//	}
	//}
	//if (st.empty())
	//	return true;
	//else
	//	return false;

	if (n == 0 || n % 2 != 0)
		return false;
	int num = 0;
	for (int i = 0; i < A.size(); i++)
	{
		if (A[i] == '(')
			num++;
		if (A[i] == ')')
			num--;
	}
	if (num == 0)
		return true;
	else
		return false;
}

int main()
{
	/*int N = 0;
	cin >> N;
	int num = 0;
	int i = 0;
	while (num < N)
	{
		num = Fib(i);
		i++;
	}
	int big = num - N;
	int small = N - Fib(i - 2);
	int ret = big < small ? big : small;
	cout << ret << endl;*/
	string a("((())a())");
	if (chkParenthesis(a, 8))
		cout << "ret" << endl;

	return 0;
}