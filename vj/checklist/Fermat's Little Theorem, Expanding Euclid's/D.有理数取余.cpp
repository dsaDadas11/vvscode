/*
 * @Author: dsaDadas11
 * @Date: 2024-05-21 19:30:45
 * @LastEditTime: 2024-05-21 19:31:06
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int p=19260817;
inline void read(int &x){
	int f=1;x=0;char s=getchar();
	while(s>'9'||s<'0'){if(s=='-')f=-1;s=getchar();}
	while(s<='9'&&s>='0'){x=x*10%p+(s-'0')%p;s=getchar();}//改成了取模
	x=x%p*f;//改成了取模
}
void exgcd(int a,int b,int &x,int &y)
{
	if(!b)
	{
		x=1,y=0;
		return;
	}
	exgcd(b,a%b,x,y);
	int t=x;
	x=y;
	y=t-a/b*y;
}
void solve()
{
	int a,b;
	read(a),read(b);
	if(b==0)
	{
		cout<<"Angry!"<<endl;
		return;
	}
	int x,y;
	exgcd(b,p,x,y);
	cout<<(a*x%p+p)%p<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}