/*
 * @Author: dsaDadas11
 * @Date: 2024-05-28 22:43:14
 * @LastEditTime: 2024-05-29 18:37:14
 * @Description: go for it!
 */
/*
解题思路：
1.首先我们要找小于等于q智商的位置
2.然后再从后往前遍历，找q>=q1的位置(q1初始为1智商，然后从后往前推，记住不是q==q1)
3.找到这个位置之后的所有位置都为1了
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,q;
int a[N];
bool ans[N];
void solve()
{
	for(int i=1;i<=n;i++) ans[i]=0;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<=q) ans[i]=1;
	}
	int q1=1,pos=-1;
	ans[n]=1;
	for(int i=n-1;i>=1;i--)
	{
		if(a[i]>q1)
		{
			q1++;
			ans[i]=0;
		}
		if(q>=q1)
		{
			pos=i;
		}
	}
	if(pos!=-1) for(int i=pos;i<=n;i++) ans[i]=1;
	for(int i=1;i<=n;i++) cout<<ans[i];
	cout<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}

/*
另一ac代码：
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,q;
int a[N];
bool ans[N];
void solve()
{
	for(int i=1;i<=n;i++) ans[i]=0;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<=q) ans[i]=1;
	}
	int q1=1;
	ans[n]=1;
	for(int i=n-1;i>=1;i--)
	{
		if(a[i]>q1) q1++;
		if(q1<=q)
		{
			ans[i]=1;
		}
	}
	for(int i=1;i<=n;i++) cout<<ans[i];
	cout<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}
*/