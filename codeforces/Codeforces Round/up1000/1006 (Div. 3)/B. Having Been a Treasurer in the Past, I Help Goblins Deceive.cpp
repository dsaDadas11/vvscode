/*
 * @Author: dsaDadas11
 * @Date: 2025-03-11 20:35:05
 * @LastEditTime: 2025-03-11 20:35:13
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
    cin>>n>>s;
    s=' '+s;
    int c1=0,c2=0,c3=0;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='_') c2++;
        else c1++;
    }
    c3=c1/2;
    c1-=c3;
    cout<<c1*c2*c3<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}