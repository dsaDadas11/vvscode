/*
 * @Author: dsaDadas11
 * @Date: 2024-07-17 10:08:04
 * @LastEditTime: 2024-07-17 10:51:39
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
void solve()
{
	int n,r,b;
	cin>>n>>r>>b;
	while(b!=0)
	{
        // 每一次重新计算是最保险的,一开始wa了就是没算
		int par=0;
		if(r%(b+1)==0) par=r/(b+1);
		else par=r/(b+1)+1;
		for(int j=1;j<=par;j++) cout<<"R";
		cout<<"B";
		b--,r-=par;
	}
	for(int i=1;i<=r;i++) cout<<"R";
	cout<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}