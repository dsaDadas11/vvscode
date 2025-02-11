/*
 * @Author: dsaDadas11
 * @Date: 2025-01-11 19:28:14
 * @LastEditTime: 2025-01-11 19:31:52
 * @Description: go for it!
 */
// URL: https://loj.ac/p/134
/*
 二维差分不太熟练，并且很容易写错字母
 如果二维差分想不起来的话 想想一维差分怎么写（在左端点加，在右端点右一位减）
 二维差分是
 d[x1][y1]+=k
 d[x1][y2+1]-=k
 d[x2+1][y1]-=k
 d[x2+1][y2+1]+=k
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
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
    int op,a,b,c,d,k;
    while(cin>>op)
    {
        if(op==1)
        {
            cin>>a>>b>>c>>d>>k;
            //a++,b++,c++,d++;
            add(c+1,d+1,k);
            add(c+1,b,-k);
            add(a,d+1,-k);
            add(a,b,k);
        }
        else
        {
            cin>>a>>b;
            //a++,b++;
            cout<<ask(a,b)<<endl;
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