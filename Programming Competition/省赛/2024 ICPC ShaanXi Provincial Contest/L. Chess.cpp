/*
 * @Author: dsaDadas11
 * @Date: 2024-09-02 18:46:32
 * @LastEditTime: 2024-09-02 18:46:41
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int x;
void solve()
{
	cin>>x;
	if(x%2)
	{
		cout<<"2"<<endl;
		return;
	}
	for(int i=2;i<=x;i++)
	{
		if(x%i)
		{
			cout<<i<<endl;
			return;
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}