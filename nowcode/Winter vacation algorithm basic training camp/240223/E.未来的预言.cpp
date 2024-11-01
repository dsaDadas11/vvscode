/*
 * @Author: dsaDadas11
 * @Date: 2024-02-23 16:19:39
 * @LastEditTime: 2024-02-23 16:19:46
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
void solve()
{
	string s; cin>>s;
    string t; cin>>t;
    int x=stoi(s.substr(2));
    int win=x/2+1;
    int len=t.size();
    int r=0,p=0;
    for(int i=0;i<len;i++)
    {
        if(t[i]=='R') r++;
        if(t[i]=='P') p++;
        if(r==win)
        {
            cout<<"kou!"<<endl;
            cout<<i+1<<endl;
            return;
        }
        if(p==win)
        {
            cout<<"yukari!"<<endl;
            cout<<i+1<<endl;
            return;
        }
    }
    cout<<"to be continued."<<endl;
    cout<<len<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}