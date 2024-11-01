/*
 * @Author: dsaDadas11
 * @Date: 2024-03-21 18:16:40
 * @LastEditTime: 2024-03-21 18:16:48
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
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==0&&c==0)
	{
		cout<<"0"<<endl;
		return;
	}
	if(a==0||c==0)
	{
		cout<<"1"<<endl;
		return;
	}
	int t1=__gcd(a,b);
	int t2=__gcd(c,d);
	a/=t1,b/=t1;
	c/=t2,d/=t2;
	int x1=a*d,x2=b*c;
	if(x1==x2) cout<<"0"<<endl;
	else if(x1%x2==0||x2%x1==0) cout<<"1"<<endl;
	else cout<<"2"<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}