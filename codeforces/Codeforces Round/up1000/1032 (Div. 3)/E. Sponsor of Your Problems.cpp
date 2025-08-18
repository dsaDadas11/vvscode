/*
 * @Author: dsaDadas11
 * @Date: 2025-08-01 15:18:09
 * @LastEditTime: 2025-08-01 15:18:16
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
string l,r;
void solve()
{
    cin>>l>>r;
    int p=0;
    while(l[p]==r[p]&&p<l.size()) p++;
    int res=2*p;
    if(p==l.size())
    {
        cout<<res<<endl;
        return;
    }
    if(l[p]+1>=r[p])
    {
        res++;
        for(int i=p+1;i<l.size();i++)
        {
            if(l[i]=='9'&&r[i]=='0') res++;
            else break;
        }
    }
    cout<<res<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}