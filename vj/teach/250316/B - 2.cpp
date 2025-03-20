/*
 * @Author: dsaDadas11
 * @Date: 2025-03-16 20:50:28
 * @LastEditTime: 2025-03-16 20:50:37
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,d;
int a[N];
void solve()
{
    cin>>n>>d;
    multiset<int> se;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    sort(a+1,a+1+n);

    for(int i=1;i<=n;i++)
    {
        se.insert(a[i]-a[i-1]-1);
    }

    int ans=0;
    for(int i=1;i<=n;i++)
    {
       se.erase(se.find(a[i]-a[i-1]-1));

       int len=d-a[n]-1;

        if(i!=n)
        {
            se.erase(se.find(a[i+1]-a[i]-1));
            se.insert(a[i+1]-a[i-1]-1);
        }
        else len=d-a[n-1]-1;

        int res=*se.begin();
        int mx=*se.rbegin();

        res=min(res,max((mx-1)/2,len));
        ans=max(ans,res);

        if(i!=n)
        {
            se.erase(se.find(a[i+1]-a[i-1]-1));
            se.insert(a[i+1]-a[i]-1);
        }
        se.insert(a[i]-a[i-1]-1);

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