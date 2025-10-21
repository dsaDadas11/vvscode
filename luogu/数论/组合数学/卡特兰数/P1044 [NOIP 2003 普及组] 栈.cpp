/*
 * @Author: dsaDadas11
 * @Date: 2025-09-17 21:48:30
 * @LastEditTime: 2025-09-17 21:48:39
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
int h[19];
void solve()
{
    cin>>n;
    h[0]=1;
    for(int i=1;i<=n;i++)
    {
        h[i]=h[i-1]*(4*i-2)/(i+1);
    }
    cout<<h[n]<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}