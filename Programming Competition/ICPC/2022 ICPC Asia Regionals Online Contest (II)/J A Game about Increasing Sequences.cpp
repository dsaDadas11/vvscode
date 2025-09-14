/*
 * @Author: dsaDadas11
 * @Date: 2025-09-11 16:01:14
 * @LastEditTime: 2025-09-11 16:01:20
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
int a[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int pre=1,suf=1;
    for(int i=1;i<n;i++)
    {
        if(a[i]<a[i+1]) pre++;
        else break;
    }
    for(int i=n;i>1;i--)
    {
        if(a[i]<a[i-1]) suf++;
        else break;
    }

    if((pre&1)||(suf&1)) cout<<"Alice"<<endl;
    else cout<<"Bob"<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}