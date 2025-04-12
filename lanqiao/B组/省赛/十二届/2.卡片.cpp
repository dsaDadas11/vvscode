/*
 * @Author: dsaDadas11
 * @Date: 2025-04-10 16:07:22
 * @LastEditTime: 2025-04-10 16:07:29
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        if(i*(i+1)/2>=n)
        {
            cout<<i<<endl;
            return;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}