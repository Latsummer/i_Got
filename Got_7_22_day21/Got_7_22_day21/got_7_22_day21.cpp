#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

//void xipai(vector<int>& arr, int k)
//{
//	vector<int> pai(arr);
//	//pai.resize(arr.size());
//	while (k--)
//	{
//		vector<int> left;
//		vector<int> right;
//		int half = pai.size() / 2;
//		for (int i = 0; i < half; i++)
//			left.push_back(pai[i]);
//		for (int i = half; i < arr.size(); i++)
//			right.push_back(pai[i]);
//		for (int i = 0; i < pai.size(); i++)
//		{
//			if (i % 2 == 0)
//				pai[i] = left[i / 2];
//			else
//				pai[i] = right[i / 2];
//		}
//	}
//	for (int i = 0; i < pai.size() - 1; i++)
//		cout << pai[i] << " ";
//	cout << pai[pai.size() - 1] << endl;
//}
//
//int main()
//{
//	int T = 0;
//	cin >> T;
//	int n, k;
//	for (int i = 0; i < T; i++)
//	{
//		cin >> n >> k;
//		vector<int> arr;
//		for (int j = 0; j < 2 * n; j++)
//		{
//			int tmp;
//			cin >> tmp;
//			arr.push_back(tmp);
//		}
//		xipai(arr, k);
//	}
//	return 0;
//}


void little(vector<int>& nums, vector<int>& order)
{
	int idx = 0;
	int size = order.size();
	int num_size = nums.size();
	for (int i = 0; i < size; i++)
	{
		if (order[i] == 1)
		{
			idx--;
			if (idx < 0)
				idx = num_size - 1;
		}
		if (order[i] == 0)
		{
			idx++;
			if (idx == num_size)
				idx = 0;
		}
	}
	for (auto e : nums)
		cout << e << " ";
	cout << endl;
	cout << nums[idx] << endl;
}

void bigger(vector<int>& nums, vector<int>& order)
{
	int up = 0, down = 3;
	int idx = 0;
	int or_size = order.size();
	int nm_size = nums.size();
	for (int i = 0; i < or_size; i++)
	{
		if (order[i] == 1)
		{
			idx--;
			if (idx < up)
			{
				up--;
				down--;
				if (up < 0)
				{
					up = nm_size - 4;
					down = nm_size - 1;
					idx = down;
				}
			}
		}
		if (order[i] == 0)
		{
			idx++;
			if (idx > down)
			{
				up++;
				down++;
				if (down >= nm_size)
				{
					up = 0;
					down = 3;
					idx = up;
				}
			}
		}
	}
	for (int i = up; i <= down; i++)
		cout << nums[i] << " ";
	cout << endl;
	cout << nums[idx] << endl;
}

int main()
{
	int num;
	string order;
	while (cin >> num >> order) {
		vector<int> arr;
		arr.resize(order.size());
		for (int i = 0; i < order.size(); i++)
		{
			if (order[i] == 'U')
				arr[i] = 1;
			if (order[i] == 'D')
				arr[i] = 0;
		}
		vector<int> nums;
		nums.resize(num);
		for (int i = 0; i < num; i++)
			nums[i] = i + 1;
		if (num <= 4)
			little(nums, arr);
		else
			bigger(nums, arr);
	}
}
