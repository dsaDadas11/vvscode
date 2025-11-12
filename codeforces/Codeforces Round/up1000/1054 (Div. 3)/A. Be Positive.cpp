/*
 * @Author: dsaDadas11
 * @Date: 2025-11-06 13:27:11
 * @LastEditTime: 2025-11-06 13:27:19
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
int a[10];
void solve()
{
    cin>>n;
    int cntf1=0,cnt0=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==-1) cntf1++;
        else if(a[i]==0) cnt0++;
    }

    cout<<cnt0+(cntf1&1)*2<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}