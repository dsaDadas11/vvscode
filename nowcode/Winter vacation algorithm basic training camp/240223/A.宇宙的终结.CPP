/*
 * @Author: dsaDadas11
 * @Date: 2024-02-23 16:16:44
 * @LastEditTime: 2024-02-23 16:16:50
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
	int l,r; cin>>l>>r;
    int p[17]={0,2,3,5,7,11,13,17,19,23,29,31,37};
    bool flag=0;
    for(int i=l;i<=r;i++)
    {
        int cnt=0;
        int t=i;
        for(int j=1;j<=12&&p[j]<=t;j++)
        {
            if(t%p[j]==0)
            {
                t/=p[j];
                cnt++;
            }
        }
        if(cnt==3&&t==1)
        {
            cout<<i<<endl;
            flag=1;
            break;
        }
    }
    if(flag==0) cout<<"-1"<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}