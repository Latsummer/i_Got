#include <iostream>
#include <vector>
using namespace std;

int getFirstUnFormedNum(vector<int> arr, int len) 
{
    int min = arr[0];
    int max = arr[0];
    for(int i = 1; i < len; i++)
    {
        max += arr[i];
        if(arr[i] < min)
            min = arr[i];
    }
    vector<bool> ret(max + 1, false);
    //ret.resize(max + 1);
    ret[0] = true;
    for(int i = 0; i < len; i++)
    {
        for(int j = max; j >= arr[i]; j--)
        {
            //ret[j] = ret[j - arr[i]] ? true : ret[j];
            if(ret[j - arr[i]])
                ret[j] = true;
        }
    }
    for(int i = min; i < ret.size(); i++)
    {
        if(ret[i] == false)
            return i;
    }
    return max + 1;
}

//int main()
//{
//	vector<int> a = { 3, 2, 5 };
//	getFirstUnFormedNum(a, a.size());
//	return 0;
//}

int main()
{
	size_t n = 0;
	while (cin >> n)
	{
		if (n == 0)
			break;
		size_t count = 0;
		while (n >= 2)
		{
			if (n % 3)
				n = n / 3 + 1;
			else
				n /= 3;
			count++;
		}
		cout << count << endl;
	}
}