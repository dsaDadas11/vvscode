#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int tr[M][M];
int n;
int lowbit(int x){return x&(-x);}
void add(int x,int y,int val)
{
	for(int i=x;i<=n;i+=lowbit(i))
	{
		for(int j=y;j<=n;j+=lowbit(j))
		{
			tr[i][j]+=val;
		}
	}
}
int sum(int x,int y)
{
	int ans=0;
	for(int i=x;i;i-=lowbit(i))
	{
		for(int j=y;j;j-=lowbit(j))
		{
			ans+=tr[i][j];
		}
	}
	return ans;
}
void solve()
{
	int op;
	while(cin>>op)
	{
		if(op==0)
		{
			cin>>n;
		}
		else if(op==1)
		{
			int x,y,val;
			cin>>x>>y>>val;
			x++,y++;
			add(x,y,val);
		}
		else if(op==2)
		{
			int l,b,r,t;
			cin>>l>>b>>r>>t;
			l++,r++,b++,t++;
			cout<<sum(r,t)-sum(r,b-1)-sum(l-1,t)+sum(l-1,b-1)<<endl;
		}
		else if(op==3) break;
	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}