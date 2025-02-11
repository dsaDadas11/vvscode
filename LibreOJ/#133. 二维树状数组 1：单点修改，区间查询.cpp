/*
 * @Author: dsaDadas11
 * @Date: 2025-01-11 19:01:21
 * @LastEditTime: 2025-01-11 19:02:31
 * @Description: go for it!
 */
// URL: https://loj.ac/p/133
/*
 2^12 = 4096
 样例全是极端样例，4e3全re了。。。
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e5+7;
constexpr int M=4e3+107;
int n,m;
int tr[M][M];
int lowbit(int x)
{
    return (x&(-x));
}
void add(int x,int y,int val)
{
    for(int i=x;i<=n;i+=lowbit(i))
    {
        for(int j=y;j<=m;j+=lowbit(j))
        {
            tr[i][j]+=val;
        }
    }
}
int ask(int x,int y)
{
    int sum=0;
    for(int i=x;i;i-=lowbit(i))
    {
        for(int j=y;j;j-=lowbit(j))
        {
            sum+=tr[i][j];
        }
    }
    return sum;
}
void solve()
{
    cin>>n>>m;
    int op,a,b,c,d;
    while(cin>>op)
    {
        if(op==1)
        {
            cin>>a>>b>>c;
            add(a,b,c);
        }
        else
        {
            cin>>a>>b>>c>>d;
            cout<<ask(c,d)-ask(c,b-1)-ask(a-1,d)+ask(a-1,b-1)<<endl;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}