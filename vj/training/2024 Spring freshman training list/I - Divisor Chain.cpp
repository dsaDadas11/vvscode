/*
 * @Author: dsaDadas11
 * @Date: 2024-04-17 19:40:25
 * @LastEditTime: 2024-04-17 19:42:16
 * @Description: go for it!
 */
// 一个简单的倍增
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
void solve()
{
	int x;
	cin>>x;
	int ans=1;
	int cnt=1;
	vector<int> v;
	v.push_back(ans);
	while(true)
	{
		if(ans==x) break;
		if(ans+cnt<=x)
		{
			ans+=cnt;
			cnt<<=1;
			v.push_back(ans);
		}
		else cnt>>=1;
	}
	cout<<v.size()<<endl;
	for(int i=v.size()-1;i>=0;i--)
	{
		cout<<v[i]<<' ';
	}
	cout<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}
/*
写for循环的时候注意循环次数，次数少的话会wa!!!
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
void solve()
{
	int x;
	cin>>x;
	int ans=1;
	int cnt=0;
	vector<int> v;
	v.push_back(ans);
	for(int i=1;i<=10000;i++)
	{
		while(ans+(1<<cnt)>x) --cnt;
		ans+=(1<<cnt);
		++cnt;
		v.push_back(ans);
		if(ans==x) break;
	}
	cout<<v.size()<<endl;
	for(int i=v.size()-1;i>=0;i--)
	{
		cout<<v[i]<<' ';
	}
	cout<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}
*/