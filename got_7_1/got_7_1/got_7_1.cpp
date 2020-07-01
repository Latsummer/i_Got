#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

int MoreThanHalfNum_Solution(vector<int> numbers) {
	sort(numbers.begin(), numbers.end());
    int half = numbers.size() / 2;
    int count = 0;
    int key = numbers[half];
    for(int i = 0; i <numbers.size(); i++)
    {
        if(numbers[i] == key)
            count++;
    }
    if(count > half)
        return numbers[half];
    else
        return 0;
	//stack<int> max;
	//qsort()
	////vector::iterator it = numbers.begin();
	//int it = 0;
	//while (it < numbers.size())
	//	//for(int i = 0; i < numbers.size(); )
	//{
	//	stack<int> st;
	//	st.push(numbers[it++]);
	//	while (numbers[it] == numbers[it - 1])
	//		st.push(numbers[it++]);
	//	if (st.size() > max.size())
	//		max = st;
	//	it++;
	//}
	//if (max.size() > numbers.size() / 2)
	//	return max.top();
	//else
	//	cout << 0;
}

int main()
{
	//string s1;
	//stack<char> max;
	//getline(cin, s1);
	//string::reverse_iterator rit = s1.rbegin();
	//while (rit != s1.rend())
	//{
	//	stack<char> st;
	//	while (*rit >= '0' && *rit <= '9')
	//	{
	//		st.push(*rit);
	//		rit++;
	//	}
	//	if (st.size() > max.size())
	//		max = st;
	//	rit++;
	//}
	//while (!max.empty())
	//{
	//	cout << max.top();
	//	max.pop();
	//}
	//cout << endl;
	vector<int> arr = { 1, 2, 3, 2, 2, 2, 5, 4, 2 };
	cout << MoreThanHalfNum_Solution(arr);
	return 0;
}