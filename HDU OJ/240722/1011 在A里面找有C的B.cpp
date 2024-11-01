/*
 * @Author: dsaDadas11
 * @Date: 2024-07-22 16:27:35
 * @LastEditTime: 2024-07-24 09:53:09
 * @Description: go for it!
 */
/*
 别闲的没事用map
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
//#define int ll
using namespace std;
constexpr int N=5e5+7;
constexpr int M=2e3+7;
constexpr int mod=1e9+7; 
int base=29;
int p[N],ha1[N],ha2[N],ha3[N],ha4[N],n;
// A      C      B       B1
bool ans[N],ans2[N];
string A,C;
string b[N],b1[N];
void pre()
{
	p[0]=1;
	for(int i=1;i<=5e5+7;i++)
	{
		p[i]=(p[i-1]*base);
	}
}
int get1(int l,int r)
{
	return (ha1[r]-ha1[l-1]*p[r-l+1]);
}
int get2(int l,int r)
{
	return (ha2[r]-ha2[l-1]*p[r-l+1]);
}
int get3(int l,int r)
{
	return (ha3[r]-ha3[l-1]*p[r-l+1]);
}
int get4(int l,int r)
{
	return (ha4[r]-ha4[l-1]*p[r-l+1]);
}
void solve()
{
	cin>>n;
	cin>>A>>C;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i]>>b1[i];
	}
	int lenA=A.size();
	A=' '+A;
	int lenC=C.size();
	C=' '+C;
	// 算C的hash2
	for(int i=1;i<=lenC;i++)
	{
		ha2[i]=(ha2[i-1]*base+C[i]-'a'+1);
	}
	int hashc=get2(1,lenC);
	// 算A的hash1
	for(int i=1;i<=lenA;i++)
	{
		ha1[i]=(ha1[i-1]*base+A[i]-'a'+1);
	}
	// 找B1中的C hash4
	int lenb1;
	for(int i=1;i<=n;i++)
	{
		lenb1=b1[i].size();
		if(lenC>lenb1) continue;
		b1[i]=' '+b1[i];
		for(int j=1;j<=lenb1;j++)
		{
			ha4[j]=(ha4[j-1]*base+b1[i][j]-'a'+1);
		}
		for(int j=1;j<=lenb1-lenC+1;j++)
		{
			if(get4(j,j+lenC-1)==hashc)
			{
				ans2[i]=1;
				break;
			}
		}
	}
	// 找A中的B
	for(int i=1;i<=n;i++)
	{
		if(!ans2[i]) continue;
		int lenb=b[i].size();
		b[i]=' '+b[i];
		for(int j=1;j<=lenb;j++)
		{
			ha3[j]=(ha3[j-1]*base+b[i][j]-'a'+1);
		}
		for(int j=1;j<=lenA-lenb+1;j++)
		{
			if(get1(j,j+lenb-1)==get3(1,lenb))
			{
				ans[i]=1;
				break;
			}
		}
	}
	bool f=0;
	for(int i=1;i<=n;i++)
	{
		if(ans[i]&&ans2[i])
		{
			if(!f) cout<<i;
			else cout<<' '<<i;
			f=1;
		}
		ans[i]=0;
		ans2[i]=0;
	}
	cout<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	pre();
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}

/*
正解：ac自动机用拓扑排序优化，减少fail跳的次数就能过了

#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=5e5+7;
constexpr int M=2e3+7;
constexpr int mod1=1e9+7; 
constexpr int mod2=998244353;
int base1=37;
int base2=233;
int p1[N],p2[N],ha1[N],ha2[N],ha3[N],ha4[N],n;
// A      C      B       B1
int ans[N],ans2[N];
string A,C;
string b[N],b1[N];
int trie[N][26];
int fail[N],vis[N]; 
int idx;
int ind[N],flag[N];
int num[N];
void pre()
{
	p1[0]=1;
	for(int i=1;i<=5e5+7;i++)
	{
		p1[i]=(p1[i-1]*base1)%mod1;
	}
	p2[0]=1;
	for(int i=1;i<=5e5+7;i++)
	{
		p2[i]=(p2[i-1]*base2)%mod2;
	}
}
int get1(int l,int r)
{
	return ((ha1[r]-ha1[l-1]*p1[r-l+1])%mod1+mod1)%mod1;
}
int get2(int l,int r)
{
	return ((ha2[r]-ha2[l-1]*p2[r-l+1])%mod2+mod2)%mod2;
}
int get3(int l,int r)
{
	return ((ha3[r]-ha3[l-1]*p1[r-l+1])%mod1+mod1)%mod1;
}
int get4(int l,int r)
{
	return ((ha4[r]-ha4[l-1]*p2[r-l+1])%mod2+mod2)%mod2;
}
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
void solve()
{
	cin>>n;
	cin>>A>>C;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i]>>b1[i];
	}
	int lenC=C.size();
	C=' '+C;
	// 算C的hash2
	for(int i=1;i<=lenC;i++)
	{
		ha1[i]=((ha1[i-1]*base1+C[i]-'a'+1)%mod1+mod1)%mod1;
		ha2[i]=((ha2[i-1]*base2+C[i]-'a'+1)%mod2+mod2)%mod2;
	}
	int hashc1=get1(1,lenC);
	int hashc2=get2(1,lenC);
	// 找B1中的C hash4
	int lenb1;
	for(int i=1;i<=n;i++)
	{
		lenb1=b1[i].size();
		if(lenC>lenb1) continue;
		b1[i]=' '+b1[i];
		for(int j=1;j<=lenb1;j++)
		{
			ha3[j]=((ha3[j-1]*base1+b1[i][j]-'a'+1)%mod1+mod1)%mod1;
			ha4[j]=((ha4[j-1]*base2+b1[i][j]-'a'+1)%mod2+mod2)%mod2;
		}
		for(int j=1;j<=lenb1-lenC+1;j++)
		{
			if(get4(j,j+lenC-1)==hashc2&&get3(j,j+lenC-1)==hashc1)
			{
				ans2[i]=1;
				break;
			}
		}
	}
	// 找A中的B
	for(int i=1;i<=n;i++)
	{
		if(!ans2[i]) continue;
		insertWords(b[i],i);
	}
	fail[0]=0;
	getFail();
	query(A);
	topu();
	bool f=0;
	for(int i=1;i<=n;i++)
	{
		if(vis[num[i]]&&ans2[i])
		{
			if(!f) cout<<i;
			else cout<<' '<<i;
			f=1;
		}
	}
	cout<<endl;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<=25;j++) trie[i][j]=0;
		fail[i]=0;
		flag[i]=0;
		ans[i]=0;
		ind[i]=0;
		vis[i]=0;
	}
	for(int i=1;i<=n;i++) ans2[i]=0;
	memset(num,0,sizeof num);
	idx=0;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	pre();
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}
*/