/*
 * @Author: dsaDadas11
 * @Date: 2024-01-24 21:27:54
 * @LastEditTime: 2024-01-24 21:28:01
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=2e5+7;
constexpr int M=2e3+7;
int ans[N];
bool cmp(int x,int y)
{
	return x>y;
}
void solve()
{
	memset(ans,0,sizeof ans);
	int n; cin>>n;
	string s; cin>>s;
	s=' '+s;
	int tot=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='L')
		{
			tot+=i-1;
			ans[i]=n-i-(i-1);
		}
		else
		{
			tot+=n-i;
			ans[i]=i-1-(n-i);
		}
	}
	sort(ans+1,ans+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		if(ans[i]>0) tot+=ans[i];
		cout<<tot<<" ";
	}
	cout<<endl;
}
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}