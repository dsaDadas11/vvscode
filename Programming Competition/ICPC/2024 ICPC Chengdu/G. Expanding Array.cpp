/*
 * @Author: dsaDadas11
 * @Date: 2025-07-18 16:25:00
 * @LastEditTime: 2025-07-18 16:25:08
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
int a[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    set<int> se;
    for(int i=1;i<n;i++)
    {
        int x=a[i],y=a[i+1];
        se.insert(x);
        se.insert(y);
        se.insert(x&y);
        se.insert(x|y);
        se.insert(x^y);
        se.insert(x&(x^y));
        se.insert(y&(x^y));
    }
    se.insert(0);
    cout<<se.size()<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}