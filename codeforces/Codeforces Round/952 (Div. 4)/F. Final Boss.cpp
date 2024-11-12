/*
 * @Author: dsaDadas11
 * @Date: 2024-11-10 21:03:11
 * @LastEditTime: 2024-11-10 21:03:26
 * @Description: go for it!
 */
/*
 思维简单，注重代码能力罢了，不如CCPC2024哈尔滨站 J.充电站 一根
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int h,n;
int a[N]; // 攻击伤害
int c[N]; // 冷却
struct op
{
	// cd为当前轮数 c[i]+round
	int cd,idx;
	bool operator<(const op&that) const
	{
		return cd>that.cd;
	}
};
priority_queue<op> pq;
void solve()
{
	while(!pq.empty()) pq.pop();
	cin>>h>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>c[i];
	// 预处理第一轮
	for(int i=1;i<=n;i++)
	{
		h-=a[i];
		pq.push({c[i]+1,i});
	}
	int round=1;
	while(h>0)
	{
		round++;
		while(!pq.empty())
		{
			auto [cd,idx]=pq.top();
			if(cd>round) round=cd;
			pq.pop();
			h-=a[idx];
			if(h<=0) break;
			pq.push({c[idx]+round,idx});
		}
	}
	cout<<round<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}