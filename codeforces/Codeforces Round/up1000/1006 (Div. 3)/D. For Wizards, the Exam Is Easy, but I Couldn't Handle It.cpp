/*
 * @Author: dsaDadas11
 * @Date: 2025-03-11 21:32:51
 * @LastEditTime: 2025-03-11 21:32:59
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
int a[M];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int l=1,r=1,ans=0;
    for(int i=1;i<=n;i++)
    {
        int cnt=0;
        for(int j=i+1;j<=n;j++)
        {
            if(a[i]>a[j]) cnt++;
            else if(a[i]<a[j]) cnt--;
            if(cnt>ans)
            {
                ans=cnt;
                l=i,r=j;
            }
        }
    }
    cout<<l<<' '<<r<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}