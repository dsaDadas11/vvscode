/*
 * @Author: dsaDadas11
 * @Date: 2024-09-23 22:14:13
 * @LastEditTime: 2024-09-23 22:14:30
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int x,y;
void solve()
{
	cin>>x>>y; // 1*1  2*2
	swap(x,y);
	int cnt=x/2;
	int r=x%2;
	int yu=y-cnt*7;
	int ans=cnt;
	if(yu<=0)
	{
		if(r==0) cout<<cnt<<endl;
		else cout<<cnt+1<<endl;
	}
	else
	{
		if(r==0)
		{
			cout<<cnt+(yu+14)/15<<endl;
		}
		else
		{
			cnt++;
			yu-=11;
			if(yu<=0) cout<<cnt<<endl;
			else cout<<cnt+(yu+14)/15<<endl;
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