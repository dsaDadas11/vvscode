/*
 * @Author: dsaDadas11
 * @Date: 2025-01-16 20:29:54
 * @LastEditTime: 2025-01-16 20:30:04
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
string s;
map<char,int> mp;
void init()
{
    char c;
    for(int i=0;i<=25;i++)
    {
        c='a'+i;
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u') continue;
        mp[c]=1;
    }
}
bool vis[N];
void solve()
{
    cin>>s;
    int len=s.size();
    int cnt=0;
    for(int i=0;i<len;i++)
    {
        if(mp[s[i]])  cnt++;
        else cnt=0;
        if(cnt>=3)
        {
            if(s[i]==s[i-1]&&s[i-1]==s[i-2]) continue;
            else vis[i]=1,cnt=1;
        }
    }
    for(int i=0;i<len;i++)
    {
        if(vis[i]) cout<<' ';
        cout<<s[i];
    }
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}