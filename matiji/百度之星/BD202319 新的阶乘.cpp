/*
 * @Author: dsaDadas11
 * @Date: 2024-05-29 20:04:06
 * @LastEditTime: 2024-05-29 20:06:26
 * @Description: go for it!
 */
/*
第一种做法：
1.先筛质数，然后从最小的质数开始遍历，并且每次j的循环都是p[i]的倍数，保证每个p[i]都被加上
2.这种做法会卡long long,只需要把cnt1和cnt2开long long即可
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
//#define int ll
using namespace std;
constexpr int N=1e7+7;
constexpr int M=2e3+7;
int a[N],p[N];
int cnt,temp;
void pre()
{
	for(int i=2;i<N;i++)
	{
		if(!a[i]) p[++cnt]=i;
		for(int j=1;j<=cnt&&p[j]*i<N;j++)
		{
			a[p[j]*i]=1;
			if(!i%p[j]) break;
		}
	}
}
void solve()
{
	int x;
	cin>>x;
	cout<<"f("<<x<<")=";
	bool vis=0;
	for(int i=1;i<=cnt&&p[i]<=x;i++)
	{
		ll cnt2=0;
		for(int j=p[i];j<=x;j+=p[i])
		{
			temp=j;
			ll cnt1=0;
			while(temp%p[i]==0)
			{
				temp/=p[i];
				cnt1+=x+1-j;
			}
			cnt2+=cnt1;
		}
		if(!vis)
		{
			vis=1;
		}
		else cout<<"*";
		if(cnt2>1) cout<<p[i]<<"^"<<cnt2;
		else cout<<p[i];
	}
	cout<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}