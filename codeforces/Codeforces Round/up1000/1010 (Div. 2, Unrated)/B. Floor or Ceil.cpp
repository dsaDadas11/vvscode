/*
 * @Author: dsaDadas11
 * @Date: 2025-04-14 15:32:36
 * @LastEditTime: 2025-04-14 15:46:59
 * @Description: go for it!
 */
/*
 解题思路：
 有一种情况是 x=1时向上取整会导致一直为 1，因此可以提前跳出循环，并且也不能特判 n+m>30
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
void find_max(int x,int n,int m)
{
	while(n&&x)
    {
        n--;
        x>>=1;
    }
    while(m&&x>1)
    {
        m--;
        x=(x+1)>>1;
    }
	cout<<x<<endl;
}
void find_min(int x,int n,int m)
{
	while(m&&x>1)
    {
        m--;
        x=(x+1)>>1;
    }
    while(n&&x)
    {
        n--;
        x>>=1;
    }
	cout<<x<<' ';
}
int x,n,m;
void solve()
{
	cin>>x>>n>>m;
	find_min(x,n,m);
	find_max(x,n,m);
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}