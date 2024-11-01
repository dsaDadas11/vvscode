#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int pre[N];
int a[N];
void solve()
{
	int n,q,op,l,r,g;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	string s;
	cin>>s;
	s=' '+s;
	int sum0=0,sum1=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='0') sum0^=a[i];
		else sum1^=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		pre[i]=pre[i-1]^a[i];
	}
	cin>>q;
	while(q--)
	{
		cin>>op;
		if(op==1)
		{
			cin>>l>>r;
			sum0^=pre[r]^pre[l-1];
			sum1^=pre[r]^pre[l-1];
		}
		else
		{
			cin>>g;
			if(g==0) cout<<sum0<<' ';
			else cout<<sum1<<' ';
		}
	}
	cout<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}