/*
 * @Author: dsaDadas11
 * @Date: 2024-06-27 10:33:26
 * @LastEditTime: 2024-12-05 22:40:36
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m;
string s[107];
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		//sum+=s[i].size();
		if(sum+s[i].size()<=m)
		{
			sum+=s[i].size();
		}
		else
		{
			cout<<i-1<<endl;
			return;
		}
	}
	cout<<n<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}