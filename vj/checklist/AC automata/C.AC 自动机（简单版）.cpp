/*
 * @Author: dsaDadas11
 * @Date: 2024-07-23 23:41:38
 * @LastEditTime: 2024-07-23 23:55:56
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int trie[N][26];
int cnt[N],fail[N]; 
int idx;
void insertWords(string s)
{
	int p=0;
	int len=s.size();
	for(int i=0;i<len;i++)
	{
		int u=s[i]-'a';
		if(!trie[p][u]) trie[p][u]=++idx;
		p=trie[p][u];
	}
	cnt[p]++;
}
void getFail()
{
	queue<int> q;
	for(int i=0;i<26;i++)
	{
		if(trie[0][i])
		{
			fail[trie[0][i]]=0;
			q.push(trie[0][i]);
		}
	}
	while(!q.empty()){
		int now=q.front();
		q.pop();
		for(int i=0;i<26;i++)
		{
			if(trie[now][i])
			{
				fail[trie[now][i]] = trie[fail[now]][i];
				q.push(trie[now][i]);
			}
			else trie[now][i]=trie[fail[now]][i];
		}
	}
}
int query(string s)
{
	int now=0,ans=0;
	int len=s.size();
	for(int i=0;i<len;i++)
	{
		now=trie[now][s[i]-'a'];
		for(int j=now;j!=0&&cnt[j]!=-1;j=fail[j])
		{
			ans+=cnt[j];
			cnt[j]=-1;
		}
	}
	return ans;
}
void solve()
{
	int n;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		insertWords(s);
	}
	fail[0]=0;
	getFail();
	cin>>s ;
	cout<<query(s)<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}


