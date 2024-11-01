/*
 * @Author: dsaDadas11
 * @Date: 2024-04-29 22:49:27
 * @LastEditTime: 2024-04-29 22:58:15
 * @Description: go for it!
 */
/*
这道题得思路：
1.首先想到用set维护宝石的等级和左右区间
2.其次是一个贪心的思路
  (1) 如果这一位置的下一个不是一个等级或者相邻的则不能合并，直接return
  (2) 如果这两个位置能合并则继续看下两个位置，如果只有第三个位置能合并则合并，否则进入下一次循环
      也就是以 2 循环或者以 3 循环(前提是不能以 2 循环的前提下)
      当然如果取完三个之后size为1则能直接合并并return了

*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
void solve()
{
	int n,x;
	cin>>n;
	set<array<int,3> > s;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		s.insert({x,i,i});
	}
	while(!s.empty())
	{
		auto [x,l,r]=*s.begin();
		s.erase(s.begin());
		if(s.empty())
		{
			cout<<"Yes"<<endl;
			return;
		}
		if(s.begin()->at(0)==x&&s.begin()->at(1)==r+1)
		{
			r=s.begin()->at(2);
			s.erase(s.begin());
			if(!s.empty()&&s.begin()->at(0)==x&&s.begin()->at(1)==r+1)
			{
				if(s.size()==1)
				{
					cout<<"Yes"<<endl;
					return;
				}
				else
				{
					auto [x1,l1,r1]=*next(s.begin());
					if(x1!=x||l1!=s.begin()->at(2)+1)
					{
						r=s.begin()->at(2);
						s.erase(s.begin());
					}
				}
			}
			s.insert({x+1,l,r});
		}
		else
		{
			cout<<"No"<<endl;
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