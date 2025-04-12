/*
 * @Author: dsaDadas11
 * @Date: 2025-03-21 20:17:45
 * @LastEditTime: 2025-03-21 20:18:11
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
int a[N],cnt[N],pos[N];
bool vis[N];
void init()
{
	for(int i=1;i<=n;i++)
	{
		cnt[i]=0;
		pos[i]=0;
		vis[i]=0;
	}
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++) cin>>a[i];
	init();
	vector<vector<int> > c(n+5,vector<int>(m+5));
	vector<vector<int> > w(n+5,vector<int>(m+5));
    vector<vector<pair<int,int> > > b(m+5,vector<pair<int,int> >(n+5));
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>c[i][j];
			if(a[j]>=c[i][j]) cnt[i]++;
		}
		
		for(int j=1;j<=m;j++)
		{
			cin>>w[i][j];
		}
	}
	
    for(int j=1;j<=m;j++)
    {
        for(int i=1;i<=n;i++)
        {
            b[j][i]={c[i][j],i};
        }
    }

    for(int j=1;j<=m;j++)
    {
        sort(b[j].begin()+1,b[j].begin()+1+n);
    }

	queue<int> q;
	for(int i=1;i<=n;i++)
	{
		if(cnt[i]==m)
		{
			q.push(i);
		}
	}

	int ans=0;
	while(!q.empty())
	{
		int p=q.front();
		q.pop();
		if(vis[p]) continue;
		vis[p]=1;
		ans++;
		
		for(int j=1;j<=m;j++)
		{
			a[j]+=w[p][j];

		}
		
        for(int j=1;j<=m;j++)
        {
            while(pos[j]+1<=n&&a[j]>=b[j][pos[j]+1].first)
            {
                pos[j]++;
                cnt[b[j][pos[j]].second]++;
                if(cnt[b[j][pos[j]].second]==m&&!vis[b[j][pos[j]].second])
                {
                    q.push(b[j][pos[j]].second);
                }
            }
        }
	}
	
	if(ans==n) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}