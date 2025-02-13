/*
 * @Author: dsaDadas11
 * @Date: 2024-10-08 21:01:12
 * @LastEditTime: 2024-10-08 21:01:20
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m;
string s;
void solve()
{
    map<char,int> mp;
    cin>>n>>m;
    cin>>s;
    for(int i=0;i<n;i++)
    {
        mp[s[i]]++;
    }
    int ans=0;
    for(char c='A';c<='G';c++)
    {
        ans+=max(0LL,m-mp[c]);
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