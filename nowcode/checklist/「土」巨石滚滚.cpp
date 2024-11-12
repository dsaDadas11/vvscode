/*
 * @Author: dsaDadas11
 * @Date: 2024-11-01 18:41:53
 * @LastEditTime: 2024-11-01 18:43:39
 * @Description: go for it!
 */
/*
 解题思路：
 纯贪心，如果都回复选a小的，如果都不恢复选b大的，否则选bx-ax大的
*/
// URL: https://ac.nowcoder.com/acm/problem/53681
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m;
struct op
{
	int ax,bx;
	int d; // bx-ax
	bool operator<(const op&rhs) const
	{
		if(d>0&&rhs.d>0) return ax<rhs.ax;
		if(d<0&&rhs.d<0) return bx>rhs.bx;
		return d>rhs.d;
	}
}p[N];
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i].ax>>p[i].bx;
		p[i].d=p[i].bx-p[i].ax;
	}
	sort(p+1,p+1+n);
	for(int i=1;i<=n;i++)
	{
		m-=p[i].ax;
		if(m<0) return cout<<"No"<<endl,void();
		m+=p[i].bx;
	}
	cout<<"Yes"<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}