#include <iostream>
#include <stack>
#include <vector>
#include <queue>
using namespace std;

int getLCA(int a, int b) {
        // write code here
        queue<int> a_path;
        queue<int> b_path;
        int child = a - 1;
        int parent = 0;
        while(child > 0)
        {
            if(child % 2 != 0)
            {
                parent = (child - 1) / 2;
                a_path.push(parent);
            }
            else
            {
                parent = (child - 2) / 2;
                a_path.push(parent);
            }
            child = parent;
        }
        child = b - 1;
        parent = 0;
        while(child > 0)
        {
            if(child % 2 != 0)
            {
                parent = (child - 1) / 2;
                b_path.push(parent);
            }
            else
            {
                parent = (child - 2) / 2;
                b_path.push(parent);
            }
            child = parent;
        }
        while(a_path.size() != b_path.size())
        {
            if(a_path.size() > b_path.size())
                a_path.pop();
            else
                b_path.pop();
        }
        while(!a_path.empty())
        {
            if(a_path.front() == b_path.front())
                break;
            a_path.pop();
            b_path.pop();
        }
        return a_path.front() + 1;
    }

//int main()
//{
//	vector<int> arr;
//	//arr.resize(8);
//	int a = 0;
//	cin >> a;
//	//int a = a;
//	int step = 0;
//	while (a != 0 && a != 1)
//	{
//		step = a % 2;
//		arr.push_back(step);
//		a = a / 2;
//	}
//	arr.push_back(a);
//	//reverse(arr.begin(), arr.end());
//	int count = 0;
//	int max = 0;
//	for (int i = 0; i < arr.size(); i++)
//	{
//		if (arr[i] == 1)
//			count++;
//		else {
//			max = count;
//			count = 0;
//		}
//	}
//	int ret = max > count ? max : count;
//	cout << ret;
//	/*for (const auto i : arr)
//		cout << i << " ";
//	cout << endl;*/
//	return 0;
//}

int main()
{
    int a = 0;
    while(cin >> a){
        int count = 0;
        int max = 0;
        while(a)
        {
            if(a & 1){
                count++;
                max = max > count ? max : count;
            }
            else
                count = 0;
            a = a >> 1;
        }
        cout << max << endl;
    }
    return 0;
}