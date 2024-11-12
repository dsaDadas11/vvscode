/*
 * @Author: dsaDadas11
 * @Date: 2024-11-03 19:07:56
 * @LastEditTime: 2024-11-03 19:14:24
 * @Description: go for it!
 */
/*
 解题思路：
 看这样一段字符串 AC[3FUN[2CN]]
 那我们按照一般思路应该怎么做？
 逐步拆解
 AC + [3FUN[2CN]]
 AC + [3(FUN+(CNCN))]
 AC + FUNCNCN + FUNCNCN +FUNCNCN
 那么我们将中括号[]里的看成一个整体，然后从最小的括号开始往外推即可
*/
// URL: https://www.luogu.com.cn/problem/P1928
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
string dfs()
{
	char ch;
	char c;
	string ans="";
	int d;
	while(cin>>ch)
	{
		if(ch=='[')
		{
			cin>>d;
			string s=dfs();
			for(int i=1;i<=d;i++) ans+=s;
		}
		else
		{
			if(ch==']') return ans;
			else ans.push_back(ch);
		}
	}
	return ans;
}
void solve()
{
	cout<<dfs()<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}