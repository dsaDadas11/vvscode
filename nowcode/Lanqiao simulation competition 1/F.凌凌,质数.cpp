/*
 * @Author: dsaDadas11
 * @Date: 2024-03-28 18:55:38
 * @LastEditTime: 2024-03-28 18:55:51
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
	cout<<"7776"<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}
/*
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e8+7;
constexpr int M=2e3+7;
int a[N],p[N];
int cnt;
void pre()
{
	for(int i=2;i<N;i++)
	{
		if(!a[i]) p[++cnt]=i;
		for(int j=1;j<=cnt&&p[j]*i<N;j++)
		{
			a[p[j]*i]=p[j];
			if(!i%p[j]) break;
		}
	}
}
void solve()
{
	pre();
	int ans=0;
	for(int i=1;i<=cnt;i++)
	{
		if(p[i]<1111) continue;
		if(p[i]>111111) break;
		if(p[i]%10!=1) ans++;
	}
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}
*/