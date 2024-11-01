/*
 * @Author: dsaDadas11
 * @Date: 2024-03-21 21:13:59
 * @LastEditTime: 2024-03-21 21:14:11
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int a[N];
void solve()
{
	int n; cin>>n;
	int pos=0,mm=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>mm)
		{
			mm=a[i];
			pos=i;
		}
	}
	bool flag=1;
	for(int i=1;i<n;i++)
	{
		if(i<pos)
		{
			if(a[i]>a[i+1])
			{
				flag=0;
				break;
			}
		}
		if(i>pos)
		{
			if(a[i]<a[i+1])
			{
				flag=0;
				break;
			}
		}
	}
	if(flag) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}