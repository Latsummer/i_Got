#include <iostream>
#include <string>
using namespace std;

//int main()
//{
//	int n = 0;
//	cin >> n;
//	int ret = 0;
//	int bott = 0;//能换几瓶
//	int step = 0;//余下来的空瓶
//	while (1)
//	{
//		bott = n / 3;
//		step = n % 3;
//		ret += bott;
//		n = bott + step;
//		if (n == 2)
//			n++;
//		if (n < 2)
//			break;
//	}
//	cout << ret << endl;
//	return 0;
//}
//
//int main()
//{
//	string a("aaa");
//	string b("bbb");
//	swap(a, b);
//	cout << a << b;
//	return 0;
//}

int main()
{
    string duan("abcdefghigklmnop");
    string chang("abcsafjklmnopqrstuvw");
    //while(cin >> duan >> chang){
    if(duan.size() > chang.size())
    {
        swap(duan, chang);
        /*string tmp = duan;
        duan = chang;
        chang = tmp;*/
    }
    //size_t changs = chang.size(), duans = duan.size();
    size_t max = 0, maxIdx = 0;
    for(size_t i = duan.size() - 1; i > 1; i--)
    {
        for(size_t j = 0; j <= duan.size() - i; j++)
        {
            string tmp;
            int t = 0;
            tmp = duan.substr(j, i);
            t = chang.find(tmp);
            if((t != -1) && max < tmp.size())
            {
                max = tmp.size();
                maxIdx = i + j;
            }
        }
    }
    cout << duan.substr(maxIdx - max, max) << endl;//}
    return 0;
}