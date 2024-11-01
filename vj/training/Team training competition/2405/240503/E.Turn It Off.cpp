/*
 * @Author: dsaDadas11
 * @Date: 2024-05-07 19:17:28
 * @LastEditTime: 2024-05-07 19:18:01
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,k;
string s;
bool check(int mid)
{
	string s1=s;
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		if(s1[i]=='1')
		{
			for(int j=i;j<=i+mid-1&&j<n;j++)
			{
				s1[j]='0';
			}
			++cnt;
			i=i+mid-1;
			if(cnt==k) break;;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(s1[i]=='1') return 0;
	}
	return 1;
}
void solve()
{
	cin>>n>>k;
	cin>>s;
	int l=1,r=n;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	cout<<l<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}