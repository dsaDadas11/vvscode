/*
 * @Author: dsaDadas11
 * @Date: 2025-01-12 21:14:58
 * @LastEditTime: 2025-01-12 21:20:36
 * @Description: go for it!
 */
/*
 解题思路：
 题目的意思是要按条件构造一个图形，这个图形中所有的 # 要是四方向连通或八方向连通
 第一行和第七行行为 a,b
 要使 a,b中的 #相互连通，那么就得将第二行和第六行都构造成八方向连通(四方向连通要求高很难构造)
 因为 1，2和 6，7已经互相连通了，只需要 3和 5找到一个 #即可
 然后第 4行根据 abs(p1-p2)的大小决定四方向连通还是八方向连通

 特判：
 当 a,b全满时可以，
 当 a,b只有一个满时不可以
 当 a或 b为空可以，将中间填满可以
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
string a,b;
void solve()
{
	cin>>n;
	cin>>a>>b;
	string emp(n,'.'),ful(n,'#');
	if(a==ful&&b==ful)
	{
		cout<<"Yes"<<endl;
		for(int i=1;i<=7;i++) cout<<a<<endl;
		return;
	}
	if(a==ful||b==ful)
	{
		cout<<"No"<<endl;
		return;
	}
	if(a==emp||b==emp)
	{
		cout<<"Yes"<<endl;
		cout<<a<<endl;
		for(int i=1;i<=5;i++) cout<<ful<<endl;
		cout<<b<<endl;
		return;
	}
	cout<<"Yes"<<endl;
	string ans[7];
	for(int i=0;i<7;i++)
	{
		ans[i]=string(n,'.');
	}
	ans[0]=a,ans[6]=b;
	for(int i=0;i<n;i++)
	{
		if(a[i]=='.') ans[1][i]='#';
		if(b[i]=='.') ans[5][i]='#';
	}
	int p1=-1,p2=-1;
	for(int i=0;i<n;i++)
	{
		if(((i>0&&ans[1][i-1]=='#')||(i<n-1&&ans[1][i+1]=='#'))&&ans[1][i]=='.'&&p1==-1) ans[2][i]='#',p1=i;
		if(((i>0&&ans[5][i-1]=='#')||(i<n-1&&ans[5][i+1]=='#'))&&ans[5][i]=='.'&&p2==-1) ans[4][i]='#',p2=i;
	}
	if(abs(p1-p2)<=1) ans[3][p1]='#';
	else
	{
		if(p1>p2) swap(p1,p2);
		for(int i=p1+1;i<p2;i++) ans[3][i]='#';
	}
	for(int i=0;i<7;i++) cout<<ans[i]<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}