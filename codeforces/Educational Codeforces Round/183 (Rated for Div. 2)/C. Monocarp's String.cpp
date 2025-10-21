/*
 * @Author: dsaDadas11
 * @Date: 2025-10-10 16:07:15
 * @LastEditTime: 2025-10-10 16:07:23
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
    s=' '+s;
    vector<int> sum(n+1);
    for(int i=1;i<=n;i++)
    {
        sum[i]=sum[i-1]+(s[i]=='a'?1:-1);
    }
    if(sum[n]==0)
    {
        cout<<0<<endl;
        return;
    }
    int ans=n;
    map<int,int> lst;
    lst[0]=0;
    for(int i=1;i<=n;i++)
    {
        if(lst.count(sum[i]-sum[n])) ans=min(ans,i-lst[sum[i]-sum[n]]);
        lst[sum[i]]=i;
    }
    if(ans==n) cout<<-1<<endl;
    else cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}