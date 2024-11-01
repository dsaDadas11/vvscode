/*
 * @Author: dsaDadas11
 * @Date: 2024-09-22 21:09:25
 * @LastEditTime: 2024-09-22 21:21:24
 * @Description: go for it!
 */
/*
 解题思路：
 这道题是辗转相除，其实手建一个二叉树寻找其规律
 有三种情况
 1.x==y 那么肯定是A赢，答案为p0
 2.x<y
   我们要让A赢的话，肯定得让A一直赢到x>y为止，赢的次数为x/y
   (用等比数列求和来减少递归次数)
   特判一下y==0的情况
 3.x>y
    这种情况比较复杂，因为既能赢也能输
    举个例子，7 9 这个样例 手搓二叉树后我们可以算出x>y的时候的概率
    是：p0+p1*(p0+p1*(p0+p1*dfs))  // dfs为接下来二叉树子树的概率
    化简则是 1-p1^3+p1^3*dfs (用等比数列求和来减少递归次数)
    并且这时候x<y了 可以继续递归下去

 剩下的看代码就懂了，注意操作时可能会出现负数，需要 +mod
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
		if(y&1) ans=(ans*x)%mod;
		x=(x*x)%mod;
		y>>=1;
	}
	return ans;
}
int niyuan(int x)
{
	return quickpow(x,mod-2);
}
int x,y;
int a0,a1,b,a;
int p0,p1;
int dfs(int x,int y)
{
	if(x>y)
	{
		int cnt1=x/y;
		int r=x%y; //x
		//int tp=(p0*(1-quickpow(p1,cnt1))%mod)*niyuan(1-p1)%mod;
		int p3=quickpow(p1,cnt1);
		int tp=((1-p3)%mod+mod)%mod;
		if(r==0)
		{
			return tp;
		}
		int res=((tp+p3*dfs(r,y))%mod+mod)%mod;
		return res;
	}
	if(x<y)
	{
		int cnt=y/x;
		int tp=quickpow(p0,cnt)%mod;
		y-=cnt*x;
		if(y==0) return tp;
		return (tp*dfs(x,y)%mod+mod)%mod;
	}
	if(x==y)
	{
		return p0;
	}
	return 0;
}
void solve()
{
	cin>>x>>y;
	cin>>a0>>a1>>b;
	a=a0+a1;
	p0=a0*niyuan(a)%mod;
	p1=a1*niyuan(a)%mod;
	cout<<(dfs(x,y)%mod+mod)%mod<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}