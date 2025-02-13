/*
 * @Author: dsaDadas11
 * @Date: 2024-09-26 12:44:01
 * @LastEditTime: 2024-09-26 12:47:14
 * @Description: go for it!
 */
/*
 解题思路：
 做的为数不多的一道反悔贪心
 我们可以选择所有的c[i]
 然后当金额不够用(<0)时，我们每次把最大的c[i]反悔取出，把金额反悔成>=0的状态
 反悔贪心应该是用在快乐值恒定的情况下吧，这时候与每个子状态没有关系
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=2e5+7;
constexpr int M=2e3+7;
int m,x;
int c[N];
void solve()
{
	cin>>m>>x;
	for(int i=1;i<=m;i++) cin>>c[i];
	priority_queue<int> pq; // 存买的c[i]
	int sum=0;
	for(int i=1;i<=m;i++)
	{
		sum-=c[i];
		pq.push(c[i]);
		while(sum<0)
		{
			sum+=pq.top();
			pq.pop();
		}
		sum+=x;
	}
	cout<<pq.size()<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}