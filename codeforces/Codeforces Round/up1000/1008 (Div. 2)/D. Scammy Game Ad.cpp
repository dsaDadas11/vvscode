/*
 * @Author: dsaDadas11
 * @Date: 2025-03-30 10:48:42
 * @LastEditTime: 2025-03-30 10:48:52
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
int f[40][2],a[40][2];
char ch[40][2];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>ch[i][0]>>a[i][0];
        cin>>ch[i][1]>>a[i][1];
    }
    f[n+1][0]=f[n+1][1]=1;
    for(int i=n;i>=1;i--)
    {
        for(int j=0;j<=1;j++)
        {
            if(ch[i][j]=='+') f[i][j]=f[i+1][j];
            else f[i][j]=f[i+1][j]+(a[i][j]-1)*max(f[i+1][0],f[i+1][1]);
        }
    }
    int l=1,r=1,cnt=0;
    for(int i=1;i<=n;i++)
    {
        cnt=0;
        if(ch[i][0]=='+') cnt+=a[i][0];
        else cnt+=l*(a[i][0]-1);

        if(ch[i][1]=='+') cnt+=a[i][1];
        else cnt+=r*(a[i][1]-1);

        if(f[i+1][0]>f[i+1][1]) l+=cnt;
        else r+=cnt;
    }
    cout<<l+r<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}