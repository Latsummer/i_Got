#include <iostream>
#include <queue>
#include <string>
using namespace std;
//
////int get_secound(int k1, int k2, int k3)
////{
////    if(k1 >= k2 && k1 <= k3)
////        return k1;
////    if(k2 >= k1 && k2 <= k3)
////        return k2;
////    if(k3 >= k1 && k3 <= k2)
////        return k3;
////}
////
////int main()
////{
////    int team = 0;
////    stack<int> st;
////    int ret = 0;
////    cin >> team;
////    for(int i = 0; i < 3 * team; i++)
////    {
////        int tmp;
////        cin >> tmp;
////        st.push(tmp);
////    }
////    
////    while(!st.empty())
////    {
////        int k1 = st.top();
////        st.pop();
////        int k2 = st.top();
////        st.pop();
////        int k3 = st.top();
////        st.pop();
////        
////        int after_Max = get_secound(k1, k2, k3);
////        ret += after_Max;
////    }
////    
////	cout << ret;
////    return 0;
////}
//
//
//int main()
//{
//    int team = 0;
//    cin >> team;
//    priority_queue<int> pq;
//    for(int i = 0; i < 3 * team; i++)
//    {
//        int tmp;
//        cin >> tmp;
//        pq.push(tmp);
//    }
//	pq.push(0);
//    
//    //for(int i = 0; i < team; i++)
//    //{
//     //   pq.pop();
//    //}
//    int ret = 0;
//    for(int i = 0; i < team; i++)
//    {
//        pq.pop();
//        ret += pq.top();
//        pq.pop();
//    }
//    cout << ret;
//    return 0;
//}


//int main()
//{
//    int team = 0;
//    cin >> team;
//    priority_queue<int> pq;
//    for(int i = 0; i < 3 * team; i++)
//    {
//        int tmp;
//        cin >> tmp;
//        pq.push(tmp);
//    }
//    
//    //for(int i = 0; i < team; i++)
//    //{
//     //   pq.pop();
//    //}
//    long long ret = 0;
//    for(int i = 0; i < team; i++)
//    {
//		  pq.pop();
//        ret += pq.top();
//        pq.pop();
//    }
//    cout << ret;
//    return 0;
//}

//
//int main()
//{
//    string s1;
//    string cut;
//    getline(cin, s1);
//    getline(cin, cut);
//    
//    string::iterator cut_it = cut.begin();
//    while(cut_it != cut.end())
//    {
//        string::iterator s1_it = s1.begin();
//        while(s1_it != s1.end())
//        {
//            if((*cut_it) == *(s1_it))
//                s1.erase(s1_it);
//            s1_it++;
//        }
//        cut_it++;
//    }
//    
//	s1.erase(0);
//    
//    cout << s1;
//    return 0;
//}


int main()
{
    string s1;
    string cut;
    getline(cin, s1);
    getline(cin, cut);
    int Hash[256] = { 0 };
    
    for(int i = 0; i < cut.size(); i++)
    {
        Hash[cut[i]] = 1;
    }
	string::iterator it = s1.begin();
	while (it != s1.end())
	{
		if (Hash[*it] == 1)
		{
			s1.erase(it);
			continue;
		}
		it++;
	}
    /*for(int i = 0; i  < s1.size(); i++)
    {
        if(Hash[s1[i]] == 1)
            s1.erase(i);
    }*/
    /*string::iterator cut_it = cut.begin();
    while(cut_it != cut.end() && !s1.empty() && !cut.empty())
    {
        string::iterator s1_it = s1.begin();
        while(s1_it != s1.end())
        {
            if((*cut_it) == *(s1_it))
                s1.erase(s1_it), continue;
            s1_it++;
        }
        cut_it++;
    }*/
    
    /*for(int i = 0; i < cut.size(); i++)
    {
        for(int j = 0; j < s1.size(); j++)
        {
            if(cut[i] == s1[j])
                s1.erase(j);
        }
    }*/
    
    cout << s1;
    return 0;
}