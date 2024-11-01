/*
 * @Author: dsaDadas11
 * @Date: 2024-07-29 14:45:46
 * @LastEditTime: 2024-07-29 14:58:31
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m,hp,dmg;
char a[M];
string s="EABCD";
void solve()
{
	cin>>n>>m>>hp>>dmg;
	int k=hp/m;
	int yu=hp%m;
	for(int i=1;i<=yu;i++)
	{
		a[i]=s[(k%5+1)%5];
	}
	for(int i=yu+1;i<=m;i++)
	{
		if(k>0) a[i]=s[k%5];
		else a[i]=' ';
	}
	for(int i=yu;i>=1;i--)
	{
		if(dmg==0) break;
		a[i]='.';
		dmg--;
	}
	for(int i=m;i>=1;i--)
	{
		if(a[i]==s[(k%5+1)%5]) break; // 因为要覆盖，所以加一个特判
		if(dmg==0) break;
		a[i]='.';
		dmg--;
	}
	cout<<"+";
	for(int i=1;i<=m;i++) cout<<"-";
	cout<<"+"<<endl;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=m+1;j++)
		{
			if(j==0||j==m+1) cout<<"|";
			else cout<<a[j];
		}
		cout<<endl;
	}
	cout<<"+";
	for(int i=1;i<=m;i++) cout<<"-";
	cout<<"+"<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}