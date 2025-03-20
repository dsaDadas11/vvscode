/*
 * @Author: dsaDadas11
 * @Date: 2025-03-11 21:07:17
 * @LastEditTime: 2025-03-11 21:07:32
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,x;
void solve()
{
    cin>>n>>x;
    int res=0;
    // 先处理 n-1个数
    for(int i=0;i<n-1;i++)
    {
        if((i|x)==x)
        {
            cout<<i<<' ';
            res|=i;
        }
        else cout<<"0"<<' ';
    }
    // 特判最后一个数
    if((res|(n-1))==x) cout<<n-1<<endl;
    else cout<<(x^res)<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}