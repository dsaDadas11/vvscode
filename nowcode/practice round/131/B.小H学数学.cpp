/*
 * @Author: dsaDadas11
 * @Date: 2024-11-01 20:50:49
 * @LastEditTime: 2024-11-01 20:51:23
 * @Description: go for it!
 */
/*
 解题思路：
 纯暴力，别开滚动数组，很容易错而且不容易维护
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e5+7;
constexpr int M=2e4+7;
constexpr int mod=1e9+7;
int x,y;
int ans[N][107];
void solve()
{
	cin>>x>>y;
	y++;
	set<int> se;
	for(int i=1;i<=5;i++)
	{
		for(int j=1;j<=5;j++)
		{
			se.insert(i-j+M);
			se.insert(i+j+M);
			se.insert(-i+j+M);
			se.insert(-i-j+M);
			
			ans[i-j+M][1]++;
			ans[i+j+M][1]++;
			ans[-i+j+M][1]++;
			ans[-i-j+M][1]++;
		}
	}
	for(int i=1;i<=10;i++)
	{
		ans[i+M][1]++;
		ans[-i+M][1]++;
		
		se.insert(i+M);
		se.insert(-i+M);
	}
	for(int i=2;i<=y;i++)
	{
		set<int> tmp;
		for(auto val:se)
		{
			for(int j=1;j<=5;j++)
			{
				for(int k=1;k<=5;k++)
				{
					ans[val+j-k][i]+=ans[val+j-k][i-1];
					ans[val+j-k][i]%=mod;
					
					ans[val+j+k][i]+=ans[val+j+k][i-1];
					ans[val+j+k][i]%=mod;
					
					ans[val-j+k][i]+=ans[val-j+k][i-1];
					ans[val-j+k][i]%=mod;
					
					ans[val-j-k][i]+=ans[val-j-k][i-1];
					ans[val-j-k][i]%=mod;
					
					tmp.insert(val+j-k);
					tmp.insert(val+j+k);
					tmp.insert(val-j+k);
					tmp.insert(val-j-k);
				}
			}
			for(int k=1;k<=10;k++)
			{
				ans[val+k][i]+=ans[val+k][i-1];
				ans[val+k][i]%=mod;
				
				ans[val-k][i]+=ans[val-k][i-1];
				ans[val-k][i]%=mod;
				
				tmp.insert(val+k);
				tmp.insert(val-k);
			}
		}
		for(auto val:tmp)
		{
			se.insert(val);
		}
	}
	cout<<ans[x+M][y]<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}