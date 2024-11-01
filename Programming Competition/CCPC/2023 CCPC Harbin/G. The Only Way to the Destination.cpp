/*
 * @Author: dsaDadas11
 * @Date: 2024-10-03 13:53:19
 * @LastEditTime: 2024-10-03 14:29:14
 * @Description: go for it!
 */
/*
 解题思路：
 这道题N要开4e5，开3e5都wa....
 这道题的n,m<=1e9，k<=1e5，n,m看起来很大但是最后可以根据特判化为k的复杂度
 1.n==1时，只有墙是连续的在列的两个端点才可行，比如 1 0 0 1 1 连通， 1 0 1 0 不连通
 2.m>=2*k+2时一定为NO，比如 0 1 0 1 0 1 0 0 ，一定会有两条路出现使方案数大于1
 3.剩下的就归为O(m)的复杂度了，接下来详细讲解一般解怎么写
 首先我们将每列的墙的x1,x2开个pair记录下来，然后排一下序，
 接下来就是找每列的空白连通块，我们需要将这一列的相邻墙进行连接，变成一个大块(用双指针的r往下走)
 然后空白块就是两个大墙之间的区间，我们可以一边遍历空白块一边往下连接墙，然后把空白块的cur端点变成x2+1

 当空白块都处理好后就是求一列和与相邻列的空白块之间的边数和顶点数，如果没有环，那么边数等于顶点数-1
 并且在相邻两个列的空白块中，若连接的边数超过2肯定也是不合法的，直接return NO即可
 我们在双指针处理相邻两列时需要注意指针能遍历的条件，思维需要缜密
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m,k;
vector<pair<int,int> > wall[N]; // 记录一下i列的墙
vector<pair<int,int> > g[N]; // 记录一下i列的空网格区间
map<int,int> mp;
void solve()
{
    cin>>n>>m>>k;
    int x1,x2,y;
    if(n==1)
    {
        for(int i=1;i<=k;i++)
        {
            cin>>x1>>x2>>y;
            mp[y]=1;
        }
        int cnt1=0,cnt2=0;
        for(int i=1;i<=k;i++)
        {
            if(mp[i]) cnt1++;
            else break;
        }
        for(int i=m;i>=m-k+1;i--)
        {
            if(mp[i]) cnt2++;
            else break;
        }
        if(cnt1+cnt2==k) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        return;
    }
    for(int i=1;i<=k;i++)
    {
        cin>>x1>>x2>>y;
        if(y<N) wall[y].push_back({x1,x2});
    }
    if(m>=2*k+2)
    {
        cout<<"NO"<<endl;
        return;
    }
    for(int i=1;i<=m;i++) sort(wall[i].begin(),wall[i].end());
    for(int i=1;i<=m;i++)
    {
        int cur=1;
        int leni=wall[i].size();
        for(int j=0;j<leni;j++)
        {
            x1=wall[i][j].first;
            x2=wall[i][j].second;
            if(cur<=n&&cur<=x1-1) g[i].push_back({cur,x1-1});
            while(j+1<leni&&wall[i][j+1].first==x2+1)
            {
                j++;
                x2=wall[i][j+1].second;
            }
            cur=x2+1;
        }
        if(cur<=n) g[i].push_back({cur,n}); // 特判一下边界
    }
    // 以防万一再排个序
    for(int i=1;i<=m;i++) sort(g[i].begin(),g[i].end());
    int edge=0,vertex=0;
    // 寻找相邻两列的连通块
    for(int i=1;i<=m;i++)
    {
        int idx=0; // 记录相邻列的指针
        int leni=g[i].size();
        int leni1=g[i+1].size();
        for(int j=0;j<leni;j++)
        {
            auto [l1,r1]=g[i][j];
            edge+=r1-l1;
            vertex+=r1-l1+1;
            while(idx<leni1)
            {
                auto [l2,r2]=g[i+1][idx];
                int l=max(l1,l2),r=min(r1,r2);
                if(r-l+1>=2)
                {
                    cout<<"NO"<<endl;
                    return;
                }
                if(r-l+1>=0) edge+=r-l+1;
                if(r2>r1) break;
                idx++;
            }
        }
    }
    if(edge==vertex-1) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}