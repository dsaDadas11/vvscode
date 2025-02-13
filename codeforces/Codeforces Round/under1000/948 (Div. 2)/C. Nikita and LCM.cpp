/*
 * @Author: dsaDadas11
 * @Date: 2024-09-30 13:10:26
 * @LastEditTime: 2024-09-30 13:22:30
 * @Description: go for it!
 */
/*
 解题思路：
 我们可以贪心的选整个数组，求整个数组的lcm，如果这个lcm不等于数组的最大值的话，
 那一定是大于整个数组的，因此整个数组可以选，否则lcm等于数组的最大值
 有个地方我之前一直没想通，在这里证明一下
 首先两个元素的lcm一定>=max(a1,a2)，那么推广到整个数组就是lcm>=max_element(a+1,a+1+n)
 所以就有上面两种情况的出现，
 第二种情况就是 数组中的所有数都是maxn的因子，只有这样lcm才为maxn,
 如果我们要找一串序列的lcm不等于a中的每一个，那么这个lcm一定是maxn的不包含a的因子
 然后我们在数组中找能够整除这些因子的数，把它们的lcm算一下是否等于因子，如果不等于那就说明选的序列的lcm是等于序列的max的
 最后模拟即可
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
int a[M];
int lcm(int a,int b)
{
    return a*b/__gcd(a,b);
}
void solve()
{
    cin>>n;
    int maxn=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        maxn=max(maxn,a[i]);
    }
    int lc=1;
    for(int i=1;i<=n;i++)
    {
        lc=lcm(lc,a[i]);
        if(lc>maxn)
        {
            cout<<n<<endl;
            return;
        }
    }
    set<int> se(a+1,a+1+n); // 把数组a存进set
    vector<int> fac; // 存数组中没有的因子，否则数组中存在的因子最后的lcm一定在数组中
    for(int i=1;i*i<=maxn;i++)
    {
        if(maxn%i==0)
        {
            if(!se.count(i)) fac.push_back(i);
            if(!se.count(maxn/i)) fac.push_back(maxn/i);
        }
    }
    int ans=0;
    for(auto x:fac)
    {
        int cnt=0;
        int llc=1;
        for(int i=1;i<=n;i++)
        {
            if(x%a[i]==0)
            {
                cnt++;
                llc=lcm(llc,a[i]);
            }
        }
        if(llc==x) ans=max(ans,cnt); // 如果等于的话就说明lcm不在数组里
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