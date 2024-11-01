/*
 * @Author: dsaDadas11
 * @Date: 2024-07-17 15:14:35
 * @LastEditTime: 2024-07-17 15:14:41
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
	int a,b,x,y;
	cin>>a>>b>>x>>y;
	swap(a,b);
	x++,y++;
	int s1=(y-1)*b,s2=(x-1)*a,s3=(b-x)*a,s4=(a-y)*b;
	vector<int > v;
	v.push_back(s1);
	v.push_back(s2);
	v.push_back(s4);
	v.push_back(s3);
	sort(v.begin(),v.end());
	cout<<v[3]<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}