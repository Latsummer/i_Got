#include <iostream>
#include <vector>
#include <string>
using namespace std;

//int main()
//{
//	/*vector<int> arr;
//	arr.push_back(1);
//	arr.push_back(1);
//	arr.push_back(1);
//	
//	cout << arr.size() << endl;*/
//	/*string str("1234");
//	cout << str.size() << endl;*/
//	int a = 20;
//	if (a == 20) {
//		cout << 1 << endl;
//	}
//	else if (a > 0) {
//		cout << 2 << endl;
//	}
//	return 0;
//}

bool checkWon(vector<vector<int> > board) {
	// write code here
	/*int row = board.size();
	int col = row;
	for(int i = 0; i < row; i++)
	{
		if(board[i][0] == board[i][1] && board[i][1] == board[i][2])
		{
			if(board[i][0] == 1)
				return true;
			else if(board[i][0] == -1)
				return false;
			else
				continue;
		}
	}
	for(int i = 0; i < col; i++)
	{
		if(board[0][i] == board[1][i] && board[1][i] == board[2][i])
		{
			if(board[0][i] == 1)
				return true;
			else if(board[0][i] == -1)
				return false;
			else
				continue;
		}
	}
	if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
	{
		if(board[0][0] == 1)
				return true;
			else if(board[0][0] == -1)
				return false;
	}
	if(board[0][2] == board[1][1] && board[1][1] == board[2][2])
	{
		if(board[0][0] == 1)
				return true;
			else if(board[0][0] == -1)
				return false;
	}*/

	int row = board.size();
	for (int i = 0; i < row; i++)
	{
		int sum_row = 0;
		int sum_col = 0;
		for (int j = 0; j < row; j++)
		{
			sum_row += board[i][j];
			sum_col += board[j][i];
		}
		if (sum_row == row)
			return true;
		if (sum_col == row)
			return true;
	}

	int left = 0;
	int right = 0;
	for (int i = 0; i < row; i++)
	{
		left += board[i][i];
		right += board[i][row - 1 - i];
	}
	if (left == row)
		return true;
	if (right == row)
		return true;
	return false;
}
};

int length(string& str)
{
	int len = str.length();
	if (len <= 4)
		return 5;
	if (len > 4 && len <= 7)
		return 10;
	return 25;
}

int letter(string& str)
{
	int small = 0;
	int big = 0;
	string::iterator it = str.begin();
	while (it != str.end())
	{
		if (*it >= 'a' && *it <= 'z')
			small = 1;
		if (*it >= 'A' && *it <= 'Z')
			big = 1;
		it++;
	}
	if (small == 0 && big == 0)
		return 0;
	if (small == 1 && big == 1)
		return 20;
	return 10;

}

int nums(string& str)
{
	int num = 0;
	string::iterator it = str.begin();
	while (it != str.end())
	{
		if (*it >= '0' && *it <= '9')
			num++;
		it++;
	}
	if (num == 0)
		return 0;
	if (num == 1)
		return 10;
	return 20;
}

int sign(string& str)
{
	int num = 0;
	string::iterator it = str.begin();
	while (it != str.end())
	{
		if (*it >= '!' && *it <= '/')
			num++;
		if (*it >= ':' && *it <= '@')
			num++;
		if (*it >= '{' && *it <= '~')
			num++;
		it++;
	}
	if (num == 0)
		return 0;
	if (num == 1)
		return 10;
	return 25;
}

int main()
{
	string Password;
	cin >> Password;
	int mark = 0;//分数
	int len_mark = length(Password);//长度
	int let_mark = letter(Password);//字母
	int num_mark = nums(Password);//数字
	int sig_mark = sign(Password);//符号
	if (let_mark == 20 && num_mark > 0 && sig_mark > 0) {
		mark += 5;
	}
	else if (let_mark > 0 && num_mark > 0 && sig_mark > 0) {
		mark += 3;
	}
	else if (let_mark > 0 && num_mark > 0) {
		mark += 2;
	}
	mark = mark + len_mark + let_mark + num_mark + sig_mark;
	if (mark >= 90) {
		cout << "VERY_SECURE" << endl;
	}
	else if (mark >= 80) {
		cout << "SECURE" << endl;
	}
	else if (mark >= 70) {
		cout << "VERY_STRONG" << endl;
	}
	else if (mark >= 60) {
		cout << "STRONG" << endl;
	}
	else if (mark >= 50) {
		cout << "AVERAGE" << endl;
	}
	else if (mark >= 25) {
		cout << "WEAK" << endl;
	}
	else if (mark >= 0) {
		cout << "VERY_WEAK" << endl;
	}
	return 0;
}