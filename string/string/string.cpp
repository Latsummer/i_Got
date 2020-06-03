#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
using namespace std;

void test1()
{

    string s;
    while(getline(cin, s))
    {
        int count[256] = { 0 };
        int size = s.size();
        int i = 0;
    
        for(i = 0; i < size; i++)
            count[s[i]] += 1;
    
        for(i = 0; i < size; i++)
        {
            if(count[s[i]] == 1)
            {
                cout << s[i] << endl;
                break;
            }
        }
        if(i == size)
            cout << -1 << endl;
    }
}

string test2()
{
	string num1("0");
	if (num1 == "0")
		return "0";
}


int StrToInt(string str) {
    int size = str.size();
    if(size == 0)
        return 0;
    int flag = 1;
    int ret = 0;
    int cur = 0;
        
    while(str[cur] == ' ')
        cur++;
    if(str[cur] == '+')
        cur++;
    else if(str[cur] == '-')
    {
        flag = -1;
        cur++;
    }
    while(cur < size)
    {
        if(str[cur] >= '0' && str[cur] <= '9')
            ret = ret * 10 + (str[cur++] - '0');
        else
        {
            ret = 0;
            break;
        }
    }
    ret *= flag;
    return ret;
}

int main()
{
	//test2();
	/*cout << test2() << endl;
	int i = 49 / 10;
	cout << i << endl;*/
	string str("-2147483649");
	int ret = StrToInt(str);
    return 0;
}