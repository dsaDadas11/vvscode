/*
 * @Author: dsaDadas11
 * @Date: 2025-09-22 16:42:18
 * @LastEditTime: 2025-09-22 18:39:07
 * @Description: go for it!
 */
/*
 解题思路：
 我们可以枚举边长的向量 (a,b)，边长即为 sqrt(a*a+b*b)
 然后我们对每个正方形的四个点都计算差分贡献
 一个点的边界就是 n-(a+b)+横坐标偏移量 和 m-(a+b)+纵坐标偏移量
 然后前缀和计算贡献即可
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m;
vector<vector<int> > g;
void get_d(int x,int y,int a,int b)
{
    g[x][y]++;
    g[n-a-b+x+1][m-a-b+y+1]++;
    g[n-a-b+x+1][y]--;
    g[x][m-a-b+y+1]--;
}
void solve()
{
    cin>>n>>m;
    g.clear();
    g.resize(n+7,vector<int>(m+7));

    int len=min(n,m);
    for(int a=0;a<=len;a++)
    {
        for(int b=1;a+b<=len;b++)
        {
            get_d(a,0,a,b);
            get_d(0,b,a,b);
            get_d(b,a+b,a,b);
            get_d(a+b,a,a,b);
        }
    }
    
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i) g[i][j]+=g[i-1][j];
            if(j) g[i][j]+=g[i][j-1];
            if(i&&j) g[i][j]-=g[i-1][j-1];
            cout<<g[i][j]<<' ';
        }
        cout<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}