/*
 * @Author: dsaDadas11
 * @Date: 2024-09-22 13:53:55
 * @LastEditTime: 2024-09-22 13:55:13
 * @Description: go for it!
 */
/*
 解题思路：
 可以直接判断4的倍数肯定不行，因为必须要a0和a1都为0
 也可以不判断自己写
 具体规律就是将二进制向前移一位(没想到这么简单)
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
int a[37]; // 0-31
int p[37];
void pre()
{
	p[0]=1;
	for(int i=1;i<=32;i++)
	{
		p[i]=p[i-1]*2;
	}
}
void solve()
{
	cin>>n;
	int t=n;
	// if(n%4==0)
	// {
	// 	cout<<"NO"<<endl;
	// 	return;
	// }
	for(int i=0;i<=31;i++) a[i]=1;
	bool flag=0;
	if(n%2==0) flag=1;
	vector<int> v;
	while(n)
	{
		if(n&1) v.push_back(1);
		else v.push_back(0);
		n>>=1;
	}
	while((int)v.size()!=32) v.push_back(0);
	v.push_back(1);
	for(int i=0;i<=31;i++)
	{
		a[i]=v[i+1];
	}
	for(int i=0;i<=31;i++)
	{
		if(a[i]==0) a[i]=-1;
	}
	if(flag) a[0]=0;
	int res=0;
	for(int i=0;i<=31;i++)
	{
		res+=a[i]*p[i];
	}
	if(res!=t)
	{
		cout<<"NO"<<endl;
		return;
	}
	cout<<"YES"<<endl;
	for(int i=0;i<=31;i++)
	{
		cout<<a[i]<<' ';
		if((i+1)%8==0) cout<<endl;
	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	pre();
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}