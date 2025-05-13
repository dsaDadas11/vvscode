/*
 * @Author: dsaDadas11
 * @Date: 2024-08-15 15:54:23
 * @LastEditTime: 2024-08-15 15:54:29
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
string fun_sub(string s1,string s2)
{
	memset(a,0,sizeof a);
	memset(b,0,sizeof b);
	memset(c,0,sizeof c);
	bool flag=0;
	if(s1.size()<s2.size()||(s1.size()==s2.size()&&s1<s2))
	{
		swap(s1,s2);
		flag=1;
	}
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
	len=s1.size();
	for(int i=0;i<len;i++)
	{
		if(a[i]<b[i])
		{
			a[i+1]--;
			a[i]+=10;
		}
		c[i]=a[i]-b[i];
	}
	while(c[len-1]==0&&len>1) len--;
	string ans="";
	if(flag) ans="-";
	for(int i=len-1;i>=0;i--)
	{
		ans+=c[i]+'0';
	}
	return ans;
}
void solve()
{
	cin>>s1>>s2;
	cout<<fun_sub(s1,s2)<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}