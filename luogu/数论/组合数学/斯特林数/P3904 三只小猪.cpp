/*
 * @Author: dsaDadas11
 * @Date: 2025-09-19 11:29:02
 * @LastEditTime: 2025-09-19 11:29:13
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m;
string S[57][57];
int a[57],b[57],c[57];
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
string fun_mul(string s,int b)
{
	memset(a,0,sizeof a);
	memset(c,0,sizeof c);
	int len=s.size();
	for(int i=0;i<len;i++)
	{
		a[len-1-i]=s[i]-'0';
	}
	for(int i=0;i<len;i++)
	{
		c[i]+=a[i]*b;
		if(c[i]>=10)
		{
			c[i+1]+=c[i]/10;
			c[i]%=10;
		}
	}
	while(c[len]>0)
	{
		if(c[len]>=10)
		{
			c[len+1]=c[len]/10;
			c[len]%=10;
		}
		len++;
	}
	while(c[len-1]==0&&len>1) len--;
	string ans="";
	for(int i=len-1;i>=0;i--)
	{
		ans+=c[i]+'0';
	}
	return ans;
}
void solve()
{
    cin>>n>>m;
    if(n<m)
    {
        cout<<0<<endl;
        return;
    }
    S[0][0]='1';
    for(int i=1;i<=n;i++) S[i][0]='0',S[i][i]='1';
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<i;j++)
        {
            S[i][j]=fun_add(S[i-1][j-1],fun_mul(S[i-1][j],j));
        }
    }
    cout<<S[n][m]<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}