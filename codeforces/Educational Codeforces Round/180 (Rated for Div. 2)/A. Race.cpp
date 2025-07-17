/*
 * @Author: dsaDadas11
 * @Date: 2025-07-17 15:27:14
 * @LastEditTime: 2025-07-17 15:27:23
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int a,x,y;
void solve()
{
    cin>>a>>x>>y;
    int ax=abs(x-a),ay=abs(y-a);
    for(int i=0;i<=200;i++)
    {
        int bx=abs(x-i),by=abs(y-i);
        if(bx<ax&&by<ay)
        {
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}