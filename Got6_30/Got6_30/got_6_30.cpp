#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

//struct A {
//	unsigned a : 19;
//	unsigned b : 11;
//	unsigned c : 4;
//	unsigned d : 29;
//	char idex;
//};
//
//int main()
//{	
//	cout << sizeof(struct A) << endl;
//	cout << sizeof(unsigned) << endl;
//	return 0;
//}

//void sss(char[], int[]);
//
//int main()
//{
//	//int a[] = { 1,2,3,4 };
//	//int* b = a;
//	//*b += 2;
//	//*(b + 2) = 2;
//	//b++;
//	//printf("%d, %d\n", *b, *(b + 2));
//	int a[10];
//	char b[80];
//
//	sss(b, a);
//}

//int main()
//{
//	string input;
//	stack<char> st;
//	string ret;
//	getline(cin, input);
//	for (int i = 0; i < input.size(); i++)
//	{
//		st.push(input[i]);
//	}
//	while (!st.empty())
//	{
//		string tmp;
//		while ( !st.empty() && st.top() != ' ')
//		{
//			tmp.insert(tmp.begin(), st.top());
//			st.pop();
//		}
//		if (!st.empty())
//		{
//			st.pop();
//		}
//		ret.append(tmp);
//		ret.push_back(' ');
//	}
//	cout << ret;
//	return 0;
//}

int main()
{
	vector<int> input;
	int num = 0;
	int count = 1;
	cin >> num;
	input.resize(num);
	for (int i = 0; i < num; i++)
		cin >> input[i];
	for(int i = 1; i < num - 1; i++)
    {
        if((input[i - 1] > input[i] && input[i] < input[i + 1])
          || (input[i - 1] < input[i] && input[i] > input[i + 1]))
        {
            count++;
            if(i != num - 3)
                i++;
        }
    }
    cout << count << endl;
	return 0;
}