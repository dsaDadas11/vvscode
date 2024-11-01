/*
 * @Author: dsaDadas11
 * @Date: 2024-03-26 20:56:08
 * @LastEditTime: 2024-03-26 20:56:16
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
	int pos=-1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=1)
		{
			pos=i;
			break;
		}
	}
	if(pos==-1)
	{
		if(n%2) cout<<"First"<<endl;
		else cout<<"Second"<<endl;
	}
	else
	{
		if((pos)%2) cout<<"First"<<endl;
		else cout<<"Second"<<endl;
	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}