/*
 * @Author: dsaDadas11
 * @Date: 2024-11-07 10:40:00
 * @LastEditTime: 2024-11-07 22:46:00
 * @Description: go for it!
 */
/*
 解题思路：
 遍历1-n，每次只给R一个点，然后看B是否符合条件，
 除了 3 3 3 3这种情况，似乎都符合
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
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	// 选一个R
	for(int i=1;i<=n;i++)
	{
		int maxn=0,minn=1e10;
		for(int j=1;j<=n;j++)
		{
			if(j==i) continue;
			maxn=max(maxn,a[j]);
			minn=min(minn,a[j]);
		}
		if(maxn-minn==0) continue;
		cout<<"YES"<<endl;
		for(int j=1;j<=n;j++)
		{
			if(j==i) cout<<'R';
			else cout<<"B";
		}
		cout<<endl;
		return;
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
题解代码：
确实只有 3 3 3 这样子的不行，其他都可行
有一个点：s[1]='B'
因为如果B取0的话，1 2 2 就可以hack，
所以我们不能取最小值，而是取第二小的，使R中maxn-minn!=0

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
	if(a[1]==a[n]) return cout<<"NO"<<endl,void();
	cout<<"YES"<<endl;
	string s(n,'R');
	s[1]='B';
	cout<<s<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}
*/