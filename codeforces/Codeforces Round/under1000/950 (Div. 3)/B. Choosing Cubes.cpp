/*
 * @Author: dsaDadas11
 * @Date: 2024-10-08 21:18:59
 * @LastEditTime: 2024-10-08 21:19:05
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,f,k;
int a[M];
void solve()
{
    cin>>n>>f>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    int val=a[f];
    sort(a+1,a+1+n,greater<>());
    bool f1=0,f2=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==val)
        {
            if(i<=k) f1=1;
            else f2=1;
        }
    }
    if(f1&&f2) cout<<"MAYBE"<<endl;
    else if(f2) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}