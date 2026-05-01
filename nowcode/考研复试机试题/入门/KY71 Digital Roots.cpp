/*
 * @Author: dsaDadas11
 * @Date: 2026-01-20 11:13:04
 * @LastEditTime: 2026-01-20 11:13:11
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int sum;
void solve()
{
    while(sum>=10)
    {
        int tmp=sum;
        int ds=0;
        while(tmp)
        {
            ds+=tmp%10;
            tmp/=10;
        }
        sum=ds;
    }
    cout<<sum<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(cin>>sum){solve();}
    return 0;
}