/*
 * @Author: dsaDadas11
 * @Date: 2024-02-18 18:30:14
 * @LastEditTime: 2024-02-18 18:30:21
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int bits(int x)
{
    int cnt=0;
    while(x){x/=10,cnt++;}
    return cnt;
}
void solve()
{
    int n; cin>>n;
    int a[1007]={0};
    for(int i=1;i<=n;i++) cin>>a[i];
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i!=j)
            {
                int b=bits(a[j]);
                int sum=a[i]*pow(10,b)+a[j];
                if(sum%36==0) ans++;
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