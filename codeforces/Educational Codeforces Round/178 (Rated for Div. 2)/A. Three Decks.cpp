/*
 * @Author: dsaDadas11
 * @Date: 2025-05-05 11:27:19
 * @LastEditTime: 2025-05-05 11:27:28
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int a,b,c;
void solve()
{
    cin>>a>>b>>c;
    if((a+b+c)%3)
    {
        cout<<"NO"<<endl;
        return;
    }
    int sum=(a+b+c)/3;
    if(a>sum||b>sum) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}