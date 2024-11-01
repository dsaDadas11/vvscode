/*
 * @Author: dsaDadas11
 * @Date: 2024-02-17 17:00:27
 * @LastEditTime: 2024-02-17 17:00:35
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
	int n; cin>>n;
	if(n==1)
    {
        int x,y,z; cin>>x>>y>>z;
        if(x==y&&z==1) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
    else
    {
        int x1,y1,z1,x2,y2,z2;
        cin>>x1>>y1>>z1>>x2>>y2>>z2;
        if(z1+z2==1&&x1==x2&&y1==y2) cout<<"No"<<endl;
        else if(z1+z2==2&&x1==y2&&y1==x2) cout<<"No"<<endl;
        else if(z1==1&&x1==y1) cout<<"No"<<endl;
        else if(z2==1&&x2==y2) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}