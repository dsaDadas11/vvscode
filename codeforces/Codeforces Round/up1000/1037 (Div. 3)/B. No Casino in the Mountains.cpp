/*
 * @Author: dsaDadas11
 * @Date: 2025-07-28 16:03:58
 * @LastEditTime: 2025-07-28 16:04:13
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
    for(int i=1;i<=n;i++) cin>>a[i];
    int ans=0;
    vector<int> d;
    int lst=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i])
        {
            d.push_back(i-lst+1-2);
            lst=i;
        }
    }
    if(lst!=n) d.push_back(n+1-lst+1-2);
    for(int i=0;i<d.size();i++)
    {
        int cnt=0;
        for(int j=1;j<=d[i];j++)
        {
            cnt++;
            if(cnt==k)
            {
                ans++;
                cnt=0;
                j++;
            }
        }
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}