/*
 * @Author: dsaDadas11
 * @Date: 2024-10-05 13:15:48
 * @LastEditTime: 2024-10-05 19:26:40
 * @Description: go for it!
 */
/*
 解题思路：
 两个相邻的数的公因子肯定为1，
 那么序列为：
 1 2
   3 4
     5 6
       7....
 最后在(n,1)位置放2*n，剩下的位置随便放就行
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,k;
pair<int,int> mp[N];
map<pair<int,int>,bool> vis;
void solve()
{
    cin>>n>>k;
    int dx=1,dy=1;
    mp[1]={1,1};
    vis[{1,1}]=1;
    for(int i=2;i<=2*n-1;i++)
    {
        if((i&1)==0) dy++;
        else dx++;
        mp[i]={dx,dy};
        vis[{dx,dy}]=1;
    }
    mp[2*n]={n,1};
    vis[{n,1}]=1;
    dx=1,dy=3;
    for(int i=k;i>2*n;i--)
    {
        while(vis[{dx,dy}])
        {
            dy++;
            if(dy==n+1) dy=1,dx++;
        }
        mp[i]={dx,dy};
        vis[{dx,dy}]=1;
    }
    for(int i=1;i<=k;i++)
    {
        cout<<mp[i].first<<' '<<mp[i].second<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}