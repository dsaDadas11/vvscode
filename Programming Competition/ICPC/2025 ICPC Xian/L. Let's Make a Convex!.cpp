/*
 * @Author: dsaDadas11
 * @Date: 2025-10-20 11:23:14
 * @LastEditTime: 2025-10-20 12:53:32
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=2e5+7;
constexpr int M=2e3+7;
int n;
int a[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    vector<int> sum(n+5,0);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];

    if(n==1)
    {
        cout<<0<<endl;
        return;
    }
    if(n==2)
    {
        cout<<"0 0"<<endl;
        return;
    }
    cout<<"0 0 ";

    vector<int> ans(n+5,0);
    vector<vector<int> > g(n+5);
    for(int i=1;i<=n;i++)
    {
        // int ans=0;
        // for(int j=i;j<=n;j++)
        // {
        //     if(a[j]<sum[j-1]-sum[j-i]) ans=max(ans,sum[j]-sum[j-i]);
        // }
        // cout<<ans<<' ';

        int l=1,r=i;
        while(l<r)
        {
            int mid=(l+r+1)>>1;
            if(a[i]>=sum[i-1]-sum[i-mid]) l=mid;
            else r=mid-1;
        }
        
        if(l+1<=i) g[l+1].push_back(i);
        // for(int j=l+1;j<=i;j++) ans[j]=max(ans[j],a[i]+sum[i-1]-sum[i-j]);

    }

    // 利用区间性质往后延伸，把时间复杂度降为 O(n+n)
    int maxn=0;
    for(int k=3;k<=n;k++)
    {
        for(auto i:g[k])
        {
            maxn=max(maxn,i);
        }

        if(maxn>=k) ans[k]=sum[maxn]-sum[maxn-k];
    }

    for(int i=3;i<=n;i++)
    {
        cout<<ans[i]<<' ';
    }
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}

/*
当长度为 k时，满足 sum[j-1]-sum[j-k]>a[j]，那么对于 k-1也满足：sum[j-1]-sum[j-(k-1)]>a[j]
当长度为 k时，不满足 sum[j-1]-sum[j-k]>a[j]，那么对于 k-1也不满足：sum[j-1]-sum[j-(k-1)]>a[j]
因此从大到小枚举 k,并且可以根据以上性质线性的变化 j的上界

#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=2e5+7;
constexpr int M=2e3+7;
int n;
int a[N];
void solve()
{
    cin>>n;
    vector<int> sum(n+5),ans(n+5);
    for(int i=1;i<=n;i++) cin>>a[i];

    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];

    int pos=n;
    for(int k=n;k>=3;k--)
    {
        for(int j=pos;j-k>=0;j--)
        {
            if(sum[j-1]-sum[j-k]>a[j])
            {
                ans[k]=sum[j]-sum[j-k];
                pos=j;
                break;
            }
        }
    }

    for(int i=1;i<=n;i++) cout<<ans[i]<<' ';
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}
*/