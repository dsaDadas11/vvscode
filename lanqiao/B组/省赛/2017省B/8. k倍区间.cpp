/*
 * @Author: dsaDadas11
 * @Date: 2025-03-02 10:38:18
 * @LastEditTime: 2025-03-02 11:17:46
 * @Description: go for it!
 */
// URL：https://www.lanqiao.cn/problems/2387/learning/?subject_code=1&group_code=4&match_num=8&match_flow=1&origin=cup
// https://www.luogu.com.cn/problem/P8649
/*
 解题思路：
 这是数据加强版的 k倍区间
 首先 (sum[j]-sum[i])%k == 0
 也就是 sum[j]%k = sum[i]%k
 但是题目不能要负倍数，所以我们要找比 sum[j]小的 sum[i]
 用 upper_bound记录即可
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,k;
int a,sum,ans;
map<int,vector<int> > mp;
void solve()
{
    cin>>n>>k;
    mp[0].push_back(0);
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        sum+=a;
        int tmp=(sum%k+k)%k;
        sort(mp[tmp].begin(),mp[tmp].end());
        int num=upper_bound(mp[tmp].begin(),mp[tmp].end(),sum)-mp[tmp].begin();
        ans+=num;
        mp[tmp].push_back(sum);
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