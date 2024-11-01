/*
 * @Author: dsaDadas11
 * @Date: 2024-10-14 18:42:18
 * @LastEditTime: 2024-10-15 21:34:11
 * @Description: go for it!
 */
/*
 解题思路：
 如果字符串后面有右括号，那么输入右括号时只会将光标移到下一位，而不会增加右括号的数量，
 所以一种可能的情况就是所有的括号都是自己输入的，然后判断一下左右括号数量是否匹配即可
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
string s;
void solve()
{
	cin>>s;
	int len=s.size();
	s=' '+s;
	int l=0; // 记录左括号数量
	string ans="";
	for(int i=1;i<=len;i++)
	{
		if(s[i]=='(')
		{
			l++;
			ans.push_back('(');
		}
		else
		{
			ans.push_back(')');
			if(l>0) l--;
		}
	}
	if(l>0) cout<<"impossible"<<endl;
	else
	{
		for(auto c:ans) cout<<c;
		cout<<endl;
	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}