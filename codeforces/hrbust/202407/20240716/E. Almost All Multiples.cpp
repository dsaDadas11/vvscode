/*
 * @Author: dsaDadas11
 * @Date: 2024-07-18 11:21:43
 * @LastEditTime: 2024-07-18 11:24:42
 * @Description: go for it!
 */
/*
  这道题的hack点在于要找最小的排列，n在x位上不是最小的排列，
  因此要用x的倍数进行替换...
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
	int n,x;
	cin>>n>>x;
	if(x>n)
	{
		cout<<"-1"<<endl;
		return;
	}
	if(n%x==0)
	{
		for(int i=1;i<=n;i++) a[i]=i;
		a[1]=x,a[x]=n,a[n]=1;
		for(int i=x*2;i<n;i+=x)
		{
			if(n%i==0)
			{
				swap(a[x],a[i]);
				x=i;
			}
		}
		for(int i=1;i<=n;i++) cout<<a[i]<<' ';
		cout<<endl;
	}
	else cout<<"-1"<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}