#include <iostream>
using namespace std;

#define SQR(A) A*A;

void func(const int& v1, const int& v2)
{
	cout << v1 << " ";
	cout << v2 << " ";
}

struct st {
	uint16_t id;
	uint32_t value;
	uint64_t time;
};

int binInsert(int n, int m, int j, int i)
{
	m <<= j;
	return n | m;
}

//int main()
//{
//	int x = 6, y = 3, z = 2;
//	x /= SQR(y + z)+SQR(y + z);
//	cout << x << endl;
//	//int i = 0; 
//	//func(++i, i++);
//	//cout << sizeof(uint16_t) << endl;
//	//st task = { };
//	//uint64_t a = 0x00010001;
//	//memcpy(&task, &a, sizeof(uint64_t));
//	//printf("%llu, %llu, %llu", task.id, task.value, task.time);
//}


bool is_sushu(int a)
{
	for (int i = 2; i < a; i++)
	{
		if (a % i == 0)
			return false;
	}
	return true;
}

int main()
{
	int input = 0;
	while (cin >> input) {
		int left = input / 2;
		int right = input / 2;
		while (left > 0)
		{
			if (is_sushu(left) && is_sushu(right))
				break;
			left--;
			right++;
		}
		cout << left << endl << right << endl;
	}
	return 0;
}