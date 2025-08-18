/*
 * @Author: dsaDadas11
 * @Date: 2025-08-08 20:49:40
 * @LastEditTime: 2025-08-08 20:49:48
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,maxn;
int a[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        maxn=max(maxn,a[i]);
    }

    vector<int> cnt(maxn+1),gg(maxn+1),mxgcd(n+1);
    for(int i=1;i<=n;i++) cnt[a[i]]++;

    if(cnt[0]==n)
    {
        for(int i=1;i<=n;i++) cout<<1<<' ';
        cout<<endl;
        return;
    }

    for(int i=1;i<=maxn;i++)
    {
        for(int j=i;j<=maxn;j+=i)
        {
            gg[i]+=cnt[j];
        }
    }
    
    int mex=0;
    while(cnt[mex]) mex++;

    int p=1;
    for(int i=maxn;i>=1;i--)
    {
        if(gg[i]>=p)
        {
            for(;p<=gg[i]&&p<=n;p++)
            {
                mxgcd[p]=i;
            }
        }
    }

    vector<int> ans(n+1);
    for(int i=1;i<=n;i++)
    {
        // mex=0
        if(n-cnt[0]>=i)
        {
            ans[i]=max(ans[i],mxgcd[i]);
        }

        // mex=1  (i=1时gcd=0,因此 i>=2才有意义)
        if(i>=2&&cnt[0]&&n-cnt[1]>=i)
        {
            int j=max(1LL,i-cnt[0]);
            ans[i]=max(ans[i],mxgcd[j]^1);
            if(gg[mxgcd[j]-1]>=j)
            {
                ans[i]=max(ans[i],(mxgcd[j]-1)^1);
            }
        }

        // mex>=2
        if(i>=2&&cnt[0]&&cnt[1])
        {
            int j=(i>mex?mex:i);
            ans[i]=max(ans[i],j^1);
            if(n-cnt[j-1]>=i) ans[i]=max(ans[i],(j-1)^1);
        }
    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<' ';
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}