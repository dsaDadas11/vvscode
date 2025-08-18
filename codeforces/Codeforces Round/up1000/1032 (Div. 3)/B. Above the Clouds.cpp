/*
 * @Author: dsaDadas11
 * @Date: 2025-08-01 11:46:04
 * @LastEditTime: 2025-08-01 11:46:10
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
    map<char,int> mp;
    mp[s[0]]++,mp[s[n-1]]++;
    for(int i=1;i<n-1;i++)
    {
        if(mp[s[i]]) return cout<<"YES"<<endl,void();
        mp[s[i]]++;
    }
    cout<<"NO"<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}