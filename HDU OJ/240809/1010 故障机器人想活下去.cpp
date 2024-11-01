/*
 * @Author: dsaDadas11
 * @Date: 2024-08-09 14:11:09
 * @LastEditTime: 2024-08-09 14:11:51
 * @Description: go for it!
 */
/*
 优先队列贪心
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e5+7;
constexpr int M=2e3+7;
int n,x,k;
int a[N];
priority_queue<int> pq;
void solve()
{
	while(!pq.empty()) pq.pop();
	cin>>n>>x>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	int ans=0;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		pq.push(a[i]);
		if(x>a[i])
		{
			x-=a[i];
			ans++;
		}
		else
		{
			if(cnt<k&&(int)pq.size()>0)
			{
				cnt++;
				x+=pq.top();
				x-=a[i];
				pq.pop();
				ans++;
			}
			else break;
		}
	}
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}