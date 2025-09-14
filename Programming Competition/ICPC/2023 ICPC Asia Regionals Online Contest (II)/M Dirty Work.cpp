/*
 * @Author: dsaDadas11
 * @Date: 2025-09-11 20:02:24
 * @LastEditTime: 2025-09-11 20:02:33
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e4+7;
constexpr int M=2e3+7;
int n;
int a,b;
double p;
void solve()
{
    cin>>n;
    vector<double> v;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b>>p;
        double tmp=1.0*a*(1.0-p)+1.0*(a+b)*p;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end());
    double sum=0,ans=0;
    for(int i=0;i<n;i++)
    {
        sum+=v[i];
        ans+=sum;
    }
    cout<<fixed<<setprecision(10)<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}