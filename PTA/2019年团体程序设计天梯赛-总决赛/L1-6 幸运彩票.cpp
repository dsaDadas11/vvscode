/*
 * @Author: dsaDadas11
 * @Date: 2025-04-15 19:54:23
 * @LastEditTime: 2025-04-15 19:54:30
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
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        int l=0,r=0;
        l=s[0]-'0'+s[1]-'0'+s[2]-'0';
        r=s[s.size()-1]-'0'+s[s.size()-2]-'0'+s[s.size()-3]-'0';
        if(l==r) cout<<"You are lucky!"<<endl;
        else cout<<"Wish you good luck."<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}