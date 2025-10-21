/*
 * @Author: dsaDadas11
 * @Date: 2025-10-11 19:56:19
 * @LastEditTime: 2025-10-11 19:56:26
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
void solve()
{
    cin>>n;
    map<int,int> mp;
    for(int i=1;i<=n;i++)
    {
        int tmp=i;
        for(int j=2;j*j<=tmp;j++)
        {
            if(tmp%j) continue;
            while(tmp%j==0)
            {
                tmp/=j;
                mp[j]++;
            }
        }
        if(tmp>1) mp[tmp]++;
    }

    for(auto [x,y]:mp) cout<<x<<' '<<y<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}