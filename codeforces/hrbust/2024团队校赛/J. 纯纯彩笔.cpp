/*
 * @Author: dsaDadas11
 * @Date: 2024-04-17 15:41:57
 * @LastEditTime: 2024-04-17 15:42:52
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,x,y;
int fen[27];
int ans;
void dfs(int step,int combo,int blood,int score,int num)
{
	if(blood<=0) return;
	if(step==n)
	{
		if(score>=y&&num==x) ans++;
		return;
	}
	if(num<x) dfs(step+1,combo+1,blood,score+fen[step+1]+10*combo,num+1);
	dfs(step+1,0,blood-10,score,num);
}
void solve()
{
	cin>>n>>x>>y;
	ans=0;
	for(int i=1;i<=n;i++) cin>>fen[i];
	dfs(0,0,50,0,0);
	if(ans>=1) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}

/*
二进制枚举：
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,x,y;
int fen[27];
int score,combo;
void solve()
{
	cin>>n>>x>>y;
	for(int i=1;i<=n;i++) cin>>fen[i];
	if(n-x>4)	return cout<<"NO\n",void();
	for(int i=1;i<(1<<n);i++){
		if(__builtin_popcount(i)!=x)	continue;
		score=combo=0;
		for(int j=0;j<n;j++){
			if(i&(1<<j)){
				score+=fen[j+1] + combo*10;
				combo++;
			} 
			else combo=0;
		}
		if(score>=y)	return cout<<"YES\n",void();
	}
	cout<<"NO\n";
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}
*/