/*
 * @Author: dsaDadas11
 * @Date: 2025-05-16 13:59:53
 * @LastEditTime: 2025-05-16 14:46:19
 * @Description: go for it!
 */
/*
 解题思路：
 这道题要用到向量的知识和向量的叉乘判断方向
 我们枚举 A, D, E三个点来找另外两个点 C, B
 D坐标可表示为 A + u ( u = ( XD-XA, YD-YA) ) 令 XD-XA=dx YD-YA=dy
 因为 DC垂直于 AD，并且在 AD的右方，那么我们可以设 v向量 = ( dy, -dx )
 那么 C = A + t*v  ( t目前未知)
 那么知道了 D, C, E的坐标后，因为 ED = EC, 我们可以列出方程
 求出 t = 2*( dx*( YD-YE )- dy*( XD-XE ) )/( dy*dy + dx*dx )
 那就可以求出 B, C坐标

 不过要判断 DA和 DE的夹角是否是钝角，并且 DE要是 DA顺时针方向钝角的向量，因此我们加上判断：
 1.向量的点积：DA * DE > 0   为了确保 DA和 DE的夹角是钝角
 2.向量的叉积：DA X DE > 0   为了确保 DE是 DA顺时针方向钝角的向量

*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
int x[307],y[307];
void solve()
{
    cin>>n;
    set<pair<int,int> > se;
    for(int i=1;i<=n;i++)
    {
        cin>>x[i]>>y[i];
        se.insert({x[i],y[i]});
    }
    int ans=0;
    int cnt=0;
    for(int a=1;a<=n;a++)
    {
        for(int d=1;d<=n;d++)
        {
            if(a==d) continue;
            for(int e=1;e<=n;e++)
            {
                if(a==e||d==e) continue;
                if((x[a]-x[d])*(x[e]-x[d])+(y[a]-y[d])*(y[e]-y[d])>=0) continue;
                if((x[a]-x[d])*(y[e]-y[d])-(y[a]-y[d])*(x[e]-x[d])<=0) continue;
                int dx=x[d]-x[a],dy=y[d]-y[a];
                if(dx==0) dy=1;
                else if(dy==0) dx=1;
                else
                {
                    int g=gcd(dx,dy);
                    dx/=g,dy/=g;
                }
                int tp=2*(dx*(y[d]-y[e])-dy*(x[d]-x[e]));
                int td=dx*dx+dy*dy;
                if(tp%td!=0) continue;
                int t=tp/td;
                int xc=x[d]+t*dy,yc=y[d]-t*dx;
                int xb=x[a]+t*dy,yb=y[a]-t*dx;
                if(se.count({xc,yc})&&se.count({xb,yb})) ans++;
            }
        }
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