/*
 * @Author: dsaDadas11
 * @Date: 2024-12-02 21:01:03
 * @LastEditTime: 2024-12-02 21:01:38
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m;
//   行         列
vector<vector<int> > a;
bool check(int l)
{
	vector<vector<int> > vis(n+5,vector<int>(m+5));
	for(int i=1;i+l-1<=n;i++)
	{
		for(int j=1;j+l-1<=m;j++)
		{
			if(vis[i][j]) continue;
			if(a[i][j]<l) continue;
			vis[i][j]=1;
			bool flag=0;
			for(int x=i;x<=i+l-1;x++)
			{
				for(int y=j;y<=j+l-1;y++)
				{
					if(a[x][y]<l)
					{
						flag=1;
						for(int xx=i;xx<=x;xx++)
						{
							for(int yy=j;yy<=y;yy++)
							{
								vis[xx][yy]=1;
							}
						}
						break;
					}
				}
			}
			if(flag==0) return 1;
		}
	}
	return 0;
}
void solve()
{
	cin>>n>>m;
	a.clear();
	a.resize(n+5,vector<int>(m+5));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
		}
	}
	int l=1,r=n;
	while(l<r)
	{
		int mid=(l+r+1)>>1;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	cout<<l<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}