/*
 * @Author: dsaDadas11
 * @Date: 2024-01-20 20:31:26
 * @LastEditTime: 2024-01-20 20:31:31
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
const int N=1e6+7;
const int M=2e3+7;
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T; cin>>T;
    for(int i=1;i<=T;i++)
    {
        int ans=0;
        int n,m; cin>>n>>m;
       if(2*n>=m)
       {
           ans=(n+m)/3;
       }
        else
        {
            ans=n;
        }
        cout<<ans<<endl;
    }
	return 0;
}