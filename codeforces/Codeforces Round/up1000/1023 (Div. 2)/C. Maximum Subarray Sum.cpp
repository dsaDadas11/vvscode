/*
 * @Author: dsaDadas11
 * @Date: 2025-05-22 21:24:09
 * @LastEditTime: 2025-05-22 21:24:16
 * @Description: go for it!
 */
/*
 解题思路：
 先将 0赋成 -inf
 在两个 0之间的 0可以改变大小使两个 0之间的区间和最大值为 k，用二分解决
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
constexpr int inf=1e18;
int n,k;
int a[N];
string s;
int check(int l,int r)
{
    int sum=0,mx=0;
    for(int i=l;i<=r;i++)
    {
        sum=max(0LL,sum+a[i]);
        mx=max(mx,sum);
    }
    return mx;
}
void solve()
{
    cin>>n>>k;
    cin>>s;
    s=' '+s;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='0') a[i]=-inf;
    }
    
    if(check(1,n)==k)
    {
        cout<<"Yes"<<endl;
        for(int j=1;j<=n;j++) cout<<a[j]<<' ';
        cout<<endl;
        return;
    }

    int sum=0;
    for(int i=1;i<=n;i++)
    {
        sum=max(0LL,a[i]+sum);
        if(sum>k) return cout<<"No"<<endl,void();
    }

    vector<int> pos;
    pos.push_back(0);
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='0') pos.push_back(i);
    }
    pos.push_back(n+1);
    
    for(int i=1;i<pos.size()-1;i++)
    {
        int l=pos[i-1]+1,r=pos[i+1]-1;
        int lo=-inf,hi=inf;
        while(lo<hi)
        {
            int mid=(lo+hi)>>1LL;
            a[pos[i]]=mid;
            if(check(l,r)>=k) hi=mid;
            else lo=mid+1;
        }
        a[pos[i]]=lo;
        if(check(l,r)==k)
        {
            cout<<"Yes"<<endl;
            for(int j=1;j<=n;j++) cout<<a[j]<<' ';
            cout<<endl;
            return;
        }
        a[i]=-inf;
    }
    cout<<"No"<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}