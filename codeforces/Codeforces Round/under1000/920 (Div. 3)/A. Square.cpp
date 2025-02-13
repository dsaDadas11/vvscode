/*
 * @Author: dsaDadas11
 * @Date: 2024-01-17 14:54:28
 * @LastEditTime: 2024-01-17 14:54:34
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
const int N=1e6+7;
const int M=2e3+7;
void solve()
{
	int x[5]={0};
	int y[5]={0};
	for(int i=1;i<=4;i++)
		cin>>x[i]>>y[i];
	sort(x+1,x+1+4);
	sort(y+1,y+1+4);
	cout<<(x[4]-x[1])*(y[4]-y[1])<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}