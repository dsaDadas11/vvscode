/*
 * @Author: dsaDadas11
 * @Date: 2025-03-07 18:32:58
 * @LastEditTime: 2025-03-07 18:33:13
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
string s;
void solve()
{
    cin>>n;
    cin>>s;
    string t;
    bool flag=0;
    for(int i=1;i<=n;i++)
    {
        cin>>t;
        if(t==s)
        {
            flag=1;
            cout<<i<<endl;
        }
    }
    if(!flag)cout<<"-1"<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}