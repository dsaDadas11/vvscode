/*
 * @Author: dsaDadas11
 * @Date: 2024-01-20 20:31:45
 * @LastEditTime: 2024-01-20 20:31:50
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
	int n,m; cin>>n>>m;
    int ans=0;
    while(n>0)
    {
        ans++;
        n-=m;
        if(m%2)
        {
            m=3*m+1;
        }
        else
        {
            m/=2;
        }
        if(m==1||m==2||m==4)
        {
            ans+=(n/7)*3;
            n%=7;
        }
    }
    cout<<ans<<endl;
	return 0;
}