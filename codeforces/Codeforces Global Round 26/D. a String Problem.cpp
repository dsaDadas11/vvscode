/*
 * @Author: dsaDadas11
 * @Date: 2024-11-07 22:28:02
 * @LastEditTime: 2024-11-07 22:35:55
 * @Description: go for it!
 */
/*
 解题思路：
 这道题用到了Z数组(s和s[i,n]的最长公共前缀) // 还好学过有板子，不然真不会做了。。。
 我们先预处理出s[i]的下一个非a位置，就相当于把字符a跳过，
 然后枚举每一个长度是否是每个非a子串的公共前缀的长度，
 并且我们还需要记录每个非a子串前面有多少个a间隔，因为这些子串可以跟a进行连接也是可行的
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int z[N];
int nxt[N]; // nxt[i]为i下一个非a的位置
void get_z(string s)
{
	int len=s.size();
	s=' '+s;
	z[1]=len;
	for(int i=2,l=0,r=0;i<=len;i++)
	{
		if(i<=r) z[i]=min(z[i-l+1],r-i+1);
		while(s[z[i]+1]==s[i+z[i]]) z[i]++;
		if(i+z[i]-1>r) l=i,r=i+z[i]-1;
	}
}
void solve()
{
	string s;
	cin>>s;
	int n=s.size();
	s=' '+s;
	for(int i=0;i<=n+5;i++) z[i]=0;
	nxt[n+1]=n+1;
	for(int i=n;i>=1;i--)
	{
		if(s[i]=='a') nxt[i]=nxt[i+1];
		else nxt[i]=i;
	}
	int pos=nxt[1];
	if(pos==n+1)
	{
		cout<<n-1<<endl;
		return;
	}
	get_z(s.substr(pos));
	int ans=0;
	for(int len=1;len<=n-pos+1;len++)
	{
		bool flag=1;
		int last_pos=pos+len-1;
		int lena=pos-1;
		for(int j=nxt[pos+len];j<=n;j=nxt[j+len])
		{
			if(z[j-pos+1]<len)
			{
				flag=0;
				break;
			}
			lena=min(lena,j-last_pos-1);
			last_pos=j+len-1;
		}
		if(flag) ans+=lena+1;
	}
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}