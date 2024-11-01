/*
 * @Author: dsaDadas11
 * @Date: 2024-10-02 13:19:24
 * @LastEditTime: 2024-10-02 16:31:07
 * @Description: go for it!
 */
/*
 看数据范围1e3,并且输出提示了我们可以n^2模拟
 这道题手玩一下就有思路了，比如
 a: 1 2 6 3 4 5 7 8 9
 b: 1 2 3 4 5 6 7 8 9
 因为在b中1 2的顺序不变，所以我们只能用方法1给它们挪到后面，
 即变为 6 3 4 5 7 8 9 1 2
 根据b中3 4 5 6的顺序我们就应该用方法2调位置
 即变为 6 7 8 9 1 2 3 4 5
 然后用方法一变为 1 2 3 4 5 6 7 8 9
 这里我们能有启发：若在b中 a1在a2后面，那么它们顺序就是相同的，就用方法1
                        若 a1在a2前面，就说明它们是逆序，用方法2将位置调换
 最后判断一下a是否等于b就行了
 怎么判断它们的顺序呢?
 用se[j] 存j前面出现过的数(包括j)，如果出现过则是逆序，否则正序，具体看代码就懂了
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e3+7;
constexpr int M=2e3+7;
int n,x;
set<int> se[N];
void solve()
{
	vector<int> a,b;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		a.push_back(x);
	}
	for(int i=0;i<n;i++)
	{
		cin>>x;
		b.push_back(x);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i;j>=0;j--)
		{
			se[b[i]].insert(b[j]); // a[i] 前面的数
		}
	}
	bool flag=0;
	while(!flag)
	{
		if(a[n-1]==b[n-2]&&a[0]==b[n-1])
		{
			cout<<"1";
			x=a[0];
			a.erase(a.begin());
			a.push_back(x);
		}
		else
		{
			if(!se[a[0]].count(a[1]))
			{
				cout<<"1";
				x=a[0];
				a.erase(a.begin());
				a.push_back(x);
			}
			else
			{
				cout<<"2";
				x=a[1];
				a.erase(a.begin()+1);
				a.push_back(x);
			}
		}
		flag=1;
		for(int i=0;i<n;i++)
		{
			if(a[i]!=b[i]) flag=0;
		}
	}
	cout<<endl;
	for(int i=0;i<=n;i++) se[i].clear();
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}