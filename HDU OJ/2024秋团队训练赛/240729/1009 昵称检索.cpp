/*
 * @Author: dsaDadas11
 * @Date: 2024-07-30 11:01:26
 * @LastEditTime: 2024-07-30 11:01:29
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m;
string s,name[N];
int ans[N];
int mp[N][26],vis[26];
int day[17]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int find_date(int date[5])
{
	int x=m+1;
	for(int i=4;i>=1;i--)
	{
		x--;
		if(x<1) return 0;
		x=mp[x][date[i]];
	}
	return x;
}
int find_name(string t)
{
	int x=0;
	int len=t.size();
	for(int i=0;i<len;i++)
	{
		x++;
		if(x>=m+1) return m+1;
		x=mp[x][t[i]-'a'];
	}
	return x;
}
void solve()
{
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>name[i];
	memset(vis,0,sizeof vis);
	s=' '+s;
	for(int i=1;i<=m;i++)
	{
		if(s[i]>='0'&&s[i]<='9') vis[s[i]-'0']=i;
		for(int j=0;j<=9;j++) mp[i][j]=vis[j];
	}
	for(int i=0;i<=m+1;i++) ans[i]=0;
	for(int i=1;i<=12;i++)
	{
		for(int j=1;j<=day[i];j++)
		{
			int date[5]={0};
			date[1]=i/10,date[2]=i%10,date[3]=j/10,date[4]=j%10;
			int pos=find_date(date);
			if(pos) ans[pos]++;
		}
	}
	fill(vis,vis+26,m+1);
	for(int i=m;i>=2;i--) ans[i-1]+=ans[i];
	for(int i=m;i>=1;i--)
	{
		if(s[i]>='a'&&s[i]<='z') vis[s[i]-'a']=i;
		for(int j=0;j<26;j++) mp[i][j]=vis[j];
	}
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		int pos=find_name(name[i]);
		if(pos<m) sum+=ans[pos+1]; 
	}
	cout<<sum<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}