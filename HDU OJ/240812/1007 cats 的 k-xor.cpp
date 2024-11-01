/*
 * @Author: dsaDadas11
 * @Date: 2024-08-13 15:10:39
 * @LastEditTime: 2024-08-13 15:13:04
 * @Description: go for it!
 */
/*
 解题思路：假设在第i位上有a+b=c或者a+b-k=c
 移项就是a+b-c=0或者a+b-c=k
 因此可得每一位都是k的倍数，所以k一定是a+b-c的因子
 我们只需要暴力寻找因子进行check就行
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int a,b,c;
bool check(int k)
{
	int t1=a,t2=b,t3=c;
	while(t1||t2||t3)
	{
		int s1=t1%k;
		int s2=t2%k;
		int s3=t3%k;
		if((s1+s2)%k!=s3) return 0;
		t1/=k,t2/=k,t3/=k;
	}
	return 1;
}
void solve()
{
	cin>>a>>b>>c;
	if(a+b==c)
	{
		cout<<"-1"<<endl;
		return;
	}
	if(a+b<c)
	{
		cout<<"0"<<endl;
		return;
	}
	int ans=0;
	int d=a+b-c;
	if(check(d)) ans++;
	for(int i=2;i*i<=d;i++)
	{
		if(d%i) continue;
		if(check(i)) ans++;
		if(i*i!=d&&check(d/i)) ans++;
	}
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}