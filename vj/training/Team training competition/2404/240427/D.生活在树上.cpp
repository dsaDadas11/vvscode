/*
 * @Author: dsaDadas11
 * @Date: 2024-04-29 12:48:08
 * @LastEditTime: 2024-04-29 12:48:25
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int dep[N];
void solve()
{
	int n,d;
	cin>>n>>d;
	if(n*(n-1)/2<d||n-1>d)
	{
		cout<<"NO"<<endl;
		return;
	}
	cout<<"YES"<<endl;
	int cnt=0;
	dep[0]=1;
	for(int i=2;i<=n;i++)
	{
		if(d-(cnt+1)>n-(i+1)+1)
		{
			d-=(cnt+1);
			++cnt;
			dep[cnt]=i;
			cout<<dep[cnt-1]<<' '<<dep[cnt]<<endl;
		}
		else
		{
			if(i==n&&d>=2)
			{
				cout<<dep[d-1]<<' '<<i<<endl;
			}
			else
			{
				cout<<1<<' '<<i<<endl;
				d--;
			}
		}
	}
	cout<<'1'<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}