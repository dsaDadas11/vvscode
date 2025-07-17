/*
 * @Author: dsaDadas11
 * @Date: 2025-06-14 14:58:03
 * @LastEditTime: 2025-06-14 14:58:12
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,k;
int c[67][67];
void init()
{
    c[0][0]=1;
    for(int i=1;i<60;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(j==0) c[i][j]=1;
            else
            {
                c[i][j]=c[i-1][j]+c[i-1][j-1];
            }
        }
    }
}
void solve()
{
    cin>>n>>k;
    vector<int> v;
    while(n)
    {
        v.push_back(n&1);
        n>>=1;
    }

    int ans=0,sum=0;
    for(int i=v.size()-1;i>=0;i--)
    {
        if(v[i]==1)
        {
            ans+=c[i][k-sum];
            sum++;
            if(sum>k) break;
        }
        if(i==0&&sum==k) ans++;
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}