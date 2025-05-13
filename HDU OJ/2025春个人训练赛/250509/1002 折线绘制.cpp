/*
 * @Author: dsaDadas11
 * @Date: 2025-05-12 16:56:02
 * @LastEditTime: 2025-05-12 17:09:28
 * @Description: go for it!
 */
/*
 解题思路：
 manacher
 但是我们不能加上左右边界，而只能将数字左右插入 -1
 在判断时加入 i+p[i]<s.size()&&i-p[i]>=0
 因为这道题是求中心对称并且我们将中间插入了 -1
 那么每次判断时可能走到 a[i]也可能走到 -1，此时我们需要取 +2或 -2
 例如：s[i+p[i]]+s[i-p[i]]==s[i+p[i]-2]+s[i-p[i]+2] 而不能是 s[i+p[i]]+s[i-p[i]]==s[i]*2 (走到 -1时一定错)
 然后，我们需要求的是区间的数量，而 p[i]代表区间中点的个数
 例如以 3为中心： -1 1 -1 2 -1 3 -1 4 -1 5 -1
 或者以 -1为中心：-1 1 -1 2 -1
 我们可以发现左右边界一定是 -1，那么求区间的数量为 p[i]/2 而不需要向上取整
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
void manacher(vector<int>& s,vector<int>& p)
{
    int r=0,c;
    for(int i=0;i<s.size();i++)
    {
        if(i<r) p[i]=min(p[c*2-i],r-i);
        else p[i]=1;
        while(i+p[i]<s.size()&&i-p[i]>=0&&s[i+p[i]]+s[i-p[i]]==s[i+p[i]-2]+s[i-p[i]+2]) p[i]++;
        if(p[i]+i>r)
        {
            r=p[i]+i;
            c=i;
        }
    }
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<int> t;
    for(int i=1;i<=n;i++)
    {
        t.push_back(-1);
        t.push_back(a[i]);
    }
    t.push_back(-1);
    vector<int> p(t.size()+3);
    manacher(t,p);
    int ans=0;
    for(int i=0;i<t.size();i++)
    {
        ans+=p[i]/2;
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