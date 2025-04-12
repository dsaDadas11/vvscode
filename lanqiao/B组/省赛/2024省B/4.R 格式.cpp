/*
 * @Author: dsaDadas11
 * @Date: 2025-04-03 15:27:38
 * @LastEditTime: 2025-04-03 15:28:07
 * @Description: go for it!
 */
/*
 第一次手搓高精度
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
string d;
void solve()
{
	cin>>n>>d;
	int len=d.size();
	reverse(d.begin(),d.end());
	d=' '+d;
	int pos;
	
	for(int i=1;i<=len;i++)
	{
		if(d[i]=='.')
		{
			pos=i;
			break;
		}
	}
	string c=" ";
	for(int i=1;i<=len;i++)
	{
		if(d[i]=='.') continue;
		c.push_back(d[i]);
	}
	len--;

	for(int i=1;i<=n;i++)
	{
		int up=0;
		for(int j=1;j<=len;j++)
		{
			int a=c[j]-'0';
			a<<=1;
			a+=up;
			up=0;
			if(a>=10)
			{
				a-=10;
				up=1;
			}
			c[j]='0'+a;
		}
		if(up)
		{
			c.push_back('1');
			len++;
		}
	}
	
	int up=0;
	if(c[pos-1]-'0'>=5)
	{
		up=1;
		for(int j=pos;j<=len;j++)
		{
			int a=c[j]-'0';
			a+=up;
			up=0;
			if(a>=10)
			{
				a-=10;
				up=1;
			}
			c[j]='0'+a;
		}
	}
	for(int i=len;i>=pos;i--) cout<<c[i];
	
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}