/*
 * @Author: dsaDadas11
 * @Date: 2025-01-14 20:43:52
 * @LastEditTime: 2025-01-15 11:43:06
 * @Description: go for it!
 */
/*
 解题思路：
 奇数只能和奇数合并，偶数只能和偶数合并
 然后在草稿纸列一下会发现，奇数和任意位的奇数都能合并(但要消耗偶数)，偶数同理
 因此我们找奇数和偶数的最后合并的大小即可
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
int c[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>c[i];
    if(n==1) return cout<<c[1]<<endl,void();
    vector<int> ji,ou;
    for(int i=1;i<=n;i++)
    {
        if(i&1) ji.push_back(c[i]);
        else ou.push_back(c[i]);
    }
    sort(ji.begin(),ji.end());
    sort(ou.begin(),ou.end());
    int ans=max(ji.back(),ou.back());
    int res1=ji.back(),res2=ou.back();
    for(int i=ji.size()-2;i>=0;i--)
    {
        if(ji[i]<=0) break;
        res1+=ji[i];
    }
    ans=max(ans,res1);
    for(int i=ou.size()-2;i>=0;i--)
    {
        if(ou[i]<=0) break;
        res2+=ou[i];
    }
    ans=max(ans,res2);
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}