/*
 * @Author: dsaDadas11
 * @Date: 2024-04-16 10:33:12
 * @LastEditTime: 2024-04-16 10:34:42
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
constexpr int mod=1e9+7;
int base=29;
int p[N],ha[N],n;
string s;
void pre()
{
	p[0]=1;
	for(int i=1;i<=1e6;i++)
	{
		p[i]=(p[i-1]*base)%mod;
	}
}
int get(int l,int r)
{
	return ((ha[r]-ha[l-1]*p[r-l+1])%mod+mod)%mod;
}
bool check(int l1,int l2,int len)
{
	int l=1,r=len;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(get(l1,l1+mid-1)==get(l2,l2+mid-1)) l=mid+1;
		else r=mid;
	}
	if(s[l1+l-1]<=s[l2+l-1]) return 1;
	return 0;
}
void solve()
{
	cin>>n>>s;
	s=' '+s;
	if(s[1]<=s[n])
	{
		cout<<'1'<<endl;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		ha[i]=((ha[i-1]*base+s[i]-'a'+1)%mod+mod)%mod;
	}
	for(int i=1,j=n;i<=n&&j>=1;i++,j--)
	{
		if(s[1]<s[j])
		{
			cout<<i<<endl;
			return;
		}
		else if(s[1]==s[j])
		{
			if(check(2,j+1,i-1))
			{
				cout<<i<<endl;
				return;
			}
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	pre();
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}
/*
超时代码（校赛水过）：
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
//#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
string s;
int n;
void solve()
{
	cin>>n;
	cin>>s;
	int ans=0;
	string t1="",t2="";
	for(int i=0;i<n;i++)
	{
		t1.push_back(s[i]);
		t2.insert(t2.begin(),s[n-i-1]);
		if(t2>=t1)
		{
			ans=i;
			break;
		}
	}
	cout<<ans+1<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}
*/