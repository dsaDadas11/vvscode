/*
 * @Author: dsaDadas11
 * @Date: 2024-05-23 09:10:44
 * @LastEditTime: 2024-05-23 09:10:53
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
struct pque
{
	int stid,queid;
	int tim;
	bool type;
	bool operator<(const pque&that) const
	{
		if(tim==that.tim) return type>that.type;
		return tim>that.tim;
	}
};
struct sque
{
	int num,idx;
	bool operator<(const sque&that) const
	{
		if(num==that.num) return idx<that.idx;
		return num<that.num;
	}
};
int quenum[N];
int last[N];
int ed[N];
int n,m,a,s;
priority_queue<pque> line;
set<sque> se;
void solve()
{
	se.clear();
	while(!line.empty()) line.pop();
	cin>>n>>m;
	pque pp;
	sque ss;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>s;
		last[i]=s;
		pp.stid=i,pp.tim=a,pp.type=1;
		line.push(pp);
	}
	for(int i=1;i<=m;i++)
	{
		quenum[i]=0;
		ed[i]=0;
		ss.idx=i;
		ss.num=0;
		se.insert(ss);
	}
	while(!line.empty())
	{
		pp=line.top();
		line.pop();
		if(pp.type)
		{
			auto t1=*se.begin();
			if(t1.num==0) ed[t1.idx]=pp.tim+last[pp.stid];
			else ed[t1.idx]+=last[pp.stid];
			se.erase(t1);
			t1.num++;
			se.insert(t1);
			quenum[t1.idx]=t1.num;
			pp.tim=ed[t1.idx];
			pp.queid=t1.idx;
			pp.type=0;
			line.push(pp);
		}
		else
		{
			sque t2;
			t2.idx=pp.queid;
			t2.num=quenum[pp.queid];
			sque pos=*se.find(t2);
			se.erase(pos);
			pos.num--;
			se.insert(pos);
			quenum[pos.idx]--;
		}
	}
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		ans=max(ed[i],ans);
	}
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}