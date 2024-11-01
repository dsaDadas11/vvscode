/*
 * @Author: dsaDadas11
 * @Date: 2024-10-24 12:11:59
 * @LastEditTime: 2024-10-24 12:15:48
 * @Description: go for it!
 */
/*
 解题思路：
 一开始纯暴力，后来想了想最劣情况：1e6*1e6
 因此我们只能通过推导数学公式来O(n)遍历
 曼哈顿距离可以看作横坐标+纵坐标，因此x,y是独立的，我们只分析其中一个，
 算每一个距离的贡献，假设总共有n个点，这个距离是排序后的第i条线段，
 那么它既可以是线段左边的点遍历到右边的点所经过的距离，也可以是右遍历到左的距离，
 因此一段距离的贡献是 d[i]*(n-i)*i*2
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=1e3+7;
int n,m;
int c;
map<int,vector<pair<int,int> > > mp;
bool cmp(pair<int,int> p1,pair<int,int> p2)
{
	return p1.second<p2.second;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>c;
			mp[c].push_back({i,j});
		}
	}
	int ans=0;
	int len=0;
	vector<int> d;
	for(auto &[x,v]:mp)
	{
		sort(v.begin(),v.end());
		len=v.size();
		if(len==1) continue;
		for(int i=0;i<len-1;i++)
		{
			d.push_back(abs(v[i+1].first-v[i].first));
		}
		for(int i=0;i<(int)d.size();i++)
		{
			if(i==0||i==(int)d.size()-1) ans+=d[i]*(len-1)*2;
			else ans+=d[i]*((len-(i+1))*(i+1))*2;
		}
		d.clear();
		sort(v.begin(),v.end(),cmp);
		for(int i=0;i<len-1;i++)
		{
			d.push_back(abs(v[i+1].second-v[i].second));
		}
		for(int i=0;i<(int)d.size();i++)
		{
			if(i==0||i==(int)d.size()-1) ans+=d[i]*(len-1)*2;
			else ans+=d[i]*((len-(i+1))*(i+1))*2;
		}
		d.clear();
	}
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}