/*
 * @Author: dsaDadas11
 * @Date: 2024-11-23 21:30:00
 * @LastEditTime: 2024-11-23 22:09:14
 * @Description: go for it!
 */
/*
 解题思路：
 不要读假题哦
 1.我们先分析最大值在i右边的情况
 此时我们肯定先想把最大值给去掉，但是最大值去掉之后又会加到前面的数上，因此我们只能把前面i-1个数也都去掉，ans[i]=i
 2.最大值在i的左边
 我们要想把最大值给去掉，也会加到前面的数上，因此我们需要把前面i-1个数都去掉即可，ans[i]=i-1
 3.最大值为i
 ans[i]=0
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,c;
int a[N];
int sum[N];
int ans[N];
void solve()
{
	cin>>n>>c;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int maxn=0;
	int pos=0;
	a[1]+=c;
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
		if(maxn<a[i])
		{
			maxn=a[i];
			pos=i;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(i==pos)
		{
			ans[i]=0;
			continue;
		}
		if(sum[i]>=maxn) ans[i]=i-1;
		else ans[i]=i;
	}
	for(int i=1;i<=n;i++) cout<<ans[i]<<' ';
	cout<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}