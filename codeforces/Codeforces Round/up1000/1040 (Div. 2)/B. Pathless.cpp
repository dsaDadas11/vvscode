/*
 * @Author: dsaDadas11
 * @Date: 2025-08-08 10:30:22
 * @LastEditTime: 2025-08-08 10:30:30
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,s,x;
void solve()
{
    cin>>n>>s;
    vector<int> cnt(3);
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        cnt[x]++;
        sum+=x;
    }
    vector<int> ans;
    for(int i=1;i<=cnt[0];i++) ans.push_back(0);
    for(int i=1;i<=cnt[2];i++) ans.push_back(2);
    for(int i=1;i<=cnt[1];i++) ans.push_back(1);
    if(sum>s||s-sum==1)
    {
        for(auto i:ans) cout<<i<<' ';
        cout<<endl;
    }
    else cout<<"-1"<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}