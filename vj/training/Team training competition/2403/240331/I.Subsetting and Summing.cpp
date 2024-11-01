/*
 * @Author: dsaDadas11
 * @Date: 2024-04-07 22:08:52
 * @LastEditTime: 2024-04-07 22:16:56
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
struct op
{
	int x,y,z;
}vec[N];
int a[3]={0,-1,1};
void solve()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>vec[i].x>>vec[i].y>>vec[i].z;
	}
	int ans=0;
	for(int xi=1;xi<=2;xi++)
	{
		for(int yi=1;yi<=2;yi++)
		{
			for(int zi=1;zi<=2;zi++)
			{
				int res=0;
				for(int i=1;i<=n;i++)
				{
					int resx=a[xi]*vec[i].x;
					int resy=a[yi]*vec[i].y;
					int resz=a[zi]*vec[i].z;
					if(resx+resy+resz>=0)
					{
						res+=resx+resy+resz;
					}
				}
				ans=max(ans,res);
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
	int n;
	cin>>n;
	vector<array<int,3>> a(n);
	for(int i=0;i<n;i++)
	{
		auto &[x,y,z]=a[i];
		cin>>x>>y>>z;
	}
	int ans=0;
	for(auto xi : {-1, +1})
	{
		for(auto yi : {-1, +1})
		{
			for(auto zi : {-1, +1})
			{
				int res=0;
				for (int i = 0; i < n; i++)
				{
					auto &[x,y,z]=a[i];
					int resx=xi*x;
					int resy=yi*y;
					int resz=zi*z;
					if (resx+resy+resz>=0)
					{
						res+=resx+resy+resz;
					}
				}                
				ans=max(ans,res);
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