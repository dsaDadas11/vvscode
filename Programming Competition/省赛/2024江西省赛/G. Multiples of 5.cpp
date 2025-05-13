/*
 * @Author: dsaDadas11
 * @Date: 2025-04-21 15:00:18
 * @LastEditTime: 2025-04-21 15:00:25
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
void solve()
{
    cin>>n;
    int sum=0;
    int a,c;
    char b;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b;
        if(b=='A') c=10;
        else c=b-'0';
        sum+=a*c;
    }
    if(sum%5==0) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}