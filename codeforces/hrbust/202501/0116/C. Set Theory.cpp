/*
 * @Author: dsaDadas11
 * @Date: 2025-01-17 14:58:43
 * @LastEditTime: 2025-01-17 14:58:54
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6;
constexpr int M=2e3+7;
int n;
int a[107];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    vector<bool> cnt(N+7);
    cnt[0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            cnt[a[j]-a[i]]=1;
        }
    }
    vector<int> b;
    b.push_back(1);
    for(int i=2;i<=N;i++)
    {
        if(b.size()==n) break;
        bool ok=0;
        for(int j=0;j<b.size();j++)
        {
            if(cnt[i-b[j]])
            {
                ok=1;
                break;
            }
        }
        if(ok) continue;
        b.push_back(i);
        if(b.size()==n) break;
    }
    if(b.size()<n) return cout<<"NO"<<endl,void();
    cout<<"YES"<<endl;
    for(auto i:b) cout<<i<<' ';
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}