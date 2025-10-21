/*
 * @Author: dsaDadas11
 * @Date: 2025-09-27 15:07:27
 * @LastEditTime: 2025-09-27 15:07:34
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
string s[10];
int t[10];
void solve()
{
    for(int i=1;i<=8;i++)
    {
        cin>>s[i]>>t[i];
    }

    // 第一轮
    vector<pair<string,int> > r1;
    for(int i=1;i<=8;i+=2)
    {
        if(t[i]>t[i+1]) r1.push_back({s[i],t[i]});
        else r1.push_back({s[i+1],t[i+1]});
    }

    // 第二轮
    vector<pair<string,int> > r2;
    for(int i=0;i<4;i+=2)
    {
        auto [s1,t1]=r1[i];
        auto [s2,t2]=r1[i+1];
        if(t1>t2) r2.push_back({s1,t1});
        else r2.push_back({s2,t2});
    }

    string s1,s2;
    if(r2[0].second>r2[1].second) s1=r2[0].first,s2=r2[1].first;
    else s2=r2[0].first,s1=r2[1].first;
    cout<<s1<<" beats "<<s2<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}