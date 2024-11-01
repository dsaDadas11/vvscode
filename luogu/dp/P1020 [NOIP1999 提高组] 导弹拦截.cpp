/*
 * @Author: dsaDadas11
 * @Date: 2024-09-17 17:17:49
 * @LastEditTime: 2024-09-17 17:31:06
 * @Description: go for it!
 */
/*
 解题思路：
 一：
 第一问构造最长不上升子序列，用二分+贪心即可
 我们可以这样贪心：用一个数组g记录这个不上升序列的最后一位元素的值（即最小的一位）
 如果有a[i]>g[cnt]的情况，就说明可以用cnt前面的数更新这个a[i]（用二分找这个位置）
 使这个g数组为不上升数组，即一个有序的数组
 二：
 第二问和第一问的构造挺像，只不过用到的是最长上升子序列（反过来的）
 g[i]表示第i个最长不上升子序列的最后一个元素，
 如果a[i]大于g[cnt]，那就说明前面的任何一个最长不上升子序列都不能将它插入队尾，所以它要新添加一个位置
 否则能在cnt前面找到一个位置将a[i]插入
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n=1;
int a[N];
int g[N];
void solve()
{
	while(cin>>a[n]) ++n;
	--n;
	// 最长不上升子序列
	int cnt=0;
	g[0]=2e9;
	for(int i=1;i<=n;i++)
	{
		if(a[i]<=g[cnt]) g[++cnt]=a[i];
		else
		{
			int l=1,r=cnt;
			while(l<r)
			{
				int mid=(l+r)>>1;
				if(g[mid]>=a[i]) l=mid+1;
				else r=mid;
			}
			g[l]=a[i];
		}
	}
	cout<<cnt<<endl;
	// 最长上升子序列 (看有多少个最长不上升子序列)
	g[0]=-2e9;
	cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>g[cnt]) g[++cnt]=a[i];
		else
		{
			int l=1,r=cnt;
			while(l<r)
			{
				int mid=(l+r)>>1;
				if(g[mid]>=a[i]) r=mid;
				else l=mid+1;
			}
			g[l]=a[i];
		}
	}
	cout<<cnt<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}