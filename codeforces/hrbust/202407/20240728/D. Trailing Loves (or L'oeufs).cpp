/*
 * @Author: dsaDadas11
 * @Date: 2024-07-28 15:48:34
 * @LastEditTime: 2024-07-28 15:49:51
 * @Description: go for it!
 */
/*
求 n！的末尾有多少个0.
在10进制下面，n的阶乘末尾零的计算方法是：
把10=2*5,     
然后2为因子的个数有：n/2+n/(2^2)+n/(2^3)……
然后5为因子的个数有：n/5+n/(5^2)+n/(5^3)……
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,b;
vector<pair<int,int> > v;
void solve()
{
	cin>>n>>b;
	int t=b;
	for(int i=2;i*i<=t;i++)
	{
		if(t%i==0)
		{
			int cnt=0;
			while(t%i==0)
			{
				cnt++;
				t/=i;
			}
			v.push_back({i,cnt});
		}
	}
	if(t>1) v.push_back({t,1});
	int ans=LONG_LONG_MAX;
	for(auto it:v)
	{
		int p=it.first;
		int res=0;
		while(p<=n)
		{
			res+=n/p;
			if(p>n/it.first) break; //注意RE
			p*=it.first;
		}
		int num=res/it.second;
		ans=min(num,ans);
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