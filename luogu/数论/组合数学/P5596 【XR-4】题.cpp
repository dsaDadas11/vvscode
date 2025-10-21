/*
 * @Author: dsaDadas11
 * @Date: 2025-09-16 18:01:55
 * @LastEditTime: 2025-09-16 18:02:04
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int a,b;
void solve()
{
    cin>>a>>b;
    if(a*a==4*b)
    {
        cout<<"inf"<<endl;
        return;
    }

    int t=1;
    int ans=0;

    if(b==(int)sqrt(b)*(int)sqrt(b)) ans++;

    while(1)
    {
        int tz=b-t*t;
        int tm=2*t-a;
        if(((tz>0&&tm>0)||(tz<0&&tm<0))&&tz%tm==0) ans++;
        if(tz<0&&tm>0) break;
        t++;
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}