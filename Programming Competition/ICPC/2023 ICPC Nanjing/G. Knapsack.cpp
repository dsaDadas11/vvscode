/*
 * @Author: dsaDadas11
 * @Date: 2025-08-11 16:11:49
 * @LastEditTime: 2025-08-11 16:18:18
 * @Description: go for it!
 */
/*
 解题思路：
 先按价格排序，从价格大的开始选，然后再根据价值维护后缀和，
 最后跑背包就好了

 如果存在物品 a 和 b，其中 a 是免费选取的，b 是付费选取的，那么一定有 wa >= wb。
 否则的话，我们可以换成免费选 b、付费选 a，方案的效果不会变差。

 如果存在物品 a 和 b，其中 a 是免费选取的，b 没有被选取，那么一定有 va >= vb。
 否则的话，我们可以换成免费选 b、不选 a，方案的效果不会变差。
 
 因此，如果我们将所有物品按照 wi 从小到大排序，
 那么对于最优策略来说，必然存在一个分界点 M，使得在序号 i > M 的物品中，价值最大的前 k 个物品会被免费选取。
 对于每个序号 i，我们可以通过维护一个堆来预先计算出：从第 i 个物品开始的后缀中，免费选取 k 个物品所能获得的最大价值之和。
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e4+7;
constexpr int M=5e3+7;
int n,W,k;
pair<int,int> a[N];
int sum[N],dp[N];
void solve()
{
    cin>>n>>W>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].first>>a[i].second;
    }
    sort(a+1,a+1+n);

    if(k)
    {
        multiset<int> se;
        for(int i=n;i>=1;i--)
        {
            if(se.size()<k)
            {
                se.insert(a[i].second);
                sum[i]=a[i].second;
            }
            else if(*se.begin()<a[i].second)
            {
                sum[i]=a[i].second-*se.begin();
                se.erase(se.begin());
                se.insert(a[i].second);
            }
            sum[i]+=sum[i+1];
        }
    }

    int ans=sum[1];
    for(int i=1;i<=n;i++)
    {
        for(int j=W;j>=a[i].first;j--)
        {
            dp[j]=max(dp[j],dp[j-a[i].first]+a[i].second);
        }
        ans=max(ans,dp[W]+sum[i+1]);
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}