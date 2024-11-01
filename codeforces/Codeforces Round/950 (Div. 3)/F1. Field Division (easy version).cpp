/*
 * @Author: dsaDadas11
 * @Date: 2024-10-10 12:58:15
 * @LastEditTime: 2024-10-10 13:05:07
 * @Description: go for it!
 */
/*
 解题思路：
 手玩一下可以发现按y从小到大排序，x从小到大排序，
 (这里讲讲为什么：因为操作只能将位置往下或往右移，所以如果我们先遍历到一个y值较后的点然后再到一个y值较前的点是不行的，
 因此我们只能先走小的再走大的)
 然后每次记录前一个位置的行和列，计算这一部分的面积即可，最后特判一下最后一个点的下面部分的面积就好

 找除去第i个喷泉的面积是否增加，只需要找
 1.它在排完序后的下一个位置的y坐标是否增加
 2.在这个喷泉前面的位置的x值是否会大于等于它，如果在它的下面就说明这个位置删掉了也没用
  用set存一下位置，然后lower_bound找一下即可
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
void solve()
{
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++)
	{
		cin>>p[i].x>>p[i].y;  
		p[i].idx=i;
	}
	// 应该按y从小到大排序，再按x从小到大排序
	sort(p+1,p+1+k);
	// 先算刚开始的面积
	int res=0;
	int edrow=0,edcol=0;
	for(int i=1;i<=k;i++)
	{
		if(p[i].x>edrow&&p[i].y>=edcol)
		{
			res+=(p[i].x-edrow)*(p[i].y-1);
			edrow=p[i].x;
			edcol=p[i].y;
		}
	}
	res+=(n-edrow)*m;
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