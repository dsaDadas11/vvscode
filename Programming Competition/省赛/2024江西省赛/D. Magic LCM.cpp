/*
 * @Author: dsaDadas11
 * @Date: 2025-04-22 20:30:24
 * @LastEditTime: 2025-04-22 21:00:34
 * @Description: go for it!
 */
/*
 解题思路：
 这道题是 gcd和 lcm能操作的次数越多越好 (实际只有 n^2次)
 但是不能用 n^2 的做法
 因此我们能想到每次取 gcd和 lcm时都是质因数的重新排列，
 那么我们可以将每个质因数的幂次方放入 vector，然后每次选每个质因数中最大的进行乘积变成一个 ans
 记录每个质因数最多有多少个幂次方，记作 mx，这个 mx就是能变成最大数的个数
 那剩下的 n-mx只能因为质因子分离变为 1，不要忘记这 n-mx个数

 注意 nlognlogn 是过不了的，不能套 map了 
 (其实用了下面的大优化之后就不卡 map了，并且每次遍历 map，存在空元素就将这个位置删掉，减少遍历次数，1812ms过)
 还有个大优化：vi<=1e6 因此拥有次幂大于 1的质因数不会超过 1e3，因此我们只需要跑 1e3的质数筛
 并且我们将上面存放次幂的 vector改成 1e3+1即可，对于大于 1e3的质数，我们直接将其放到对应的 res[j]中 (1780ms过)
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=1e3+7;
constexpr int mod=998244353;
int n,b;
int v[N],res[N];
int a[N],p[N],len;
int quickpow(int x,int y)
{
    int ans=1;
    while(y)
    {
        if(y&1) ans=ans*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return ans;
}
void init()
{
    for(int i=2;i<M;i++)
    {
        if(!a[i]) p[++len]=i;
        for(int j=1;j<=len&&p[j]*i<M;j++)
        {
            a[p[j]*i]=p[j];
            if(!i%p[j]) break;
        }
    }
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
        res[i]=1;
    }

    vector<vector<int> > mp(p[len]+1);
    map<int,int> pos;
    int mx=0;
    for(int i=1;i<=n;i++)
    {
        b=v[i];
        for(int j=1;j<=len&&p[j]<=b;j++)
        {
            if(b%p[j]) continue;
            int cnt=0;
            while(b%p[j]==0)
            {
                b/=p[j];
                cnt++;
            }
            mp[p[j]].push_back(cnt);
        }
        if(b>1)
        {
            res[++pos[b]]*=b;
            res[pos[b]]%=mod;
            mx=max(mx,pos[b]);
        }
    }

    for(int i=1;i<=len;i++)
    {
        if(mp[p[i]].size()==0) continue;
        sort(mp[p[i]].begin(),mp[p[i]].end());
        mx=max(mx,(int)mp[p[i]].size());
    }

    int ans=n-mx;
    for(int j=1;j<=mx;j++)
    {
        for(int i=1;i<=len;i++)
        {
            if(mp[p[i]].size())
            {
                res[j]*=quickpow(p[i],mp[p[i]].back());
                res[j]%=mod;
                mp[p[i]].pop_back();
            }
        }
        ans=(ans+res[j])%mod;
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}