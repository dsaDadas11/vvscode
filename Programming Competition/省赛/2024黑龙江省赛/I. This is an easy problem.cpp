/*
 * @Author: dsaDadas11
 * @Date: 2024-05-14 20:21:53
 * @LastEditTime: 2024-05-14 20:58:50
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
void solve()
{
	int x,ans=0;
	cin>>x;
	while(x)
	{
		if(x&1) ans++;
		x>>=1;
	}
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}

/*
ac代码：用lowbit计算二进制中 1 的个数
原理：lowbit(x)算的是x中最小位的 1 代表的值
例如： lowbit(6) = 10
	6的二进制为 110，最小位的1是第二位，值就是10
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int lowbit(int x)
{
	return x&(-x);
}
void solve()
{
	int x,ans=0;
	cin>>x;
	while(x)
	{
		ans++;
		x-=lowbit(x);
	}
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}
*/