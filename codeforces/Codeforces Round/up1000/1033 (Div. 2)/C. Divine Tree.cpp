/*
 * @Author: dsaDadas11
 * @Date: 2025-07-22 17:03:19
 * @LastEditTime: 2025-07-22 17:19:19
 * @Description: go for it!
 */
/*
 解题思路：
 特别思维的一道题，很费脑子
 首先一颗树的最大贡献就是反着建的一条链，为 n*(n+1)/2
 我们可以反着建，然后根据和 m的差值决定 ans[i]为哪一个节点
 if(sum==m) 那就说明 i后面的节点可以反着建
 else 那一定是 sum>m的情况，那么我们就要将 ans[i]变小，变小 min(sum-m,ans[i]-1)
 首先看变小 sum-m的情况，这时候说明只要改完这个节点，整棵树的贡献就会变为 m，因此我们将这个节点 i连向 ans[i]-(sum-m)，
   因为前面的 n->i+1节点连向的一定都是 1 (就是变小 ans[i]-1的情况)，因此我们将 i连向比 i小的节点可以保证贡献为ans[i]-(sum-m)，
   原因是：后面更小的节点都是反向的链，所以 ans[i]-(sum-m)节点一定是其中最小的节点
 再看变小 ans[i]-1的情况，这时 ans[i]-(ans[i]-1)=1，就相当于把节点 i连向了 1，使得整体贡献小了 ans[i]-1(因为后面的节点还是正常连，贡献不会变)

 1400的思维题都这么难。。。要歇了
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m;
void solve()
{
    cin>>n>>m;
    if(m>n*(n+1)/2||m<n)
    {
        cout<<-1<<endl;
        return;
    }
    vector<int> ans(n+1);
    int rt=-1,sum=n*(n+1)/2;
    for(int i=1;i<=n;i++) ans[i]=i;
    for(int i=n;i>=1;i--)
    {
        if(sum>m)
        {
            int p=min(sum-m,ans[i]-1);
            ans[i]-=p;
            sum-=p;
        }
        else
        {
            rt=i;
            break;
        }
    }
    cout<<rt<<endl;
    for(int i=1;i+1<=rt;i++)
    {
        cout<<i<<' '<<i+1<<endl;
    }
    for(int i=rt+1;i<=n;i++)
    {
        cout<<i<<' '<<ans[i]<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}