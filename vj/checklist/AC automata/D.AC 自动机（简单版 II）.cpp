#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e5+7;
constexpr int M=2e3+7;
int trie[N][26];
int cnt[N],fail[N]; 
int idx;
int num[N],ans[N];
void insertWords(string s,int pos)
{
	int p=0;
	int len=s.size();
	for(int i=0;i<len;i++)
	{
		int u=s[i]-'a';
		if(!trie[p][u]) trie[p][u]=++idx;
		p=trie[p][u];
		//cnt[p]++;
	}
	//cnt[p]++;
	num[p]=pos;
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
void query(string s)
{
	int now=0;
	int len=s.size();
	for(int i=0;i<len;i++)
	{
		now=trie[now][s[i]-'a'];
		for(int j=now;j!=0;j=fail[j])
		{
			ans[num[j]]++;
		}
	}
}
int n;
string s[N];
void solve()
{
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		insertWords(s[i],i);
	}
	fail[0]=0;
	getFail();
	string t;
	cin>>t;
	//cout<<query(s)<<endl;
	query(t);
	int maxn=0;
	for(int i=1;i<=n;i++)
	{
		maxn=max(maxn,ans[i]);
	}
	cout<<maxn<<endl;
	for(int i=1;i<=n;i++)
	{
		if(ans[i]==maxn)
		{
			cout<<s[i]<<endl;
		}
	}
	for(int i=0;i<=idx;i++)
	{
		for(int j=0;j<=25;j++) trie[i][j]=0;
		cnt[i]=0;
		fail[i]=0;
	}
	memset(num,0,sizeof num);
	for(int i=0;i<=n;i++) ans[i]=0;
	idx=0;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//	int T=1; cin>>T;
//	while(T--){solve();}
	while(cin>>n&&n){solve();}
	return 0;
}