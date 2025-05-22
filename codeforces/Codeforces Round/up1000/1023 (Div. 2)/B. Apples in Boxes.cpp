/*
 * @Author: dsaDadas11
 * @Date: 2025-05-21 19:25:00
 * @LastEditTime: 2025-05-21 19:25:07
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,k;
int a[N];
void solve()
{
    cin>>n>>k;
    int minn=1e16,maxn=0;
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        minn=min(minn,a[i]);
        maxn=max(maxn,a[i]);
        sum+=a[i];
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==maxn) cnt++;
    }
    if(maxn-minn>k+1||(maxn-minn>k&&cnt>1)||sum%2==0)
    {
        cout<<"Jerry"<<endl;
    }
    else cout<<"Tom"<<endl;
    
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}