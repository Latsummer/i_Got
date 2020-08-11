// write your code here cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<char> > Map(21, vector<char>(21));

int cnt = 1;

void DFS(int i, int j)
{
	Map[i][j] = 'X';
	if (Map[i + 1][j] == '.')
	{
		cnt++;
		DFS(i + 1, j);
	}
	if (Map[i - 1][j] == '.')
	{
		cnt++;
		DFS(i - 1, j);
	}
	if (Map[i][j + 1] == '.')
	{
		cnt++;
		DFS(i, j + 1);
	}
	if (Map[i][j - 1] == '.')
	{
		cnt++;
		DFS(i, j - 1);
	}
	return;
}

int main()
{
	int m, n;
	while (cin >> m >> n)
	{
		Map.clear();
		for (int i = 0; i < Map.size(); i++)
			Map[i].clear();

		Map.resize(m + 2);
		for (int i = 0; i < Map.size(); i++)
			Map[i].resize(n + 2);
		cnt = 1;
		vector<string> input;
		input.resize(m);
		int is, js;
		for (int i = 1; i <= m; i++)
		{
			string input;
			cin >> input;
			//input.push_back(tmp);
			for (int j = 0; j < n; j++)
			{
				if (input[j] == '@')
				{
					is = i;
					js = j;
				}
				Map[i][j] = input[j];
			}
		}
		DFS(is, js);
		cout << cnt << endl;
	}
	return 0;
}


#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N, M, K;
	while (cin >> M >> N >> K)
	{
		vector<vector<int> > Map(M + 1, vector<int>(N + 1, 0));
		vector<vector<double> > ret(M + 1, vector<double>(N + 1));

		for (int i = 0; i < K; i++)
		{
			int x, y;
			cin >> x >> y;
			Map[x][y]++;
		}
		ret[1][1] = 1.0;
		for (int i = 1; i < M + 1; i++)
		{
			for (int j = 1; j < N + 1; j++)
			{
				if (Map[i][j] > 0)
				{
					ret[i][j] = 0;
					continue;
				}
				if (!(i == 1 && j == 1))
					ret[i][j] = ret[i - 1][j] * (j == N ? 1.0 : 0.5) + ret[i][j - 1] * (i == M ? 1.0 : 0.5);
			}
		}
		printf("%.2f\n", ret[M][N]);
	}
	return 0;
}