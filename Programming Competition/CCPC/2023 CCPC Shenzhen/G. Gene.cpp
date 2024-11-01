/*
 * @Author: dsaDadas11
 * @Date: 2024-10-17 21:49:45
 * @LastEditTime: 2024-10-17 21:54:08
 * @Description: go for it!
 */
/*
 解题思路：
 先看数据范围： n,q<=3e2 m<=6e4
 我们可以暴力遍历n,q找方案数，因此我们只需要优化在m中找不同的复杂度，
 我们先用哈希将所有字符串都算出哈希值，然后用二分+哈希从[1,n]找第一个不同的位置(假设是p)
 然后我们从[p+1,n]继续找第二个不同的位置....以此类推，
 时间复杂度就是n*q*k*logm
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=6e4+7;
constexpr int M=4e2+7;
constexpr int mod=1e9+7;
int n,q,m,k;
int ha1[M][N];
int ha2[M][N];
string s[M],t[M];
int ans[M];
int base=29;
int p[N];
void pre()
{
	p[0]=1;
	for(int i=1;i<=6e4+3;i++)
	{
		p[i]=(p[i-1]*base)%mod;
	}
}
int get1(int l,int r,int x)
{
	return ((ha1[x][r]-ha1[x][l-1]*p[r-l+1])%mod+mod)%mod;
}
int get2(int l,int r,int x)
{
	return ((ha2[x][r]-ha2[x][l-1]*p[r-l+1])%mod+mod)%mod;
}
int check(int lx,int len,int x,int y)
{
	int l=1,r=len;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(get1(lx,lx+mid-1,x)==get2(lx,lx+mid-1,y)) l=mid+1;
		else r=mid;
	}
	if(s[x][lx+l-1]!=t[y][lx+l-1]) return l;
	return 0;
}
void solve()
{
	cin>>n>>q>>m>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		s[i]=' '+s[i];
	}
	for(int i=1;i<=q;i++)
	{
		cin>>t[i];
		t[i]=' '+t[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			ha1[i][j]=((ha1[i][j-1]*base+s[i][j]-'a'+1)%mod+mod)%mod;
		}
	}
	for(int i=1;i<=q;i++)
	{
		for(int j=1;j<=m;j++)
		{
			ha2[i][j]=((ha2[i][j-1]*base+t[i][j]-'a'+1)%mod+mod)%mod;
		}
	}
	for(int i=1;i<=q;i++)
	{
		for(int j=1;j<=n;j++)
		{
			int cnt=0;
			int l=1,lx=0;
			bool flag=0;
			while((lx=check(l,m-l+1,j,i))!=0)
			{
				cnt++;
				if(cnt>k)
				{
					flag=1;
					break;
				}
				l+=lx;
			}
			if(!flag) ans[i]++;
		}
	}
	for(int i=1;i<=q;i++) cout<<ans[i]<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	pre();
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}