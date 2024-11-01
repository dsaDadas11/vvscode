/*
 * @Author: dsaDadas11
 * @Date: 2024-05-21 12:41:56
 * @LastEditTime: 2024-05-21 12:42:01
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
int x,y,p1,p2,n,m,a,b,l;
int tt;
void exgcd(int a,int b)
{
	if(!b)
	{
		x=1,y=0;
		return;
	}
	exgcd(b,a%b);
	int t=x;
	x=y;
	y=t-a/b*y;
}
signed main()
{
	cin>>p1>>p2>>m>>n>>l;
	b=n-m,a=p1-p2;
	// 处理负数
	if(b<0)
	{
		b=-b;
		a=-a;
	}
	// (n-m)*x+l*y=p1-p2
	exgcd(b,l);
	tt=__gcd(b,l);
	// 裴属定理:如果a不能整除b,l的最小公倍数，方程就不成立
	if(a%tt!=0) cout<<"Impossible"<<endl;
	else cout<<((x*(a/tt))%(l/tt)+(l/tt))%(l/tt)<<endl;// 求最小解
	return 0;
}