/*
 * @Author: dsaDadas11
 * @Date: 2024-03-29 22:37:12
 * @LastEditTime: 2024-03-29 22:38:05
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
    cout<<"434"<<endl;
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
int month[17]={0,31,29,31,30,31,30,31,31,30,31,30,31};
void solve()
{
	//2
	int week=2;
	int ans=0;
	for(int i=2025;i<=2276;i++)
	{
		if((i%4==0&&i%100!=0)||(i%400==0)) month[2]=29;
		else month[2]=28;
		for(int j=1;j<=12;j++)
		{
			for(int k=1;k<=month[j];k++)
			{
				week=(week+1)%7;
				if(week==0&&k==13)
				{
					ans++;
				}
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
*/