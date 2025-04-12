/*
 * @Author: dsaDadas11
 * @Date: 2025-04-06 18:31:56
 * @LastEditTime: 2025-04-06 18:32:10
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e3+7;
constexpr int M=2e3+7;
int n,V;
int v[N],w[N],s[N];
int dp[M];
void solve()
{
    cin>>n>>V;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i]>>w[i]>>s[i];
    }

    for(int i=1;i<=n;i++)
    {
        int sum=s[i];
        vector<int> tmp;
        int x=1;
        while(sum>=x)
        {
            tmp.push_back(x);
            sum-=x;
            x<<=1;
        }
        if(sum!=0) tmp.push_back(sum);

        vector<int> tmpv,tmpw;
        for(auto j:tmp)
        {
            tmpv.push_back(j*v[i]);
            tmpw.push_back(j*w[i]);
        }

        for(int j=0;j<tmp.size();j++)
        {
            for(int k=V;k>=tmpv[j];k--)
            {
                dp[k]=max(dp[k],dp[k-tmpv[j]]+tmpw[j]);
            }
        }
    }
    cout<<dp[V]<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}