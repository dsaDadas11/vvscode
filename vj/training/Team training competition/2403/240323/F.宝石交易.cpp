/*
 * @Author: dsaDadas11
 * @Date: 2024-03-25 21:22:53
 * @LastEditTime: 2024-03-25 21:29:45
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e5+7;
constexpr int M=2e3+7;
constexpr int F=507;
constexpr int inf=0x3f3f3f3f;
int dist[F][F];
//数组记得开大些，不然不到n的两倍，会wa也会re
int s[N],t[N];
void floyd()
{
	for(int k=1;k<F;k++)
	{
		for(int i=1;i<F;i++)
		{
			for(int j=1;j<F;j++)
			{
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
}
void solve()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=n;i++)
	{
		cin>>t[i];
		t[n+i]=t[i];
	}
	int ans=inf;
	for(int i=1;i<F;i++)
	{
		for(int j=1;j<F;j++)
		{
			if(i==j) dist[i][j]=0;
			else dist[i][j]=inf;
		}
	}
	while(m--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		dist[a][b]=min(dist[a][b],c);
	}
	floyd();
    // 两个环项链的模拟1-n对应，其中一个项链开2*n的长度
	for(int i=1;i<=n;i++)
	{
		int sum=0;
		bool flag=0;
		int l=i,r=i+n-1;
		for(int j=l,k=1;j<=r;j++,k++)
		{
			if(s[k]==t[j]) continue;
			int mm=min(dist[s[k]][t[j]],dist[t[j]][s[k]]);
			if(mm==inf)
			{
				flag=1;
				break;
			}
			sum+=mm;
		}
		if(!flag) ans=min(ans,sum);
	}
	if(ans==inf) cout<<"-1"<<endl;
	else cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}
/*
另一个ac代码：
第一点：用取模m来模拟两个项链的模拟过程
注意：两个数组不同点在于 正常数组t的边界为1-n，模拟环的数组s边界为0-n-1
第二点：把long long 关掉，不然超时 //因为long long 取模特别慢，容易卡常

#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
//#define int ll
using namespace std;
constexpr int N=1e5+7;
constexpr int M=2e3+7;
constexpr int F=407;
constexpr int inf=0x3f3f3f3f;
int dist[F][F];
int s[N],t[N];
void floyd()
{
	for(int k=1;k<F;k++)
	{
		for(int i=1;i<F;i++)
		{
			for(int j=1;j<F;j++)
			{
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
}
void solve()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>s[i];
	for(int i=1;i<=n;i++) cin>>t[i];
	int ans=inf;
	for(int i=1;i<F;i++)
	{
		for(int j=1;j<F;j++)
		{
			if(i==j) dist[i][j]=0;
			else dist[i][j]=inf;
		}
	}
	while(m--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		dist[a][b]=min(dist[a][b],c);
	}
	floyd();
	for(int i=1;i<=n;i++)
	{
		int sum=0;
		bool flag=0;
		for(int j=1;j<=n;j++)
		{
			int k=(i+j-1)%(n);
			if(s[k]==t[j]) continue;
			int mm=min(dist[s[k]][t[j]],dist[t[j]][s[k]]);
			if(mm==inf)
			{
				flag=1;
				break;
			}
			sum+=mm;
		}
		if(!flag) ans=min(ans,sum);
	}
	if(ans==inf) cout<<"-1"<<endl;
	else cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}
*/