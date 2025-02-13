/*
 * @Author: dsaDadas11
 * @Date: 2024-12-05 23:49:17
 * @LastEditTime: 2024-12-06 19:49:17
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
int a[N];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		sum+=a[i];
	}
	if(sum%n)
	{
		cout<<"NO"<<endl;
		return;
	}

	int ave=sum/n;
	for(int i=2;i<n;i++)
	{
		int d=ave-a[i-1];
		a[i-1]=ave;
		a[i+1]-=d;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]<0||a[i]!=ave)
		{
			cout<<"NO"<<endl;
			return;
		}
	}
	cout<<"YES"<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}

/*
更简单的做法：
因为奇数位和偶数位互不干扰，
然后分别求平均值看是否相等即可

void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int sum1=0,sum0=0;
	for(int i=1;i<=n;i++)
	{
		if(i&1) sum1+=a[i];
		else sum0+=a[i];
	}
	int len1=(n+1)/2;
	int len0=n/2;
	if(sum1%len1||sum0%len0) return cout<<"NO"<<endl,void();
	if(sum1/len1!=sum0/len0) return cout<<"NO"<<endl,void();
	cout<<"YES"<<endl;
}

*/