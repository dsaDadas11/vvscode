#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int a[N];
void solve()
{
	int n; cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	int st=0,ed=-1;
	for(int i=1;i<n;i++)
	{
		if(st==0&&a[i]==a[i+1]) st=i+1;
		if(a[i]==a[i+1]) ed=i;
	}
	if(ed>st) cout<<ed-st<<endl;
	else if(ed==st) cout<<"1"<<endl;
	else cout<<"0"<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}