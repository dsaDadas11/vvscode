/*
 * @Author: dsaDadas11
 * @Date: 2025-08-21 16:28:39
 * @LastEditTime: 2025-08-21 16:28:47
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
int p[N],d[N];
int s[N];
bool ok[N];
int q[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>p[i]>>d[i];
        p[i+n]=p[i],d[i+n]=d[i];
    }
    p[0]=p[n],d[0]=d[n];

    // 顺时针
    for(int i=1;i<=2*n;i++)
    {
        s[i]=p[i]-d[i];
        s[i]+=s[i-1];
    }
    int h=1,t=0;
    for(int i=2*n;i>=1;i--)
    {
        while(h<=t&&s[q[t]]>=s[i]) t--;
        q[++t]=i;
        if(q[h]>i+n-1) h++;
        if(i<=n&&s[q[h]]-s[i-1]>=0) ok[i]=1;
    }

    // 逆时针
    for(int i=2*n;i>=1;i--)
    {
        s[i]=p[i]-d[i-1];
        s[i]+=s[i+1];
    }
    h=1,t=0,q[0]=0;
    for(int i=1;i<=2*n;i++)
    {
        while(h<=t&&s[q[t]]>=s[i]) t--;
        q[++t]=i;
        if(q[h]<i-n+1) h++;
        if(i>n&&s[q[h]]-s[i+1]>=0) ok[i-n]=1;
    }

    for(int i=1;i<=n;i++) cout<<(ok[i]?"TAK":"NIE")<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}