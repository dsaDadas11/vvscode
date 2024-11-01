/*
 * @Author: dsaDadas11
 * @Date: 2024-02-23 18:40:03
 * @LastEditTime: 2024-02-23 18:40:10
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int a[N],b[N],sa[N],sa2[N],sb[N],sb2[N];
void solve()
{
	int n,m; cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>b[i];
    int mxa=-1e18;
    int mia=1e18;
    for(int i=1;i<=n;i++)
    {
        sa[i]=max(a[i],sa[i-1]+a[i]);
        sa2[i]=min(a[i],sa2[i-1]+a[i]);
        mxa=max(mxa,sa[i]);
        mia=min(mia,sa2[i]);
    }
    int mxb=-1e18;
    int mib=1e18;
    for(int i=1;i<=m;i++)
    {
        sb[i]=max(b[i],sb[i-1]+b[i]);
        sb2[i]=min(b[i],sb2[i-1]+b[i]);
        mxb=max(mxb,sb[i]);
        mib=min(mib,sb2[i]);
    }
    cout<<max({mxa*mxb,mia*mib,mia*mxb,mib*mxa})<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}