/*
 * @Author: dsaDadas11
 * @Date: 2025-11-01 20:29:21
 * @LastEditTime: 2025-11-01 20:29:28
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int l,r,n;
void solve()
{
    cin>>l>>r;
    n=r-l+1;

    vector<int> a;
    for(int i=l;i<=r;i++)
    {
        a.push_back(i);
    }

    int L=0,R=n;
    for(int i=29;i>=0;i--)
    {
        int p=L;
        while(p<R&&(((a[p]>>i)&1))==0) p++;

        if(p-L<=R-p)
        {
            int nl=2*p-L;
            reverse(a.begin()+L,a.begin()+nl);
            L=nl;
        }
        else
        {
            int nr=2*p-R;
            reverse(a.begin()+nr,a.begin()+R);
            R=nr;
        }
    }

    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans+=a[i]|(i+l);
    }

    cout<<ans<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<' ';
    }
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}