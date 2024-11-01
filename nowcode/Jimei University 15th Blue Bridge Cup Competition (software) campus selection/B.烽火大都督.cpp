/*
 * @Author: dsaDadas11
 * @Date: 2024-01-20 20:29:35
 * @LastEditTime: 2024-01-20 20:29:40
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
const int N=1e6+7;
const int M=2e3+7;
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	double a,b,c,d,e; cin>>a>>b>>c>>d>>e;
    int ans=(a+b+c)*(1+1.0*d/100)*1.0*e/100;
    cout<<ans<<endl;
	return 0;
}