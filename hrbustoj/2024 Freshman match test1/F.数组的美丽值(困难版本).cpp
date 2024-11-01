/*
 * @Author: dsaDadas11
 * @Date: 2024-10-17 21:03:51
 * @LastEditTime: 2024-10-17 22:49:42
 * @Description: go for it!
 */
/*
 URL: http://acm.hrbust.edu.cn/contests/index.php?act=showproblem&cid=2369&p=F
*/
/*
 解题思路：
 题意：求一段区间的数严格小于a数组数字的个数的总和，
 既然要求所有a[i]对于一段区间产生的贡献，那么可以反过来求区间中某一个元素对整个数组a产生的贡献(a中大于b[i]的个数)，
 假如说 b 数组的一段区间为 [2,3,5] , a数组为[1,2,3,4,5,6],
 看b[1]的贡献为4，b[2]的贡献为3，b[3]的贡献为1，
 相加等于8，正向求a数组中每个元素对b产生的贡献也是8(0+0+1+2+2+3=8),
 那么我们可以预处理出a[i]中每个元素对整个a产生的贡献(多开一个数组，sort+upper_bound求)，
 然后求个前缀和，最后对于一个区间[l,r]的ans即为sum[r]-sum[l-1]
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m;
int a[N];
int b[N];
int sum[N];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b+1,b+1+n);
	for(int i=1;i<=n;i++)
	{
		int pos=upper_bound(b+1,b+1+n,a[i])-(b);
		sum[i]=sum[i-1]+n-pos+1;
	}
	cin>>m;
	int l,r;
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		cin>>l>>r;
		ans+=sum[r]-sum[l-1];
	}
	cout<<ans<<endl;
	for(int i=0;i<=n+5;i++) sum[i]=0;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}