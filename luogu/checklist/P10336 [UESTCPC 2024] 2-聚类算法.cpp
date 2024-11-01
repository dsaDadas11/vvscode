/*
 * @Author: dsaDadas11
 * @Date: 2024-10-19 20:31:30
 * @LastEditTime: 2024-10-19 20:41:20
 * @Description: go for it!
 */
/*
 解题思路：
 2024CCPC哈尔滨站的热身赛C题，原电子科大校赛J题，
 题意：A和B轮流选一些点，A使val(dist(SA))-val(dist(SB))最大化，B使其最小化
 有一种很奇妙的解题方式：
 我们将边权化为边两个顶点的点权，这么做的好处是，我们可以根据这个点权(一个点到其他点的曼哈顿距离之和)排序，
 当A或B同时选了一条边的两个顶点，那么这个权就加了两遍，如果没同时选的话，相减的时候就能把这两个权值消掉
 因此最后ans=(sum(SA)-sum(SB))/2
 (画图推导一下可以发现点权确实可以求ans)
 点权用一般求和公式可以发现就是点在之前出现的次数-之前的点的presum，用前缀和跑一遍，后缀和跑一遍即可
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,k;
void solve()
{
	cin>>n>>k;
	n<<=1;
	vector<vector<int> > v(n,vector<int>(k));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<k;j++)
		{
			cin>>v[i][j];
		}
	}
	vector<int> distsum(n);
	// 按每一维排序
	for(int j=0;j<k;j++)
	{
		vector<pair<int,int> > tmp;
		for(int i=0;i<n;i++) tmp.push_back({v[i][j],i});
		sort(tmp.begin(),tmp.end());
		int presum=0;
		for(int i=0;i<n;i++)
		{
			distsum[tmp[i].second]+=tmp[i].first*i-presum;
			presum+=tmp[i].first;
		}
		presum=0;
		// 倒着再来一遍 将一个点和其他所有点的距离都算出来(即算出点权)
		for(int i=n-1;i>=0;i--)
		{
			distsum[tmp[i].second]+=presum-tmp[i].first*(n-1-i);
			presum+=tmp[i].first;
		}
	}
	int ans=0;
	// 从大到小排序
	sort(distsum.begin(),distsum.end(),greater<int>());
	for(int i=0;i<n;i++)
	{
		if(i&1) ans-=distsum[i];
		else ans+=distsum[i];
	}
	// 最后答案除以2
	ans>>=1;
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}