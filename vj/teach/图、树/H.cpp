/*
 * @Author: dsaDadas11
 * @Date: 2025-10-28 15:21:06
 * @LastEditTime: 2025-10-28 15:21:16
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
string mid,lst;
int pm[28],pl[28];
void dfs(int ml,int mr,int tl,int tr)
{
	
	if(ml>mr||tl>tr) return;
	
	// 先找根
	char ch=lst[tr];
	
	cout<<ch;
	
	int posz=pm[ch-'A'+1];
	int len1=posz-ml;
	
	
	dfs(ml,posz-1,tl,tl+len1-1);
	dfs(posz+1,mr,tl+len1,tr-1);
}
void solve()
{
	cin>>mid>>lst;
	n=mid.size();
	mid=' '+mid;
	lst=' '+lst;
	
	for(int i=1;i<=n;i++)
	{
		pm[mid[i]-'A'+1]=i;
		pl[lst[i]-'A'+1]=i;
	}
	
	// cout<<pm['A'-'A'+1];
	
	dfs(1,n,1,n);
}
signed main()
{
	 ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}