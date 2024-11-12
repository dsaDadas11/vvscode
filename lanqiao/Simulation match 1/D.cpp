/*
 * @Author: dsaDadas11
 * @Date: 2024-11-09 12:25:55
 * @LastEditTime: 2024-11-09 13:14:30
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int month[15]={0,31,28,31,30,31,30,31,31,30,31,30,31};
void solve()
{
	int ans=0;
	int st=2; // 星期二
	// 年份
	for(int i=1901;i<=2024;i++)
	{
		if((i%4==0&&i%100!=0)||(i%400==0)) month[2]=29;
		else month[2]=28;

		// 月
		for(int j=1;j<=12;j++)
		{
			// 日
			for(int k=1;k<=month[j];k++)
			{
				if((k%10==1)&&st==1) ans++;
				st++;
				if(st==8) st=1;
			}
		}
	}
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}