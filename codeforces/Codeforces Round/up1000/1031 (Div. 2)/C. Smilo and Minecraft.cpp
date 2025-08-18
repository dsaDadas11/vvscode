/*
 * @Author: dsaDadas11
 * @Date: 2025-08-06 10:18:30
 * @LastEditTime: 2025-08-06 10:20:31
 * @Description: go for it!
 */
/*
 解题思路：
 可以发现在一个地方引爆后可以在其他区域进行范围为 1的引爆，换句话说只有开始引爆的区域的内部是无法获取金块的
 我们可以通过前缀和来维护引爆区域内的金块数量
 要注意边界
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m,k;
char c[507][507];
int calc(int x,int mx)
{
    return min(max(x,0LL),mx);
}
void solve()
{
    cin>>n>>m>>k;
    vector<vector<int> > sum(n+1,vector<int>(m+1));
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>c[i][j];
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+(c[i][j]=='g');
            cnt+=(c[i][j]=='g');
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(c[i][j]!='.') continue;
            int a=i+k-1,b=j+k-1,c=i-k+1,d=j-k+1;
            int res=sum[calc(a,n)][calc(b,m)]-sum[calc(a,n)][calc(d-1,m)]-sum[calc(c-1,n)][calc(b,m)]+sum[calc(c-1,n)][calc(d-1,m)];
            ans=max(ans,cnt-res);
        }
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