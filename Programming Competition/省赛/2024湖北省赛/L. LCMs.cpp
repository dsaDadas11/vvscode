/*
 * @Author: dsaDadas11
 * @Date: 2025-05-02 21:44:03
 * @LastEditTime: 2025-05-02 21:45:55
 * @Description: go for it!
 */
/*
 先特判 a==b, b%a==0, gcd(a,b)>1 情况
 然后设 p为 a的质因子，q为 b的质因子，再加上一个 2
 a p 2 q b 跑最短路
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
    if(a==b) return cout<<"0"<<endl,void();
    if(a>b) swap(a,b);
    if(b%a==0) return cout<<b<<endl,void();
    if(gcd(a,b)>1) return cout<<a+b<<endl,void();

    int x=a,y=b,z;
    for(int i=2;i*i<=a;i++)
    {
        if(a%i==0)
        {
            x=i;
            break;
        }
    }
    for(int i=2;i*i<=b;i++)
    {
        if(b%i==0)
        {
            y=i;
            break;
        }
    }
    int ans=min({lcm(a,b),lcm(a,x)+lcm(x,b),lcm(a,y)+lcm(y,b)});
    ans=min(ans,lcm(a,2)+lcm(2,b));
    ans=min(ans,lcm(a,x)+lcm(x,y)+lcm(y,b));
    ans=min(ans,lcm(a,x)+lcm(x,2)+lcm(2,b));
    ans=min(ans,lcm(a,2)+lcm(2,y)+lcm(y,b));
    ans=min(ans,lcm(a,x)+lcm(x,2)+lcm(2,y)+lcm(y,b));
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}