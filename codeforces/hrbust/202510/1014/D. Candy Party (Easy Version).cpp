/*
 * @Author: dsaDadas11
 * @Date: 2025-10-14 21:46:39
 * @LastEditTime: 2025-10-14 21:46:47
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=2e5+7;
constexpr int M=2e3+7;
int lowbit(int x)
{
    return x&(-x);
}
int n;
int a[N];
void solve()
{
    cin>>n;
    int s=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        s+=a[i];
    }
    if(s%n)
    {
        cout<<"NO"<<endl;
        return;
    }
    s/=n;

    map<int,int> g; // 收  给
    for(int i=1;i<=n;i++)
    {
        int di=abs(a[i]-s);
        int p=0,q=0;

        q=lowbit(di);
        di+=q;
        p=lowbit(di);
        if(p!=di)
        {
            cout<<"NO"<<endl;
            return;
        }
        if(a[i]<s) swap(p,q);
        g[p]++,g[q]--;
    }
    for(auto [x,y]:g)
    {
        if(y!=0)
        {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}