/*
 * @Author: dsaDadas11
 * @Date: 2024-07-26 15:12:43
 * @LastEditTime: 2024-07-26 15:13:07
 * @Description: go for it!
 */
/*
 又又又读假题了....(必须包含a[1])
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e5+7;
constexpr int M=2e3+7;
int n,l,d;
int a[N];
void solve()
{
	memset(a,0,sizeof a);
	vector<int> v;
	cin>>n>>l>>d;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+2,a+1+n);
	int cnt=0;
	for(int i=2;i<=n;i++)
	{
		if(a[i]<l) cnt++;
	}
	if(cnt<=1)
	{
		cout<<"No"<<endl;
		return;
	}
	if(a[1]>=l)
	{
		if(cnt>=3)
		{
			if(a[1]-a[2]<=d)
			{
				cout<<"No"<<endl;
				return;
			}
			else
			{
				cout<<"Yes"<<endl;
				return;
			}
		}
		else
		{
			cout<<"No"<<endl;
		}
	}
	else
	{
		int maxn=max({a[1],a[2],a[3],a[n]});
		int minn=min({a[1],a[2],a[3],a[n]});
		if(maxn-minn<=d)
		{
			cout<<"No"<<endl;
			return;
		}
		else
		{
			cout<<"Yes"<<endl;
			return;
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}