/*
 * @Author: dsaDadas11
 * @Date: 2025-05-21 18:55:59
 * @LastEditTime: 2025-05-21 18:56:14
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
int a[107];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        int ga=a[i];
        int gb=0;
        for(int j=1;j<=n;j++)
        {
            if(j==i) continue;
            if(gb==0) gb=a[j];
            else gb=gcd(gb,a[j]);
        }
        if(ga!=gb)
        {
            cout<<"Yes"<<endl;
            for(int j=1;j<i;j++) cout<<"2 ";
            cout<<"1 ";
            for(int j=i+1;j<=n;j++) cout<<"2 ";
            cout<<endl;
            return;
        }
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