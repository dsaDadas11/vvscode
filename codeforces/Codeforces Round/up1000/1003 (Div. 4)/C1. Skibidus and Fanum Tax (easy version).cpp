/*
 * @Author: HuangCe
 * @Date: 2025-02-11 18:31:09
 * @LastEditTime: 2025-02-11 19:07:38
 * @Description: go for it!
 */
/*
 解题思路见 C2
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m;
int a[N];
int b;
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    cin>>b;
    a[n]=max(a[n],b-a[n]);
    for(int i=n-1;i>=1;i--)
    {
        int maxn=max(a[i],b-a[i]);
        int minn=min(a[i],b-a[i]);
        if(maxn>a[i+1])
        {
            a[i]=minn;
        }
        else a[i]=maxn;
    }
    if(is_sorted(a+1,a+1+n)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}