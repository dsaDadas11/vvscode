/*
 * @Author: dsaDadas11
 * @Date: 2024-10-13 19:45:47
 * @LastEditTime: 2024-10-13 19:48:11
 * @Description: go for it!
 */
/*
 解题思路：
 设x为末尾相同字符的个数，这x个数不会减少，
 有三种可能的情况
 1.x=k 只要找到长度大于k的字符串并从中分离出长度为k的字符串即可
 2.x>k 显然没有解
 3.x<k 找到长度为k−x或2k−x的图块，并从中分离出长度为k−x的图块
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,k;
string s;
bool check()
{
	for(int i=0;i<k;i++)
	{
		if(s[i]!=s[0]) return 0;
	}
	for(int i=0;i+k<n;i++)
	{
		if(s[i]==s[i+k]) return 0;
	}
	return true;
}
void find_pos(int p)
{
	reverse(s.begin(),s.begin()+p);
	s=s.substr(p,(int)s.size()-p)+s.substr(0,p);
	if(check()) cout<<p<<endl;
	else cout<<"-1"<<endl;
}
void solve()
{
	cin>>n>>k;
	cin>>s;
	int cnt=0;
	for(int i=n-1;i>=0;i--)
	{
		if (s[i]==s[n - 1]) cnt++;
		else break;
	}
	if(cnt>k) return cout<<"-1"<<endl,void();
	if(cnt==k)
	{
		int p=n;
		for (int i=n-1-k;i>=0;i--)
		{
			if(s[i]==s[i+k])
			{
				p=i+1;
				break;
			}
		}
		find_pos(p);
	}
	else
	{
		bool flag=0;
		for(int i=0;i<n;i++)
		{
			if(s[i]!=s[n-1]) continue;
			int j=i;
			while(j+1<n&&s[i]==s[j+1]) j++;
			if(j-i+1==k-cnt)
			{
				find_pos(j+1);
				flag=1;
				break;
			}
			else if(j-i+1==2*k-cnt)
			{
				find_pos(i+k-cnt);
				flag=1;
				break;
			}
			i=j;
		}
		if(!flag) find_pos(n);
	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}