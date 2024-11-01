/*
 * @Author: dsaDadas11
 * @Date: 2024-07-20 14:28:30
 * @LastEditTime: 2024-07-20 18:17:31
 * @Description: go for it!
 */
/*
  这道题关键在于如何找2^k倍  x&(x-1)==0
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int a,b;
bool flag;
void dfs(int x,int step)
{
	if(x>b) return;
	if(x==0) return;
	if(x==b)
	{
		cout<<step<<endl;
		flag=1;
		return;
	}
	if(!flag&&x<b) dfs(x*8,step+1);
	if(!flag&&x<b) dfs(x*4,step+1);
	if(!flag&&x<b) dfs(x*2,step+1);
	if(x%2==0&&!flag&&x>b) dfs(x/2,step+1);
	if(x%4==0&&!flag&&x>b) dfs(x/4,step+1);
	if(x%8==0&&!flag&&x>b) dfs(x/8,step+1);
}
void solve()
{
	cin>>a>>b;
	flag=0;
	if(a>b) swap(a,b);
	int x=b/a;
	if(b%a==0&&(x&(x-1))==0)
	{
		dfs(a,0);
	}
	else
	{
		cout<<"-1"<<endl;
		return;
	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}