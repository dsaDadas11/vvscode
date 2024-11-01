/*
 * @Author: dsaDadas11
 * @Date: 2024-02-02 18:56:37
 * @LastEditTime: 2024-02-02 20:11:47
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m,ans;
int a[17],u[17],v[17];
void dfs(int x)
{
	if(x==m+1)
	{
		int cnt=1;
		for(int i=2;i<=n;i++)
		{
			if(a[i]>a[1]) cnt++;
		}
		ans=min(ans,cnt);
		return;
	}
	a[u[x]]+=3;
	dfs(x+1);
	a[u[x]]-=3;
	a[v[x]]+=3;
	dfs(x+1);
	a[v[x]]-=3;
	a[u[x]]+=1;
	a[v[x]]+=1;
	dfs(x+1);
	a[u[x]]-=1;
	a[v[x]]-=1;
}
void solve()
{
	cin>>n>>m;
	ans=1e9;
	memset(a,0,sizeof a);
	memset(u,0,sizeof u);
	memset(v,0,sizeof v);
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i];
	}
	dfs(1);
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}


//GPT给的ac代码

/*
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n, m;
vector<int> scores;
vector<pair<int, int>> matches;
int getHighestRank()
{
	vector<int> tempScores = scores;
	sort(tempScores.rbegin(), tempScores.rend());
	int rank = 1;
	for (int i = 0; i < n; ++i)
	{
		if (tempScores[i] == scores[0])
			return rank;
		if (i + 1 < n && tempScores[i] != tempScores[i + 1])
			rank = i + 2;
	}
	return n;
}
void simulateMatches(int index, int &bestRank)
{
	if (index == m)
	{
		bestRank = min(bestRank, getHighestRank());
		return;
	}
	scores[matches[index].first - 1] += 3;
	simulateMatches(index + 1, bestRank);
	scores[matches[index].first - 1] -= 3;
	scores[matches[index].second - 1] += 3;
	simulateMatches(index + 1, bestRank);
	scores[matches[index].second - 1] -= 3;
	scores[matches[index].first - 1] += 1;
	scores[matches[index].second - 1] += 1;
	simulateMatches(index + 1, bestRank);
	scores[matches[index].first - 1] -= 1;
	scores[matches[index].second - 1] -= 1;
}
void solve()
{
	cin >> n >> m;
	scores.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> scores[i];
	matches.resize(m);
	for (int i = 0; i < m; ++i)
		cin >> matches[i].first >> matches[i].second;
	
	int bestRank = n;
	simulateMatches(0, bestRank);
	cout << bestRank << endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}
*/