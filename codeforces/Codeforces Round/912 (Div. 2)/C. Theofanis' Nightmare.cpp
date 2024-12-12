/*
 * @Author: dsaDadas11
 * @Date: 2024-12-03 12:37:22
 * @LastEditTime: 2024-12-03 12:45:55
 * @Description: go for it!
 */
/*
 区间分组求最大值的套路题
 还有两道此套路题：
 https://codeforces.com/contest/2042/problem/C
 https://codeforces.com/gym/105385/problem/F

 思路：
 我们从后往前找，每当我们在 i这里划分了一个界限，那么对 [i+1,n]都会产生贡献 ( i本身有贡献)
 并且产生的贡献为：suf[i+1]+a[i] 即为 suf[i]
 每次划分相当于 [i+1,n] 的数多加了一次
 贪心的想：我们更希望大于0的后缀多加一些，因此我们只需要在 suf[i]>0 时划分界限(等于也行)
 但是第一组比较特别，必须得分组，因此最后要加上 suf[1]的贡献

 引用大佬的话：
 本质上，就是每个数前面如果产生新的划分，那么这个划分的总的贡献是后面所有数的和。
 所以每个划分的贡献是独立的。
 所以只需要在suffix是正的时候添加划分即可（第一个数前面强制一个划分，无论正负）
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
int suf[N];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	suf[n+1]=0;
	for(int i=n;i>=1;i--)
	{
		suf[i]=suf[i+1]+a[i];
	}
	int ans=0;
	for(int i=n;i>=2;i--)
	{
		if(suf[i]>0) ans+=suf[i];
	}
	// 第一位必须分组
	ans+=suf[1];
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}