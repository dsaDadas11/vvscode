/*
 * @Author: dsaDadas11
 * @Date: 2024-09-23 22:35:12
 * @LastEditTime: 2024-09-23 22:37:13
 * @Description: go for it!
 */
/*
 解题思路：
 这道题有点绕，因为选的r是根据根据字典序排序的，所以我们可以开一个map存他们的对称关系
 然后遍历一遍map的key(first)即是r
 然后根据r操作s[i]就行了
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
string s;
void solve()
{
	cin>>n>>s;
	char c='a'-1;
	map<char,char> mp;
	for(int i=0;i<n;i++)
	{
		mp[s[i]]=s[n-1-i];
	}
	string t="";
	for(auto [c1,c2]:mp)
	{
		t.push_back(c1);
	}
	map<char,char> mp1;
	int len=t.size();
	for(int i=0;i<len;i++)
	{
		mp1[t[i]]=t[len-1-i];
	}
	for(int i=0;i<n;i++)
	{
		s[i]=mp1[s[i]];
	}
	cout<<s<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}