/*
 * @Author: dsaDadas11
 * @Date: 2024-10-10 21:40:49
 * @LastEditTime: 2024-10-10 21:47:48
 * @Description: go for it!
 */
/*
 解题思路：
 不得不说 hard version 真的很难
 前一个easy version 我们已经将哪些能增加面积的算出来了，
 那么这个版本只需要遍历这些位置就行，
 我们用sum[i]存i及前i个位置的面积总和，然后我们往后遍历算没有i这个位置的面积和，
 当遍历到下一个可以增加面积的点或者终点的时候就更新前后面积的差值(这样居然不t，复杂度应该是2*n吧)，
 要注意如果最后一个位置是合法点，那么不能继续往下遍历，那么就需要特判一下
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=2e5+7;
constexpr int M=2e3+7;
int n,m,k;
struct op
{
	int x,y;
	int idx;
	bool operator<(const op& a) const
	{
		if(y==a.y) return x<a.x;
		return y<a.y;
	}
}p[N];
int ans[N];
int sum[N];
void solve()
{
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++)
	{
		cin>>p[i].x>>p[i].y;  
		p[i].idx=i;
	}
	for(int i=0;i<=k+5;i++) sum[i]=0;
	// 应该按y从小到大排序，再按x从小到大排序
	sort(p+1,p+1+k);
	// 先算刚开始的面积
	int res=0;
	map<pair<int,int>,pair<int,int> > mp; // 记录前驱节点
	int edrow=0,edcol=1;
	for(int i=1;i<=k;i++)
	{
		sum[i]=sum[i-1];
		if(p[i].x>edrow&&p[i].y>=edcol)
		{
			mp[{p[i].x,p[i].y}]={edrow,edcol};
			res+=(p[i].x-edrow)*(p[i].y-1);
			sum[i]+=(p[i].x-edrow)*(p[i].y-1);
			edrow=p[i].x;
			edcol=p[i].y;
		}
	}
	res+=(n-edrow)*m;
	sum[k]+=(n-edrow)*m;
	cout<<res<<endl;
	set<int> se;
	p[k+1].idx=0,p[k+1].x=0,p[k+1].y=0;
	for(int i=1;i<=k;i++)
	{
		if(p[i].y==p[i+1].y)
		{
			ans[p[i].idx]=0;
		}
		else
		{
			if(se.lower_bound(p[i].x)==se.end()) ans[p[i].idx]=1;
			else ans[p[i].idx]=0;
		}
		// set存行位置
		se.insert(p[i].x);
	}
	for(int i=1;i<=k;i++)
	{
		if(ans[p[i].idx]==0) continue;
		int s=sum[i-1];
		auto [er,ec]=mp[{p[i].x,p[i].y}];
		if(i==k)
		{
			ans[p[i].idx]=s+(n-er)*m-sum[i];
		}
		for(int j=i+1;j<=k;j++)
		{
			if(p[j].x>er&&p[j].y>=ec)
			{
				s+=(p[j].x-er)*(p[j].y-1);
				er=p[j].x;
				ec=p[j].y;
			}
			if(j==k)
			{
				s+=(n-er)*m;
			}
			if(ans[p[j].idx]||j==k)
			{
				ans[p[i].idx]=s-sum[j];
				break;
			}
		}
	}
	for(int i=1;i<=k;i++) cout<<ans[i]<<' ';
	cout<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}