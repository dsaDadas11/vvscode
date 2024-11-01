/*
 * @Author: dsaDadas11
 * @Date: 2024-08-13 16:19:33
 * @LastEditTime: 2024-08-13 16:22:52
 * @Description: go for it!
 */
/*
 解题思路：即找最长子段和
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e5+7;
constexpr int M=2e3+7;
int n;
int a[N];
int find_max(int l,int r)
{
	int sum=0,b=0;
	for(int i=l;i<=r;i++)
	{
		if(b>0) b+=a[i];
		else b=a[i];
		if(b>sum) sum=b;
	}
	return sum;
}
void solve()
{
	cin>>n;
	int ans1=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ans1+=a[i];
	}
	int ans2=find_max(1,n-1);
	int ans3=find_max(2,n);
	if(max(ans2,ans3)>=ans1) cout<<"NO"<<endl;
	else cout<<"YES"<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}