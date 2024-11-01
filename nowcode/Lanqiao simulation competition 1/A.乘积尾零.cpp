/*
 * @Author: dsaDadas11
 * @Date: 2024-03-28 18:34:10
 * @LastEditTime: 2024-03-28 18:37:04
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
	cout<<"31"<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}
/*
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
void solve()
{
	int c2=0,c5=0;
	for(int i=1;i<=10;i++)
	{
		for(int j=1;j<=10;j++)
		{
			int x; cin>>x;
			while(x%2==0)
			{
				x/=2;
				c2++;
			}
			while(x%5==0)
			{
				x/=5;
				c5++;
			}
		}
	}
	cout<<min(c2,c5)<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}
*/