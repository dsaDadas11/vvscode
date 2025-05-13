/*
 * @Author: dsaDadas11
 * @Date: 2024-11-03 18:37:31
 * @LastEditTime: 2024-11-03 18:40:19
 * @Description: go for it!
 */
/*
 解题思路：
 注意 -1 -1 -1 跳出循环的判断
*/
// URL: https://www.luogu.com.cn/problem/P1464
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int vis[27][27][27];
int x,y,z;
int func(int a,int b,int c)
{
	if(a<=0||b<=0||c<=0) return 1;
	if(a>20||b>20||c>20)
	{
		if(vis[20][20][20]) return vis[20][20][20];
		return vis[20][20][20]=func(20,20,20);
	}
	if(vis[a][b][c]) return vis[a][b][c];
	if(a<b&&b<c) return vis[a][b][c]=func(a,b,c-1)+func(a,b-1,c-1)-func(a,b-1,c);
	return vis[a][b][c]=func(a-1,b,c)+func(a-1,b-1,c)+func(a-1,b,c-1)-func(a-1,b-1,c-1);
}
void solve()
{
	cout<<"w("<<x<<", "<<y<<", "<<z<<") = "<<func(x,y,z)<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(cin>>x>>y>>z&&(x!=-1||y!=-1||z!=-1)){solve();}
	return 0;
}