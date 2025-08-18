/*
 * @Author: dsaDadas11
 * @Date: 2025-08-03 11:29:39
 * @LastEditTime: 2025-08-03 11:29:46
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
int p[N];
void solve()
{
    cin>>n>>s;
    for(int i=1;i<=n;i++) cin>>p[i];
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        if(p[i]!=i) sum++;
    }
    if(n==2)
    {
        cout<<"Alice"<<endl;
        return;
    }
    if(sum==0)
    {
        cout<<"Alice"<<endl;
        return;
    }
    if(sum==2)
    {
        cout<<s<<endl;
        return;
    }
    if(sum==3&&n==3)
    {
        if(s=="Bob") cout<<"Alice"<<endl;
        else cout<<"Bob"<<endl;
        return;
    }
    cout<<"Bob"<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}