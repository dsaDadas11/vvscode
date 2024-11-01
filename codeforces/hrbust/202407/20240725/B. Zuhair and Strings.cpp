/*
 * @Author: dsaDadas11
 * @Date: 2024-07-25 20:39:27
 * @LastEditTime: 2024-07-25 20:40:12
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=2e5+7;
constexpr int M=2e3+7;
constexpr int mod=1e9+7; 
int base=29;
int p[N],ha[N],n;
int ha2[N][27];
bool vis[N][27];
void pre()
{
	p[0]=1;
	for(int i=1;i<=2e5+2;i++)
	{
		p[i]=(p[i-1]*base)%mod;
	}
	for(int i=1;i<=26;i++)
	{
		for(int j=1;j<=N+2;j++)
		{
			ha2[j][i]=((ha2[j-1][i]*base+i)%mod+mod)%mod;
		}
	}
}
int get(int l,int r)
{
	return ((ha[r]-ha[l-1]*p[r-l+1])%mod+mod)%mod;
}
int get2(int l,int r,int pos)
{
	return ((ha2[r][pos]-ha2[l-1][pos]*p[r-l+1])%mod+mod)%mod;
}
void solve()
{
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	int ans=0;
	int len=s.size();
	s=' '+s;
	for(int i=1;i<=len;i++)
	{
		ha[i]=((ha[i-1]*base+s[i]-'a'+1)%mod+mod)%mod;
	}
	for(int i=1;i<=26;i++)
	{
		int res=0;
		for(int j=1;j+k-1<=len;j++)
		{
			if(get(j,j+k-1)==get2(j,j+k-1,i))
			{
				res++;
				j+=k-1;
			}
		}
		ans=max(ans,res);
	}
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	pre();
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}