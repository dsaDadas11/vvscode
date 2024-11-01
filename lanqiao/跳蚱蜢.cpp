/*
 * @Author: dsaDadas11
 * @Date: 2024-08-29 21:32:18
 * @LastEditTime: 2024-08-29 21:32:33
 * @Description: go for it!
 */
// URL:https://www.lanqiao.cn/problems/642/learning/
// 解题思路：让盘子动
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
string beg="012345678",ed="087654321";
map<string,bool> mp;
void bfs()
{
	queue<pair<string,int> > q;
	q.push({beg,0});
	mp[beg]=1;
	while(!q.empty())
	{
		string s=q.front().first;
		int t=q.front().second;
		q.pop();
		if(s==ed)
		{
			cout<<t<<endl;
			return;
		}
		int pos=0;
		for(int i=0;i<=9;i++)
		{
			if(s[i]=='0')
			{
				pos=i;
				break;
			}
		}
		string temp="";
		for(int i=pos-2;i<=pos+2;i++)
		{
			int k=(i+9)%9;
			if(k==pos) continue;
			temp=s;
			swap(temp[pos],temp[k]);
			if(mp[temp]) continue;
			mp[temp]=1;
			q.push({temp,t+1});
		}
	}
}
void solve()
{
	bfs();
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}