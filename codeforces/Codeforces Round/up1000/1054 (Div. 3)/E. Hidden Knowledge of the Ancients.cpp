/*
 * @Author: dsaDadas11
 * @Date: 2025-11-11 21:35:25
 * @LastEditTime: 2025-11-11 21:48:20
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=2e5+7;
constexpr int M=2e3+7;
int n,k,l,r;
int a[N];
void solve()
{
    cin>>n>>k>>l>>r;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    map<int,int> mp1,mp2;
    int p1=0,p2=0;
    int ans=0;

    for(int i=1;i<=n;i++)
    {
        // min
        while(p1<n&&mp1.size()<k)
        {
            mp1[a[++p1]]++;
        }

        // max
        while(p2<n&&(mp2.size()<k||(mp2.size()==k&&mp2.count(a[p2+1]))))
        {
            mp2[a[++p2]]++;
        }
        
        if(mp1.size()==k&&mp2.size()==k&&i+l-1<=n)
        {
            int dl=i+l-1,dr=i+r-1;
            ans+=max(0LL,min(dr,p2)-max(dl,p1)+1); // 不加 max居然可能是负数？
            // 原来会有 p1>dr或者 p2<dl 的情况...
        }

        // delete
        mp1[a[i]]--;
        if(mp1[a[i]]==0) mp1.erase(a[i]);

        mp2[a[i]]--;
        if(mp2[a[i]]==0) mp2.erase(a[i]);
    }

    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}