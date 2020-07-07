#include <iostream>
#include <string>
#include <vector>
using namespace std;

//class cla {
//	static int n;
//public:
//	cla() { n++; }
//	~cla() { n--; }
//	static int get_n() { return n; }
//};
//int cla::n = 0;
//int main()
//{
//	cla* p = new cla;
//	delete p;
//	cout << cla::get_n() << endl;
//	return 0;
//}

//class A {
//public:
//	A() :m_ival(0) { test(); }
//	virtual void func() { cout << m_ival << " "; }
//	void test() { func(); }
////public:
//	int m_ival;
//};
//class B : public A {
//public:
//	B() { test(); }
//	virtual void func()
//	{
//		++m_ival;
//		cout << m_ival << " ";
//	}
//};
//
//int main()
//{
//	//A* p = new B;
//	//p->test();
//	B b1, b2;
//	B* p[2] = { &b1, &b2 };
//	return 0;
//}

//bool is_zidian(vector<string>& str)
//{
//	for (int i = 1; i < str.size(); i++)
//	{
//		if (str[i] < str[i - 1])
//			return false;
//	}
//	return true;
//}
//
//bool is_length(vector<string>& str)
//{
//	vector<int> len;
//	len.resize(str.size());
//	for (int i = 0; i < str.size(); i++)
//		len[i] = str[i].length();
//	for (int i = 1; i < len.size(); i++)
//	{
//		if (len[i] < len[i - 1])
//			return false;
//	}
//	return true;
//}
//
//int main()
//{
//	int n = 0;
//	cin >> n;
//	vector<string> str;
//	str.resize(n);
//	for (int i = 0; i < n; i++)
//		cin >> str[i];
//	int zidian = 0;
//	int length = 0;
//	if (is_zidian(str))
//		zidian = 1;
//	if (is_length(str))
//		length = 1;
//
//	if (zidian == 1 && length == 1) {
//		cout << "both" << endl;
//	}
//	else if (zidian == 0 && length == 0) {
//		cout << "none" << endl;
//	}
//	else if (zidian == 1 && length == 0) {
//		cout << "lexicographically" << endl;
//	}
//	else {
//		cout << "lengths" << endl;
//	}
//	return 0;
//}

int main()
{
	int A = 0;
	int B = 0;
	cin >> A >> B;

	for (int i = 1; ; i++)
	{
		int _A = i % A;
		int _B = i % B;
		if (_A == 0 && _B == 0) {
			cout << i << endl;
			break;
		}
	}
	return 0;
}