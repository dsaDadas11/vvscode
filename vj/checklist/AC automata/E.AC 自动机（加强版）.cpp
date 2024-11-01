/*
 * @Author: dsaDadas11
 * @Date: 2024-07-24 09:37:54
 * @LastEditTime: 2024-07-24 09:54:00
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=2e6+7;
constexpr int M=2e3+7;
int trie[N][26];
int cnt[N],fail[N]; 
int idx;
int ind[N],flag[N];
int num[N],ans[N];
int vis[N];
void insertWords(string s,int pos)
{
	int p=0;
	int len=s.size();
	for(int i=0;i<len;i++)
	{
		int v=s[i]-'a';
		if(!trie[p][v]) trie[p][v]=++idx;
		p=trie[p][v];
	}
	if(!flag[p]) flag[p]=pos;
	num[pos]=flag[p];
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
	while(!q.empty())
	{
		int now=q.front();
		q.pop();
		for(int i=0;i<26;i++)
		{
			if(trie[now][i])
			{
				fail[trie[now][i]] = trie[fail[now]][i];
				ind[fail[trie[now][i]]]++;
				q.push(trie[now][i]);
			}
			else trie[now][i]=trie[fail[now]][i];
		}
	}
}
void query(string s)
{
	int now=0;
	int len=s.size();
	for(int i=0;i<len;i++)
	{
		now=trie[now][s[i]-'a'];
		// 不用暴力跳fail了，直接打上标记就行了
		ans[now]++;
	}
}
void topu()
{
	queue<int> q;
	for(int i=1;i<=idx;i++)
	{
		if(ind[i]==0) q.push(i);
	}
	while(!q.empty())
	{
		int now=q.front();
		q.pop();
		vis[flag[now]]=ans[now];
		int v=fail[now];
		ind[v]--;
		ans[v]+=ans[now];
		if(ind[v]==0) q.push(v);
	}
}
int n;
string s[N];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		insertWords(s[i],i);
	}
	fail[0]=0;
	getFail();
	string t;
	cin>>t;
	query(t);
	topu();
	for(int i=1;i<=n;i++)
	{
		cout<<vis[num[i]]<<endl;
	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}