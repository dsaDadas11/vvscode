/*
 * @Author: dsaDadas11
 * @Date: 2024-04-08 21:59:26
 * @LastEditTime: 2024-04-08 22:00:01
 * @Description: go for it!
 */
/*
1 欧拉猜想：大于2 的所有偶数都可以写成两个素数相加

2 衍生：对于所有数（2除外）有如下规律：（3-最少可以写成3个素数相加）

偶 ： 2

	   素 ： 1
奇 ：   n-2素 ： 2
	   else ： 3
       
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e7+7;
constexpr int M=2e3+7;
bool a[N];
int p[N],sum[N],f[N];
int cnt,n;
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
	f[2]=1;
	for(int i=3;i<N;i++)
	{
		if(i%2==0) f[i]=2;
		else
		{
			if(!a[i]) f[i]=1;
			else if(!a[i-2]) f[i]=2;
			else f[i]=3;
		}
	}
	for(int i=2;i<N;i++) sum[i]=sum[i-1]+f[i];
}
void solve()
{
	cin>>n;
	cout<<sum[n]<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	pre();
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}