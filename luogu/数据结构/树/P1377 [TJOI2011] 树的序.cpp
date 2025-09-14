/*
 * @Author: dsaDadas11
 * @Date: 2025-09-02 14:00:57
 * @LastEditTime: 2025-09-02 14:09:03
 * @Description: go for it!
 */
/*
 解题思路：
 二叉搜索树(bst)是根据权值进行排序的，而笛卡尔树（元素 w,下标 k）满足 w小根堆，k二叉搜索树性质
 这道题是将 val构造 bst，那我们可以把 val当成下标 k,并且题目要求字典序最小，那么我们就把元素的下标当成 w,构造小根堆
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
int a[N];
pair<int,int> p[N];
int h[N];
int ls[N],rs[N];
int stk[N],top;
void dfs(int u)
{
    cout<<h[a[u]]<<' ';
    if(ls[u])
    {
        dfs(ls[u]);
    }
    if(rs[u])
    {
        dfs(rs[u]);
    }
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>p[i].first;
        p[i].second=i;
    }
    sort(p+1,p+1+n);

    for(int i=1;i<=n;i++)
    {
        a[i]=p[i].second;
        h[p[i].second]=p[i].first;
    }

    for(int i=1;i<=n;i++)
    {
        while(a[stk[top]]>a[i]&&top) top--;
        if(!top) ls[i]=stk[top+1];
        else ls[i]=rs[stk[top]],rs[stk[top]]=i;
        stk[++top]=i;
    }

    dfs(stk[1]);
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}