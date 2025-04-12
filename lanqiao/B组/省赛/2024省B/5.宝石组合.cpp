/*
 * @Author: dsaDadas11
 * @Date: 2025-04-03 16:04:26
 * @LastEditTime: 2025-04-03 16:08:58
 * @Description: go for it!
 */
/*
 解题思路：
 首先有前提条件：
 gcd(lcm(a,b),c) = lcm(gcd(a,c),gcd(b,c)) 
 能推出：
 lcm(a,b,c) = a * b * c * gcd(a,b,c) / ( gcd(a,b) * gcd(a,c) * gcd(b,c) )

 因此 S = gcd(a,b,c)
 但是看 n范围 1e5 需要 n^3才能算出答案
 但是 Hi范围也是 1e5，那么我们可以从大到小枚举 S,时间复杂度为 O(nlogn)
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
int cnt[N];
void solve()
{
    cin>>n;
    int mx=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        cnt[a[i]]++;
        mx=max(mx,a[i]);
    }
    vector<int> ans;
    for(int i=mx;i>=1;i--)
    {
        vector<int> tmp;
        int t=0;
        for(int j=1;j<=mx/i;j++)
        {
            t+=cnt[j*i];
            for(int k=1;k<=cnt[j*i];k++)
            {
                if(tmp.size()==3) break;
                tmp.push_back(j*i);
            }
            if(tmp.size()==3) break;
        }
        if(tmp.size()==3)
        {
            ans=tmp;
            break;
        }
    }
    for(auto i:ans) cout<<i<<' ';
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}