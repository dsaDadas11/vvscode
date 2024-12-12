/*
 * @Author: dsaDadas11
 * @Date: 2024-11-18 09:35:03
 * @LastEditTime: 2024-11-18 09:35:13
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
int ask(int l,int r)
{
	cout<<"? "<<l<<' '<<r<<endl;
	cout<<flush;
	int res;
	cin>>res;
	return res;
}
void solve()
{
	cin>>n;
	vector<int> ans(n+1);
	int pos=0;
	vector<int> v;
	v.push_back(0);
	v.push_back(0);
	for(int i=2;i<=n;i++)
	{
		int res=ask(1,i);
		v.push_back(res);
	}
	int k=0;
	int k2=0;
	for(int i=2;i<=n;i++)
	{
		if(v[i])
		{
			k=v[i];
			k2=v[i];
			pos=i;
			break;
		}
	}
	if(pos==0)
	{
		cout<<"! IMPOSSIBLE"<<endl;
		return;
	}
	ans[pos-1]=0,ans[pos]=1;
	for(int i=pos+1;i<=n;i++)
	{
		if(v[i]==k)
		{
			ans[i]=0;
		}
		else
		{
			k=v[i];
			ans[i]=1;
		}
	}
	for(int i=pos-k2;i<pos;i++)
	{
		ans[i]=0;
	}
	for(int i=1;i<pos-k2;i++)
	{
		ans[i]=1;
	}
	cout<<"! ";
	for(int i=1;i<=n;i++)
	{
		cout<<ans[i];
	}
	cout<<endl;
}
signed main()
{
	//ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}