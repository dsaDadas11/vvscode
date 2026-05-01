/*
 * @Author: dsaDadas11
 * @Date: 2025-11-13 14:12:32
 * @LastEditTime: 2025-11-13 14:13:02
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
void solve()
{
    cin>>n>>k;
    int tmp=n;
    vector<int> a;
    
    // 每次加一会有 n-1的贡献
    while(k>=n-1&&n)
    {
        k-=n-1;
        a.push_back(1);
        n--;
    }

    // 当 k<n-1 可能 k比较大的时候直接二分分配不完？
    int cnt=n; // [n,2*n-1]
    while(k&&n)
    {
        int l=2,r=n;
        int ans=2;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            if(mid*(mid-1)/2<=k)
            {
                l=mid+1;
                ans=mid;
            }
            else
            {
                r=mid-1;
            }
        }
        if(ans*(ans-1)/2<=k)
        {
            k-=ans*(ans-1)/2;
            n-=ans;
            for(int i=1;i<=ans;i++)
            {
                a.push_back(cnt);
            }
            cnt++;
        }
    }

    for(int i=1;i<=n;i++) a.push_back(cnt++);

    for(auto i:a) cout<<i<<' ';
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}