/*
 * @Author: dsaDadas11
 * @Date: 2024-03-25 21:43:24
 * @LastEditTime: 2024-03-26 13:55:41
 * @Description: go for it!
 */
// 打表
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
//#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int sg[N];
bool mex[M];
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(int i=1;i<=1000000;i++)
	{
		int q1=sqrt(i);
		int q2=q1*q1;
		int cnt=0;
		for(int j=0;j<=q1+1;j++) mex[j]=0;
		for(int j=0;j<=q1;j++)
		{
			if(j==0&&i==q2) continue;
			mex[sg[i-(i-q2+j*q1)]]=1;
		}
		while(mex[cnt]) ++cnt;
		sg[i]=cnt;
	}
	int n,t;
	int ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		ans^=sg[t];
	}
	if(ans==0) cout<<"Second"<<endl;
	else cout<<"First"<<endl;
	return 0;
}
/*
dfs超时代码
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
//#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int a[N],f[N];
int n;
int sg(int x)
{
	if(f[x]!=-1) return f[x];
	unordered_set<int> S;
	int q1=sqrt(x);
	int q2=q1*q1;
	for(int j=0;j<=q1;j++)
	{
		if(j==0&&q2==x) continue;
		if(x>=x-q2+j*q1) S.insert(sg(q2-j*q1));
	}
	for(int i=0;;i++)
	{
		if(!S.count(i)) return f[x]=i;
	}
}
void solve()
{
    cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	memset(f,-1,sizeof f);
	int ans=0;
	for(int i=1;i<=n;i++) ans^=sg(a[i]);
	if(ans==0) cout<<"Second"<<endl;
	else cout<<"First"<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}
*/