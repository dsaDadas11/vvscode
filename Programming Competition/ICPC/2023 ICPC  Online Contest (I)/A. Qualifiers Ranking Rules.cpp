/*
 * @Author: dsaDadas11
 * @Date: 2025-09-04 22:57:17
 * @LastEditTime: 2025-09-04 22:57:31
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
string x;
void solve()
{
    cin>>n>>m;
    map<string,int> mp1,mp2;
    vector<string> s,t;

    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        if(!mp1[x])
        {
            mp1[x]=1;
            s.push_back(x);
        }
    }
    for(int i=1;i<=m;i++)
    {
        cin>>x;
        if(!mp2[x])
        {
            mp2[x]=1;
            t.push_back(x);
        }
    }

    vector<string> ans;
    int len=min(s.size(),t.size());
    for(int i=0;i<len;i++)
    {
        ans.push_back(s[i]);
        ans.push_back(t[i]);
    }
    if(s.size()<t.size())
    {
        for(int i=len;i<t.size();i++) ans.push_back(t[i]);
    }
    else
    {
        for(int i=len;i<s.size();i++) ans.push_back(s[i]);
    }

    mp1.clear();
    for(auto x:ans)
    {
        if(!mp1[x])
        {
            cout<<x<<endl;
            mp1[x]=1;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}