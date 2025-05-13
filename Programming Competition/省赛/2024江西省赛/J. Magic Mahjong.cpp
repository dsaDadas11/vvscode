/*
 * @Author: dsaDadas11
 * @Date: 2025-04-21 14:52:31
 * @LastEditTime: 2025-04-21 14:52:44
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
map<string,int> mp;
bool check13()
{
    if(mp["1s"]==0||mp["9s"]==0) return 0;
    if(mp["1p"]==0||mp["9p"]==0) return 0;
    if(mp["1m"]==0||mp["9m"]==0) return 0;
    for(int i=1;i<=7;i++)
    {
        string tmp="";
        tmp=to_string(i)+'z';
        if(mp[tmp]==0) return 0;
    }
    return 1;
}
bool check7()
{
    for(int i=1;i<=9;i++)
    {
        string tmp="";
        tmp=to_string(i)+'s';
        if(mp[tmp]==0) continue;
        if(mp[tmp]!=2) return 0;
    }
    for(int i=1;i<=9;i++)
    {
        string tmp="";
        tmp=to_string(i)+'p';
        if(mp[tmp]==0) continue;
        if(mp[tmp]!=2) return 0;
    }
    for(int i=1;i<=9;i++)
    {
        string tmp="";
        tmp=to_string(i)+'m';
        if(mp[tmp]==0) continue;
        if(mp[tmp]!=2) return 0;
    }
    return 1;
}
void solve()
{
    cin>>s;
    mp.clear();
    int len=s.size();
    s=' '+s;
    for(int i=1;i<=len;i+=2)
    {
        string tmp="";
        tmp.push_back(s[i]);
        tmp.push_back(s[i+1]);
        mp[tmp]++;
    }
    if(check13()) cout<<"Thirteen Orphans"<<endl;
    else if(check7()) cout<<"7 Pairs"<<endl;
    else cout<<"Otherwise"<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}