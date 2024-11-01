/*
 * @Author: dsaDadas11
 * @Date: 2024-07-18 15:17:18
 * @LastEditTime: 2024-07-18 15:17:24
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
string s,t;
int len1,len2;
bool flag=0;
void dfs(int pos,int now,bool r)
{
	if(now==len2-1)
	{
		flag=1;
		return;
	}
	if(pos+1<len1&&s[pos+1]==t[now+1]&&!flag&&r)
	{
		dfs(pos+1,now+1,1);
	}
	if(pos-1>=0&&s[pos-1]==t[now+1]&&!flag)
	{
		dfs(pos-1,now+1,0);
	}
}
void solve()
{
	flag=0;
	cin>>s>>t;
	len1=s.size();
	len2=t.size();
	for(int i=0;i<len1;i++)
	{
		if(s[i]==t[0])
		{
			dfs(i,0,1);
			if(flag) break;
		}
	}
	if(flag) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}