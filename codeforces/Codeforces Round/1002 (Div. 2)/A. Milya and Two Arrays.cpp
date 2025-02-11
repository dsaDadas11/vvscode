/*
 * @Author: dsaDadas11
 * @Date: 2025-02-03 19:42:35
 * @LastEditTime: 2025-02-03 19:42:42
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,x;
void solve()
{
    cin>>n;
    set<int> s1,s2;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        s1.insert(x);
    }
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        s2.insert(x);
    }
    if(s1.size()+s2.size()>=4) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}