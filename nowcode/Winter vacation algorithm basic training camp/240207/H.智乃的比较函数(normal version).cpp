/*
 * @Author: dsaDadas11
 * @Date: 2024-01-15 17:40:03
 * @LastEditTime: 2024-02-17 18:19:50
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
void solve()
{
	int n; cin>>n;
	int x[57]={0},y[57]={0},z[57]={0};
	int a[4]={0};
	for(int i=1;i<=n;i++) cin>>x[i]>>y[i]>>z[i];
	int f1=0;
	for(a[1]=1;a[1]<=3;a[1]++)
	{
		for(a[2]=1;a[2]<=3;a[2]++)
		{
			for(a[3]=1;a[3]<=3;a[3]++)
			{
				bool f2=1;
				for(int i=1;i<=n;i++)
				{
					if((a[x[i]]<a[y[i]]&&z[i]==1)||(a[x[i]]>=a[y[i]]&&z[i]==0)) continue;
					else f2=0;
				}
				f1+=f2;
			}
		}
	}
	cout<<(f1?"Yes":"No")<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}