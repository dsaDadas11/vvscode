/*
 * @Author: dsaDadas11
 * @Date: 2024-07-20 21:18:08
 * @LastEditTime: 2024-07-20 21:34:08
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1048576+7;
constexpr int M=2e3+7;
string A,B;
int p[N],ha[N],n;
int ha2[N];
int base=29;
void pre()
{
	p[0]=1;
	for(int i=1;i<=N;i++)
	{
		p[i]=(p[i-1]*base);
	}
}
int get(int l,int r)
{
	return (ha[r]-ha[l-1]*p[r-l+1]);
}
int get2(int l,int r)
{
	return (ha2[r]-ha2[l-1]*p[r-l+1]);
}
void solve()
{
	map<int,int> mp;
	cin>>A>>B;
	n=A.size();
	string t=A+A;
	int len=t.size();
	t=' '+t;
	for(int i=1;i<=len;i++)
	{
		ha[i]=(ha[i-1]*base+t[i]-'A'+1);
	}
	for(int i=1;i+n-1<=len;i++)
	{
		mp[get(i,i+n-1)]=1;
	}
	int len1=B.size();
	B=' '+B;
	for(int i=1;i<=len1;i++)
	{
		ha2[i]=(ha2[i-1]*base+B[i]-'A'+1);
	}
	int ans=0;
	for(int i=1;i+n-1<=len1;i++)
	{
		ans+=mp[get2(i,i+n-1)];
	}
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	pre();
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}