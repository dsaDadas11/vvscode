/*
 * @Author: dsaDadas11
 * @Date: 2024-07-23 23:41:11
 * @LastEditTime: 2024-07-23 23:41:21
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=3e6+7;
constexpr int M=2e3+7;
int n,q,idx;
int cnt[N],trie[N][76]; //看题目给字符范围
string s;
void inser(string S)
{
	int len=S.size();
	int p=0;
	for(int i=0;i<len;i++)
	{
		int u=S[i]-'0';
		if(!trie[p][u]) trie[p][u]=++idx;
		p=trie[p][u];
		cnt[p]++;
	}
}
int query(string S)
{
	int len=S.size();
	int p=0;
	for(int i=0;i<len;i++)
	{
		int u=S[i]-'0';
		if(!trie[p][u]) return 0;
		p=trie[p][u];
	}
	return cnt[p];
}
void solve()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		inser(s);
	}
	string t;
	while(q--)
	{
		cin>>t;
		cout<<query(t)<<endl;
	}
	for(int i=0;i<=idx;i++)
	{
		for(int j=0;j<76;j++) trie[i][j]=0;
		cnt[i]=0;
	}
	idx=0;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}