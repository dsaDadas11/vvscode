/*
 * @Author: dsaDadas11
 * @Date: 2024-08-08 14:27:37
 * @LastEditTime: 2024-08-08 14:28:08
 * @Description: go for it!
 */
/*
 贪心，每两个顶点之间选花费最小的即可
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m,x,y;
int v[N];
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>v[i];
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y;
		ans+=min(v[x],v[y]);
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