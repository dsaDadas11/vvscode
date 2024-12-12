/*
 * @Author: dsaDadas11
 * @Date: 2024-12-04 19:50:41
 * @LastEditTime: 2024-12-04 19:50:53
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int ri;
int ri2;
int ri3;
bool check1(int x,int y)
{
	if(x*x+y*y<ri3) return 1;
	return 0;
}
bool check2(int x,int y)
{
	if(x*x+y*y>=ri2) return 0;
	return 1;
}
void solve()
{
	cin>>ri;
	ri2=ri*ri;
	ri3=(ri+1)*(ri+1);
	
	int ans=0;
	for(int i=0;i<=ri;i++)
	{
		int l=0,r=1e8;
		while(l<r)
		{
			int mid=(l+r)>>1;
			if(check1(i,mid)) l=mid+1;
			else r=mid;
		}

		int l1=0,r1=1e8;
		while(l1<r1)
		{
			int mid=(l1+r1)>>1;
			if(check2(i,mid)) l1=mid+1;
			else r1=mid;
		}

		l--;
		if(l1<=ri) ans+=min(l,ri)-l1+1;
	}
	ans-=2;
	ans*=4;
	ans+=4;

	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}