/*
 * @Author: dsaDadas11
 * @Date: 2024-03-26 20:55:47
 * @LastEditTime: 2024-03-26 20:55:56
 * @Description: go for it!
 */
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
	int n,m,k;
	cin>>n>>m>>k;
	string a,b;
	cin>>a>>b;
	vector<char> c,d;
	for(int i=0;i<n;i++)
	{
		c.push_back(a[i]);
	}
	for(int i=0;i<m;i++)
	{
		d.push_back(b[i]);
	}
	sort(c.begin(),c.end());
	sort(d.begin(),d.end());
	string ans="";
	int op=0;
	int cnt=0;
	if(c[0]<d[0]) op=0;
	else op=1;
	for(int l=0,r=0;l<n&&r<m;)
	{
		if(op==0)
		{
			cnt++;
			ans.push_back(c[l]);
			l++;
			if(d[r]<c[l])
			{
				cnt=k;
			}
		}
		else
		{
			cnt++;
			ans.push_back(d[r]);
			r++;
			if(d[r]>c[l])
			{
				cnt=k;
			}
		}
		if(cnt>=k)
		{
			op=(op+1)%2;
			cnt=0;
		}
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