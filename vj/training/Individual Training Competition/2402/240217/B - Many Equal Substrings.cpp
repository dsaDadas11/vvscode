/*
 * @Author: dsaDadas11
 * @Date: 2024-02-17 20:29:44
 * @LastEditTime: 2024-02-18 16:54:18
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
void solve()
{
	int n,k; cin>>n>>k;
	string t; cin>>t;
	int pos=0;
	for(int i=0;i<n;i++)
	{
		if(t.substr(0,i)==t.substr(n-i,i)) pos=i;
	}
	cout<<t;
	for(int i=1;i<k;i++) cout<<t.substr(pos);
	cout<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}


/*
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
void solve()
{
	int n,k; cin>>n>>k;
	string s; cin>>s;
	int i,j;
	for(i=1;i<n;i++)
	{
		bool flag=1;
		for(int j=0;j+i<n;j++)
		{
			if(s[j]!=s[j+i])
			{
				flag=0;
				break;
			}
		}
		if(flag) break;
	}
	string s1="";
	for(int a=n-i;a<n;a++) s1.push_back(s[a]);
	for(int i=1;i<k;i++) s+=s1;
	cout<<s<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}
*/