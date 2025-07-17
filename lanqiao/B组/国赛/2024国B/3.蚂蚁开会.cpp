/*
 * @Author: dsaDadas11
 * @Date: 2025-06-07 13:04:32
 * @LastEditTime: 2025-06-07 13:10:20
 * @Description: go for it!
 */
/*
 可用 gcd做，会快一点
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
map<int,int> mp;
void solve()
{
    cin>>n;
    int x1,x2,y1,y2;
    for(int i=1;i<=n;i++)
    {
        cin>>x1>>y1>>x2>>y2;
        if(x1>x2)
        {
            swap(x1,x2);
            swap(y1,y2);
        }
        int dx=x2-x1,dy=y2-y1;
        if(dx==0)
        {
            for(int j=min(y1,y2);j<=max(y1,y2);j++)
            {
                mp[x1*N+j]++;
            }
            continue;
        }
        for(int x=x1;x<=x2;x++)
        {
            if(((x-x1)*dy)%dx) continue;
            int y=(dy*(x-x1)/dx)+y1;
            mp[x*N+y]++;
        }
    }
    int ans=0;
    for(auto [x,y]:mp)
    {
        if(y>=2) ans++;
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

/*
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
map<int,int> mp;
void solve()
{
    cin>>n;
    int x1,x2,y1,y2;
    for(int i=1;i<=n;i++)
    {
        cin>>x1>>y1>>x2>>y2;
        int xmin=min(x1,x2),xmax=max(x1,x2);
        int ymin=min(y1,y2),ymax=max(y1,y2);
        int d=gcd(xmax-xmin,ymax-ymin);
        int dx=(x2-x1)/d,dy=(y2-y1)/d;

        int x=x1,y=y1;
        for(int i=0;i<=d;i++)
        {
            mp[x*N+y]++;
            x+=dx,y+=dy;
        }
    }
    int ans=0;
    for(auto [x,y]:mp)
    {
        if(y>=2) ans++;
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
*/