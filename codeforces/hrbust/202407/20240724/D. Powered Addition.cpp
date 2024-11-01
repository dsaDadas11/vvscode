/*
 * @Author: dsaDadas11
 * @Date: 2024-07-24 19:51:13
 * @LastEditTime: 2024-07-24 19:53:14
 * @Description: go for it!
 */
/*
 解题思路：因为序列要升序，所以我们要找最大值和当前值的差值，
 然后用二进制遍历差值最前面一位1，加1即为最大second
 一开始以为加的越多越好了....
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
int a[N];
void solve()
{
	cin>>n;
	int maxn=-1e16;
	int ans=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		if(a[i]>=maxn) maxn=a[i];
		else
		{
			int x=maxn-a[i];
			int pos=0;
			for(int i=0;i<=34;i++)
			{
				if(x&(1LL<<i)) pos=i;
			}
			ans=max(ans,pos+1);
		}
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