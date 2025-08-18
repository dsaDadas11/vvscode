/*
 * @Author: dsaDadas11
 * @Date: 2025-08-06 09:45:58
 * @LastEditTime: 2025-08-06 09:46:08
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int w,h,a,b;
void solve()
{
    int x1,y1,x2,y2;
    cin>>w>>h>>a>>b;
    cin>>x1>>y1>>x2>>y2;

    if(x1==x2)
    {
        if(abs(y1-y2)%b) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
        return;
    }

    if(y1==y2)
    {
        if(abs(x1-x2)%a) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
        return;
    }

    if((x1-x2)%a&&(y1-y2)%b) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}