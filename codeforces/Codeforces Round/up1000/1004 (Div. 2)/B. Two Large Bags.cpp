/*
 * @Author: HuangCe
 * @Date: 2025-02-13 18:26:58
 * @LastEditTime: 2025-02-13 18:27:04
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
int a[M];
void solve()
{
    cin>>n;
    vector<int> cnt(2*n+7);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        cnt[a[i]]++;
    }
    for(int i=1;i<=2*n;i++)
    {
        if(cnt[i]==1) return cout<<"No"<<endl,void();
        if(cnt[i]<=2) continue;
        cnt[i+1]+=cnt[i]-2; // 留两个，剩下的往后加
    }
    cout<<"Yes"<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}