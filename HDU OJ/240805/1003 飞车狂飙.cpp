/*
 * @Author: dsaDadas11
 * @Date: 2024-08-05 18:19:07
 * @LastEditTime: 2024-08-05 18:19:48
 * @Description: go for it!
 */
/*
 这道题的关键点在于怎么模拟移动
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
string s;
struct Dir
{
	int dir;
	Dir():dir(0){}
	int dx()
	{
		if(dir==1||dir==3) return dir==1?-1:1;
		return 0;
	}
	int dy()
	{
		if(dir==2||dir==0) return dir==2?-1:1;
		return 0;
	}
	void left()
	{
		dir++;
		dir=(dir%4+4)%4;
	}
	void right()
	{
		dir--;
		dir=(dir%4+4)%4;
	}
};
int check()
{
	Dir dd;
	set<pair<int,int> > se;
	int nowx=0,nowy=0;
	se.insert({nowx,nowy});
	for(int i=0;i<n;i++)
	{
		if(s[i]=='L') dd.left();
		else if(s[i]=='R') dd.right();
		nowx+=dd.dx();
		nowy+=dd.dy();
		if(se.count({nowx,nowy})&&i<n-1) return -1;//最后一个不要判断，因为会重合
		se.insert({nowx,nowy});
	}
	if(nowx==0&&nowy==0&&dd.dir==0) return 1;
	return 0;
}
void solve()
{
	cin>>n;
	cin>>s;
	cout<<check()<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}