/*
 * @Author: dsaDadas11
 * @Date: 2024-09-25 21:50:03
 * @LastEditTime: 2024-09-25 21:56:16
 * @Description: go for it!
 */
/*
 解题思路：
 根据剪纸的方式和k数进行双指针模拟即可
 这道题让我们算有多少个点，看点的数量为2e5，可以用双指针模拟(不过复杂度好像是n^2吧)
 我们设纸的边界为 nowlx=0,nowrx=a+1,nowly=0,nowry=b+1;
 然后每次剪纸的时候向对应的边界进行加减操作
 对于点的集合pair，我们要分别以x和y按从小到大排序
 然后我们x定义两个指针：lx rx，y定义两个指针：ly,ry
 慢慢加减到边界就可以了，其实用lowerbound可以加快搜索
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
#define pll pair<ll,ll>
using namespace std;
constexpr int N=2e5+7;
constexpr int M=2e3+7;
int a,b,n,m,k;
int ans[2]; // B A
char op;
pll xi[N],yi[N];
bool cmp(pll x,pll y)
{
	return x.second<y.second;
}
map<pll,bool> mp;
void solve()
{
	cin>>a>>b>>n>>m;
	mp.clear();
	ans[0]=ans[1]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>xi[i].first>>xi[i].second;
		yi[i]=xi[i];
	}
	sort(xi+1,xi+1+n);
	sort(yi+1,yi+1+n,cmp);
	int lx=1,rx=n,ly=1,ry=n;
	int nowlx=0,nowrx=a+1,nowly=0,nowry=b+1;
	for(int i=1;i<=m;i++)
	{
		cin>>op>>k;
		if(op=='U') // up
		{
			nowlx+=k;
			while(xi[lx].first<=nowlx&&lx<=rx)
			{
				if(mp[xi[lx]]==0)
				{
					mp[xi[lx]]=1;
					ans[i&1]++;
				}
				lx++;
			}
		}
		if(op=='D') // down
		{
			nowrx-=k;
			while(xi[rx].first>=nowrx&&lx<=rx)
			{
				if(mp[xi[rx]]==0)
				{
					mp[xi[rx]]=1;
					ans[i&1]++;
				}
				rx--;
			}
		}
		if(op=='L') // left
		{
			nowly+=k;
			while(yi[ly].second<=nowly&&ly<=ry)
			{
				if(mp[yi[ly]]==0)
				{
					mp[yi[ly]]=1;
					ans[i&1]++;
				}
				ly++;
			}
		}
		if(op=='R') // right
		{
			nowry-=k;
			while(yi[ry].second>=nowry&&ly<=ry)
			{
				if(mp[yi[ry]]==0)
				{
					mp[yi[ry]]=1;
					ans[i&1]++;
				}
				ry--;
			}
		}
	}
	cout<<ans[1]<<' '<<ans[0]<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}