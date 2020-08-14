// write your code here cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int _DFS(vector<vector<char> >& Map, char key, int x, int y)
{
	int max = 0;
	int dir[4][2][2] = {
		{{-1, 0}, {1, 0}},
		{{0, -1}, {0, 1}},
		{{-1, -1}, {1, 1}},
		{{-1, 1}, {1, -1}}
	};
	for (int i = 0; i < 4; i++)
	{
		int cnt = 0;
		for (int j = 0; j < 2; j++)
		{
			int nx = x, ny = y;
			while (nx >= 1 && nx <= 20 && ny >= 1 && ny <= 20 && Map[nx][ny] == key)
			{
				nx += dir[i][j][0];
				ny += dir[i][j][1];
				cnt++;
			}
			max = max > cnt ? max : cnt;
		}
	}
	return max - 1;
}

bool DFS(vector<vector<char> >& Map)
{
	for (int i = 1; i <= 20; i++)
	{
		for (int j = 1; j <= 20; j++)
		{
			if (Map[i][j] == '*' || Map[i][j] == '+')
				if (_DFS(Map, Map[i][j], i, j) >= 5)
					return true;
		}
	}
	return false;
}

bool wuzi(vector<string>& input)
{
	vector<vector<char> > Map(22, vector<char>(22));
	for (int i = 1; i <= 20; i++)
	{
		for (int j = 1; j <= 20; j++)
		{
			Map[i][j] = input[i - 1][j - 1];
		}
	}
	return DFS(Map);
}

int main()
{
	string tmp;
	vector<string> input;
	while (cin >> tmp)
	{
		input.push_back(tmp);
		if (input.size() == 20)
		{
			if (wuzi(input))
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
			input.clear();
		}
	}
	return 0;
}


// write your code here cpp
#include <iostream>
#include <stack>
using namespace std;

int main()
{
	int n = 0;
	while (cin >> n)
	{
		//stack<char> st;
		stack<int> st;
		while (n--)
		{
			string tmp;
			cin >> tmp;
			if (tmp == "+")
			{
				int right = st.top();
				st.pop();
				int left = st.top();
				st.pop();
				st.push(left + right);
			}
			else if (tmp == "-")
			{
				int right = st.top();
				st.pop();
				int left = st.top();
				st.pop();
				st.push(left - right);
			}
			else if (tmp == "*")
			{
				int right = st.top();
				st.pop();
				int left = st.top();
				st.pop();
				st.push(left * right);
			}
			else if (tmp == "/")
			{
				int right = st.top();
				st.pop();
				int left = st.top();
				st.pop();
				st.push(left / right);
			}
			else
			{
				int num = 0;
				for (int i = 0; i < tmp.size(); i++)
					num = num * 10 + tmp[i] - '0';
				st.push(num);
			}
		}
		cout << st.top() << endl;
	}
	return 0;
}