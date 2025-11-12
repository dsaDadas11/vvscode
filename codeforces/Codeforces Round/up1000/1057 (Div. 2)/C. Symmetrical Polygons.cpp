/*
 * @Author: dsaDadas11
 * @Date: 2025-11-12 19:29:35
 * @LastEditTime: 2025-11-12 19:29:48
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=2e5+7;
constexpr int M=2e3+7;
int n;
int a[N];
void solve()
{
    cin>>n;
    map<int,int> mp;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        mp[a[i]]++;
    }

    int ans=0,cnt=0,sum=0;
    vector<int> b;
    for(auto [x,y]:mp)
    {
        if(y%2)
        {
            sum+=x*(y-1);
            cnt+=y-1;
            b.push_back(x);
        }
        else
        {
            sum+=x*y;
            cnt+=y;
        }
    }

    // 不选
    ans=sum;
    // 选一个
    for(int i=0;i<b.size();i++)
    {
        if(sum>b[i]) ans=max(ans,sum+b[i]),cnt++;
    }
    // 选两个
    for(int i=b.size()-2;i>=0;i--)
    {
        if(sum+b[i]>b[i+1])
        {
            ans=sum+b[i]+b[i+1];
            cnt++;
            break;
        }
    }

    if(cnt<3) cout<<0<<endl;
    else cout<<ans<<endl;

}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}