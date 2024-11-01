/*
 * @Author: dsaDadas11
 * @Date: 2024-10-31 12:49:10
 * @LastEditTime: 2024-10-31 12:56:02
 * @Description: go for it!
 */
/*
 解题思路：
 贪心+二分，我们先将所有点必须取得取完，然后枚举将每个点删掉，然后往后面能取得最大值，
 用后缀和 和 二分找到最大位置即可，要注意得是删掉后可以选[0,m]而不是[0,r]
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m;
struct op
{
	int w,l,r;
	bool operator<(const op&rhs) const
	{
		return w<rhs.w;
	}
}a[N];
int suf[N]; // 区间后缀
int sufval[N];
int tmp,ans;
bool check(int x,int mx,int pos)
{
	if(x<=pos)
	{
		if(suf[x]-(a[pos].r-a[pos].l)>mx) return 1;
		return 0;
	}
	else
	{
		if(suf[x]>mx) return 1;
		return 0;
	}
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].w>>a[i].l>>a[i].r;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		tmp+=a[i].w*a[i].l;
		m-=a[i].l;
	}
	for(int i=n;i>=1;i--)
	{
		suf[i]=suf[i+1]+(a[i].r-a[i].l);
		sufval[i]=sufval[i+1]+a[i].w*(a[i].r-a[i].l);
	}
	// 遍历每一个点，二分
	for(int i=1;i<=n;i++)
	{
		int res=tmp;
		res-=a[i].w*a[i].l;
		int mx=m;
		mx+=a[i].l;
		
		// 将第i个点全都去掉
		int l=1,r=n;
		while(l<r)
		{
			int mid=(l+r)>>1;
			if(check(mid,mx,i)) l=mid+1;
			else r=mid;
		}
		while(suf[l]<mx&&l>1) l--;
		if(l+1<=i)
		{
			res+=sufval[l+1]-a[i].w*(a[i].r-a[i].l);
			mx-=(suf[l+1]-(a[i].r-a[i].l));
		}
		else
		{
			res+=sufval[l+1];
			mx-=suf[l+1];
		}
		if(mx>0)
		{
			if(a[l].r-a[l].l>=mx) res+=a[l].w*mx;
			else
			{
				res+=a[l].w*(a[l].r-a[l].l);
				mx-=(a[l].r-a[l].l);
				res+=a[i].w*mx;
			}
		}
		ans=max(ans,res);
		
		// 全取第i个点
		res=tmp;
		mx=m;
		res+=mx*a[i].w;
		ans=max(ans,res);
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