/*
 * @Author: dsaDadas11
 * @Date: 2025-07-16 19:01:38
 * @LastEditTime: 2025-07-17 21:46:39
 * @Description: go for it!
 */
/*
 解题思路：
 只需要 a[i]<=[1,i-1]最小值 或者 a[i]>=[i+1,n]的最大值
 那么最后变为三个数时一定可以将另外两个数消掉
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
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
    vector<int> pre(n+2); // min
    vector<int> suf(n+2); // max
    pre[0]=1e9,suf[n+1]=0;
    for(int i=1;i<=n;i++)
    {
        pre[i]=min(pre[i-1],a[i]);
    }
    for(int i=n;i>=1;i--)
    {
        suf[i]=max(suf[i+1],a[i]);
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]<=pre[i]||a[i]>=suf[i]) cout<<1;
        else cout<<0;
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
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
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
    vector<int> pre(n+2); // min
    vector<int> suf(n+2); // max
    pre[0]=1e9,suf[n+1]=0;
    for(int i=1;i<=n;i++)
    {
        pre[i]=min(pre[i-1],a[i]);
    }
    for(int i=n;i>=1;i--)
    {
        suf[i]=max(suf[i+1],a[i]);
    }
    for(int i=1;i<=n;i++)
    {
        bool flag=0;
        int minn=0,maxn=0;
        pre[0]=0,suf[n+1]=0;
        // 1
        minn=pre[i];
        maxn=max(minn,suf[i+1]);
        if(maxn==a[i]) flag=1;

        // 2
        minn=pre[i-1];
        maxn=max(minn,suf[i]);
        if(maxn==a[i]) flag=1;

        pre[0]=1e9,suf[n+1]=1e9;
        // 3
        maxn=suf[i];
        minn=min(maxn,pre[i-1]);
        if(minn==a[i]) flag=1;

        // 4
        maxn=suf[i+1];
        minn=min(maxn,pre[i]);
        if(minn==a[i]) flag=1;

        if(flag) cout<<"1";
        else cout<<"0";
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
*/