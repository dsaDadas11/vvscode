/*
 * @Author: dsaDadas11
 * @Date: 2024-09-28 11:15:36
 * @LastEditTime: 2024-09-28 11:16:49
 * @Description: go for it!
 */
/*
 解题思路：
 这道题就是找一个或两个递增序列，
 如果是两个递增序列，那么前一个的最小值要大于后面一个的最大值
 一定要设好初始值，不然很难想到边界错误
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
int a[57];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	int d1=a[1]; //构造递增序列最小/最大值
	int pos=2,pos2=-1;
	for(int i=1;i<n;i++)
	{
		if(a[i]<=a[i+1])
		{
			d1=min(d1,a[i+1]);
			d1=min(d1,a[i]);
		}
		else
		{
			pos=i+1;
			break;
		}
	}
	int d2=a[pos];
	for(int i=pos;i<n;i++)
	{
		if(a[i]<=a[i+1])
		{
			d2=max(d2,a[i]);
			d2=max(d2,a[i+1]);
		}
		else
		{
			pos2=i+1;
			break;
		}
	}
	int cnt=1;
	for(int i=1;i<n;i++)
	{
		if(a[i]<=a[i+1]) cnt++;
		else break;
	}
	if(cnt==n)
	{
		cout<<"YES"<<endl;
	}
	else
	{
		if(pos2==-1&&d1>=d2) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}