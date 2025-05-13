/*
 * @Author: dsaDadas11
 * @Date: 2025-04-26 11:38:14
 * @LastEditTime: 2025-04-26 11:40:13
 * @Description: go for it!
 */
/*
 解题思路：
 看 B的范围为 [1,mod-1] 大概 1e4，可以枚举出 B
 那么就能把 B*B*B*c + B*B*d + B*e+f = A给求出来
 然后用 A求出字符串的字符 (0不可以)，再用 B去检验 hashb是否正确
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
constexpr int mod=10007;
int k,c,d,e,f;
int p[10];
void init()
{
	p[0]=1;
	for(int i=1;i<=10;i++)
	{
		p[i]=p[i-1]*10;
	}
}
bool check(int x,int val)
{
	vector<int> v;
	while(x)
	{
		v.push_back(x%27);
		if(v.back()==0) return 0;
		x/=27;
	}
	int tmp=0;
	for(int i=0;i<v.size();i++)
	{
		tmp+=v[i]*p[i]%mod;
		tmp%=mod;
	}
	return tmp==val;
}
void solve()
{
	cin>>k>>c>>d>>e>>f;
	int ans=0;
	for(int i=0;i<mod;i++)
	{
		int a=i*i*i*c+i*i*d+i*e+f;
		if(check(a,i)&&a) ans++;
	}
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	init();
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}