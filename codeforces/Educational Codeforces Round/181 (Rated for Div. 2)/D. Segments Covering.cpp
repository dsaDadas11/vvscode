/*
 * @Author: dsaDadas11
 * @Date: 2025-07-22 23:18:25
 * @LastEditTime: 2025-07-23 20:57:53
 * @Description: go for it!
 */
/*
 解题思路：
 概率 dp
 设 dp[i]为前 i个点被一条线覆盖的概率，设 pre[i]为前 i个位置拥有的线段的不取方法的前缀积 (1-p/q)
 首先我们根据 r存储 l,p,q (使得每次到右端点使解决这条线段)
 那么在 [l,r]中的所有线段不取的概率就是 pre[i]/pre[l-1]
 当我们想要一个线段能被取得时，就应该除去 pre中得不取概率，即 pre[i]/pre[l-1] * 1/(1-p/q) * p/q
 那么状态转移方程就显而易见了：dp[i]+=dp[l-1] * pre[i]/pre[l-1] * 1/(1-p/q) * p/q
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
constexpr int mod=998244353;
int quickpow(int x,int y)
{
	int ans=1;
	while(y)
	{
		if(y&1) ans=ans*x%mod;
		y>>=1;
		x=x*x%mod;
	}
	return ans;
}
int niyuan(int x)
{
	return quickpow(x,mod-2);
}
int n,m;
int l,r,p,q;
int dp[N];
vector<pair<int,int> > g[N];
void solve()
{
	cin>>n>>m;
	int b=1;
	for(int i=1;i<=n;i++)
	{
		cin>>l>>r>>p>>q;
		int invq=niyuan(q);
		int qp=((q-p)%mod+mod)%mod;
		b=(b*qp%mod)*invq%mod;
		int invqp=niyuan(qp);
		int w=p*invqp%mod;
		g[r].push_back({l,w});
	}
	dp[0]=1;
	for(int i=1;i<=m;i++)
	{
		int cur=0;
		for(auto [l,w]:g[i])
		{
			cur=(cur+dp[l-1]*w)%mod;
		}
		dp[i]=cur;
	}
	cout<<dp[m]*b%mod<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}
/*
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
constexpr int mod=998244353;
int quickpow(int x,int y)
{
	int ans=1;
	while(y)
	{
		if(y&1) ans=ans*x%mod;
		y>>=1;
		x=x*x%mod;
	}
	return ans;
}
int ni(int x)
{
	return quickpow(x,mod-2);
}
int n,m;
int l,r,p,q;
struct op
{
    int l,p,q;
};
vector<op> g[N];
int dp[N];
int pre[N]; // 前 i个不取的前缀积
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>l>>r>>p>>q;
        g[r].push_back({l,p,q});
    }
    dp[0]=1,pre[0]=1;
    for(int i=1;i<=m;i++)
    {
        pre[i]=pre[i-1];
        for(auto [l,p,q]:g[i])
        {
            pre[i]*=(1-p*ni(q)%mod+mod)%mod;
            pre[i]%=mod;
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(auto [l,p,q]:g[i])
        {
            int p_pre=pre[i]*ni(pre[l-1])%mod;
            int pq=p*ni(q)%mod;
            int inv_pq=ni((1-pq+mod)%mod);
            dp[i]+=((dp[l-1]*p_pre%mod)*inv_pq%mod)*pq%mod;
            dp[i]=(dp[i]%mod+mod)%mod;
        }
    }
    cout<<dp[m]<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}
*/