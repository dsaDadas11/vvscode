/*
 * @Author: dsaDadas11
 * @Date: 2024-10-14 21:03:38
 * @LastEditTime: 2024-10-15 21:49:14
 * @Description: go for it!
 */
/*
 解题思路：
 这道题是我做过的第一道思想分治，
 先看数据范围：n*m<=180，
 当 n<10 时 n! < 2^m ,此时可以直接算n的排列组合，复杂度为 n!
 当 n>=10 时 n! > 2^m ,此时枚举每个位置选或不选，复杂度为 2^m
 因此平均时间复杂度 < min( n!, 2^m ),
 然后代码的复杂度应该就是这样的吧(尽管没写分治...)
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m;
void solve()
{
	cin>>n>>m;
	vector<vector<int> > a(m+1,vector<int>(n+1));
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	set<vector<int> > ans;
	vector<int> t(n+1);
	for(int i=1;i<=m;i++)
	{
		set<vector<int> > tmp;
		tmp.insert(a[i]);
		for(auto x:ans)
		{
			for(int j=1;j<=n;j++)
			{
				t[j]=x[a[i][j]];
			}
			tmp.insert(t);
		}
		for(auto i:tmp) ans.insert(i);
	}
	cout<<ans.size()<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}