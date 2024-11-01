/*
 * @Author: dsaDadas11
 * @Date: 2024-07-18 15:29:43
 * @LastEditTime: 2024-07-18 20:17:42
 * @Description: go for it!
 */
/*
  这道题最后异或就剩两种情况：
  1.x x (两个一样的)
  2.x x x (三个一样的)
 假设一个数组为 1 1 1 1 1，最后异或为 1 1 1
 一个数组为 1 1 1 1 1 1，最后异或为 0 0 0
 这个就是三个一样的情况，一开始判断少了，wa了三发... 
 o(n^2)做法
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int a[M];
int pre[M];
void solve()
{
	int n;
	cin>>n;
	memset(pre,0,sizeof pre);
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		pre[i]=pre[i-1]^a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(pre[i]==(pre[n]^pre[i]))
		{
			cout<<"YES"<<endl;
			return;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(pre[i]==(pre[j]^pre[i])&&pre[i]==(pre[n]^pre[j]))
			{
				cout<<"YES"<<endl;
				return;
			}
		}
	}
	cout<<"NO"<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}

/*
 另一个o(n)解法，如果是两个相同的，那么最后异或为0
 如果是三个相同的，最后异或等于本身，只需要看是否有大于2个异或能得到它本身就行

 #include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
int a[N],pre[N];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		pre[i]=pre[i-1]^a[i];
	}
	if(pre[n]==0)
	{
		cout<<"YES"<<endl;
		return;
	}
	int cnt=0,temp=0;
	for(int i=1;i<=n;i++)
	{
		temp^=a[i];
		if(temp==pre[n])
		{
			cnt++;
			temp=0;
		}
	}
	if(cnt>=2) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}
*/