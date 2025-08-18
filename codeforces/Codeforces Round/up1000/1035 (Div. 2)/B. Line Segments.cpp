/*
 * @Author: dsaDadas11
 * @Date: 2025-08-09 16:33:09
 * @LastEditTime: 2025-08-09 16:33:16
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
int px,py,qx,qy;
double a[N];
void solve()
{
    cin>>n;
    cin>>px>>py>>qx>>qy;
    for(int i=1;i<=n;i++) cin>>a[i];
    a[++n]=sqrt((px-qx)*(px-qx)+(py-qy)*(py-qy));
    sort(a+1,a+1+n);
    double sum=a[n];
    for(int i=1;i<n;i++) sum-=a[i];
    if(sum<=0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}