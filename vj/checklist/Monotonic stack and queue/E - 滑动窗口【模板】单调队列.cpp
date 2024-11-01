/*
 * @Author: dsaDadas11
 * @Date: 2024-01-24 11:18:37
 * @LastEditTime: 2024-03-07 15:19:40
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
const int N=1e6+7;
const int M=2e3+7;
int a[N],q[N];
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,k; cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	int tt=-1,hh=0;
	for(int i=1;i<=n;i++)
	{
		while(tt>=hh&&i-q[hh]+1>k) hh++;
		while(tt>=hh&&a[q[tt]]>=a[i]) tt--;
		q[++tt]=i;
		if(i>=k) cout<<a[q[hh]]<<' ';
	}
	cout<<endl;
	tt=-1,hh=0;
	for(int i=1;i<=n;i++)
	{
		while(tt>=hh&&i-q[hh]+1>k) hh++;
		while(tt>=hh&&a[i]>=a[q[tt]]) tt--;
		q[++tt]=i;
		if(i>=k) cout<<a[q[hh]]<<' ';
	}
	return 0;
}

/*
deque模拟：

#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,k;
int a[N];
deque<int> deq;
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	//找最小值
	for(int i=1;i<=n;i++)
	{
		while(!deq.empty()&&i-deq.front()+1>k) deq.pop_front();
		while(!deq.empty()&&a[deq.back()]>=a[i]) deq.pop_back();
		deq.push_back(i);
		if(i>=k) cout<<a[deq.front()]<<(i==n?'\n':' ');
	}
	while(!deq.empty()) deq.pop_back();
	//找最大值
	for(int i=1;i<=n;i++)
	{
		while(!deq.empty()&&i-deq.front()+1>k) deq.pop_front();
		while(!deq.empty()&&a[deq.back()]<=a[i]) deq.pop_back();
		deq.push_back(i);
		if(i>=k) cout<<a[deq.front()]<<(i==n?'\n':' ');
	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}
*/