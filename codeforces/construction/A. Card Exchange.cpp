/*
 * @Author: dsaDadas11
 * @Date: 2024-08-28 21:02:43
 * @LastEditTime: 2024-08-28 21:03:02
 * @Description: go for it!
 */
//URL:https://codeforces.com/problemset/problem/1966/A
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,k;
int a[107];
int b[107];
bool cmp(int x,int y)
{
	return x>y;
}
void solve()
{
	cin>>n>>k;
	memset(b,0,sizeof b);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[a[i]]++;
	}
	sort(b+1,b+1+100,cmp);
	int ans=0;
	while(1)
	{
		if(b[1]<k) break;
		if(b[1]>k)
		{
			b[1]--;
		}
		else
		{
			b[1]-=k;
			b[2]+=k-1;
		}
		sort(b+1,b+1+100,cmp);
		ans++;
	}
	cout<<n-ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}