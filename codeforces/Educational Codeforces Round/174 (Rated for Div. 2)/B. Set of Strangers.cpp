/*
 * @Author: dsaDadas11
 * @Date: 2025-03-09 11:03:16
 * @LastEditTime: 2025-03-09 11:06:55
 * @Description: go for it!
 */
/*
 解题思路：
 每一次操作能把同一个颜色的集合中不相邻的部分染成想要的颜色
 如果相邻，那就只需要染两次色
 因此判断是否相邻即可
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=1e3+7;
int dx[7]={0,1,0,-1};
int dy[7]={1,0,-1,0};
int n,m;
int a[M][M];
bool flag[N];
bool check(int x,int y)
{
    return (x>=1&&x<=n&&y>=1&&y<=m);
}
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) flag[i]=0;
    set<int> se;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
            se.insert(a[i][j]);
        }
    }
    // 寻找相邻
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(flag[a[i][j]]) continue;
            for(int k=0;k<4;k++)
            {
                int x=i+dx[k],y=j+dy[k];
                if(check(x,y)&&a[x][y]==a[i][j]) flag[a[i][j]]=1;
            }
        }
    }
    vector<int> v(se.begin(),se.end());
    int len=v.size();
    int ans=1e16;
    int sum=0;
    for(int i=0;i<len;i++)
    {
        if(flag[v[i]]) sum+=2;
        else sum++;
    }
    // 枚举每一种颜色
    for(int i=0;i<len;i++)
    {
        if(flag[v[i]]) ans=min(ans,sum-2);
        else ans=min(ans,sum-1);
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}