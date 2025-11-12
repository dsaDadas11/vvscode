/*
 * @Author: dsaDadas11
 * @Date: 2025-10-23 19:34:55
 * @LastEditTime: 2025-10-23 19:35:03
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
string s;
void solve()
{
    cin>>n;
    cin>>s;
    s=' '+s;
    vector<int> ans(n+1);
    int sum=0,p=1;

    // 向右遍历
    for(int i=1;i<=n;i++)
    {
        while(p<n&&s[p]!='<') p++;
        if(s[p]!='<') break;
        sum+=2*(p-i)+1;
        ans[i]=sum;
        // cout<<i<<" "<<sum<<endl;
        if(p==n) break;
        p++;
        // cout<<"p: "<<p<<endl;
    }

    sum=0,p=n;
    for(int i=n;i>=1;i--)
    {
        while(p>1&&s[p]!='>') p--;
        if(s[p]!='>') break;
        sum+=2*(i-p)+1;
        ans[i]=sum;
        if(p==1) break;
        p--;
    }

    for(int i=1;i<=n;i++)
    {
        cout<<ans[i]<<' ';
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