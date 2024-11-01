/*
 * @Author: dsaDadas11
 * @Date: 2024-05-21 18:56:38
 * @LastEditTime: 2024-05-21 19:07:56
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=3e6+7;
int n,p,inv[N];
signed main()
{
	cin>>n>>p;
	inv[1]=1;
	cout<<'1'<<endl;
	for(int i=2;i<=n;i++)
	{
		inv[i]=p-(p/i)*inv[p%i]%p;
		cout<<inv[i]<<endl;
	}
	return 0;
}