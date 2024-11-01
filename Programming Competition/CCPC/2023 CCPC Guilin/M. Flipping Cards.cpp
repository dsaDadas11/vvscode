/*
 * @Author: dsaDadas11
 * @Date: 2024-10-14 19:56:00
 * @LastEditTime: 2024-10-15 21:42:32
 * @Description: go for it!
 */
/*
 解题思路：
 直接二分答案，
 1.如果a[i]>=mid,b[i]>=mid,那么交换后贡献不变
 2.如果a[i]<mid,b[i]>=mid，贡献为+1
 3.如果a[i]>=mid,b[i]<mid，贡献为-1
 然后算连续的子段的贡献最大是多少，
 判断a数组中除这个子段外的贡献+这个子段的贡献是否大于一半
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
int a[N],b[N];
int half;
bool check(int x)
{
	int cnt1=0,cnt2=0;
	int t=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>=x) cnt1++,t--;
		if(b[i]>=x) t++;
		cnt2=max(cnt2,t);
		t=max(t,0LL);
	}
	return (cnt1+cnt2)>=half;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
	half=(n+1)/2;
	int l=1,r=1e9;
	while(l<r)
	{
		int mid=(l+r+1)>>1;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	cout<<l<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}