/*
 * @Author: dsaDadas11
 * @Date: 2024-02-23 16:17:38
 * @LastEditTime: 2024-02-23 16:17:51
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int f[67];
unordered_map<int,bool> mp;
unordered_map<int,vector<int> > mp2;
void pre()
{
    f[1]=0,f[2]=1;
    for(int i=3;i<=45;i++)
    {
        f[i]=f[i-1]+f[i-2];
    }
    for(int i=1;i<=45;i++)
    {
        for(int j=1;j<=45;j++)
        {
            for(int k=1;k<=45;k++)
            {
                int sum=f[i]+f[j]+f[k];
                mp[sum]=1;
                mp2[sum].push_back(f[i]);
                mp2[sum].push_back(f[j]);
                mp2[sum].push_back(f[k]);
            }
        }
    }
}
void solve()
{
	int n; cin>>n;
    if(mp[n]==1)
    {
        for(int i=0;i<=2;i++)
        {
            cout<<mp2[n][i]<<' ';
        }
        cout<<endl;
    }
    else cout<<"-1"<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    pre();
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}