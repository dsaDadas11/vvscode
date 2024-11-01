/*
 * @Author: dsaDadas11
 * @Date: 2024-10-20 20:09:48
 * @LastEditTime: 2024-10-30 13:11:17
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
void solve()
{
	cin>>n;
	vector<int> fac;
	for(int i=1;i*i<=n;i++)
	{
		if(n%i==0)
		{
			fac.push_back(i);
			if(i*i!=n) fac.push_back(n/i);
		}
	}
	sort(fac.begin(),fac.end());
	int ans=1;
	for(int i=0;i<(int)fac.size()-1;i++)
	{
		ans+=(fac[i+1]-fac[i])*(n/fac[i]);
	}
	ans+=(n-fac.back())*(n/fac.back());
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}
/*
3
5
451
114514

ans:
21
10251
7075858
*/