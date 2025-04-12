/*
 * @Author: HuangCe
 * @Date: 2025-02-19 13:31:07
 * @LastEditTime: 2025-02-19 13:35:50
 * @Description: go for it!
 */
/*
 解题思路：
 题目中有个条件 max{r-l} <= min{R-L}
 这就说明 m个框区间一定大于等于 n个被框区间
 而题目要求不小于被框区间的一半即可，就是经过中点就可以
 因为不存在经过中点还比被框线段长度一半还小

 但是直接用 (l+r)/2 会有精度损失，我们就乘 2，用 l+r即可
 最后前缀和，O(1)查询
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=2e6+7;
constexpr int M=2e3+7;
int n,m;
int sum[N];
void solve()
{
    cin>>n>>m;
    int l,r;
    for(int i=1;i<=n;i++)
    {
        cin>>l>>r;
        sum[l+r]++;
    }
    for(int i=1;i<N;i++)
    {
        sum[i]+=sum[i-1];
    }
    for(int i=1;i<=m;i++)
    {
        cin>>l>>r;
        l<<=1;
        r<<=1;
        cout<<sum[r]-sum[l-1]<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}