/*
 * @Author: dsaDadas11
 * @Date: 2024-08-15 15:47:14
 * @LastEditTime: 2024-08-15 15:47:21
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
string s1,s2;
int a[N],b[N],c[N];
string fun_add(string s1,string s2)
{
	memset(a,0,sizeof a);
	memset(b,0,sizeof b);
	memset(c,0,sizeof c);
	int len=s1.size();
	for(int i=0;i<len;i++)
	{
		a[len-1-i]=s1[i]-'0';
	}
	len=s2.size();
	for(int i=0;i<len;i++)
	{
		b[len-1-i]=s2[i]-'0';
	}
	if((int)s1.size()>len) len=s1.size();
	for(int i=0;i<len;i++)
	{
		// 相加
		c[i]+=a[i]+b[i];
		if(c[i]>=10)
		{
			c[i+1]+=c[i]/10;
			c[i]%=10;
		}
	}
	if(c[len]>0) len++;
	string ans="";
	for(int i=len-1;i>=0;i--)
	{
		ans+=c[i]+'0';
	}
	return ans;
}
void solve()
{
	cin>>s1>>s2;
	cout<<fun_add(s1,s2)<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}