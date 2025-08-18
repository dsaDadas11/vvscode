/*
 * @Author: dsaDadas11
 * @Date: 2025-08-02 11:03:36
 * @LastEditTime: 2025-08-02 11:03:49
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
int b[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>b[i];
    int minn=b[1];
    for(int i=2;i<=n;i++)
    {
        if(b[i]>=2*minn)
        {
            cout<<"NO"<<endl;
            return;
        }
        minn=min(minn,b[i]);
    }
   
    cout<<"YES"<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}