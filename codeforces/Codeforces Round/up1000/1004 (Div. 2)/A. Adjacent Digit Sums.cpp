/*
 * @Author: HuangCe
 * @Date: 2025-02-13 17:12:44
 * @LastEditTime: 2025-02-13 17:12:53
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int x,y;
void solve()
{
    cin>>x>>y;
    if((x+1-y)%9==0&&(x+1-y)>=0) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}