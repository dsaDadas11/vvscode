/*
 * @Author: HuangCe
 * @Date: 2025-02-18 18:24:27
 * @LastEditTime: 2025-02-18 18:24:37
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,x;
void solve()
{
    cin>>n;
    map<int,int> cnt;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        cnt[x]++;
    }
    int ans1=0,ans2=0;
    for(auto [x,y]:cnt)
    {
        if(y<2) ans1++;
        else if(y>2) ans2+=y-2;
    }
    if(ans1<=ans2)
    {
        cout<<ans2<<endl;
    }
    else
    {
        cout<<(ans1-ans2)/2+ans2<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}