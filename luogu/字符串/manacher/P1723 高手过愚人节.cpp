/*
 * @Author: dsaDadas11
 * @Date: 2025-11-10 11:36:45
 * @LastEditTime: 2025-11-10 11:36:54
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
// #define int ll
using namespace std;
constexpr int N=3e7+7;
constexpr int M=2e3+7;
string init(string s)
{
    string t="$";
    for(int i=0;i<s.size();i++)
    {
        t.push_back('#');
        t.push_back(s[i]);
    }
    t+="#&";
    return t;
}
int p[N];
void manacher(string s)
{
    int r=0,c;
    for(int i=1;i<s.size()-1;i++)
    {
        if(i<r) p[i]=min(p[2*c-i],r-i);
        else p[i]=1;

        while(s[i-p[i]]==s[i+p[i]]) p[i]++;
        
        if(i+p[i]>r)
        {
            r=i+p[i];
            c=i;
        }
    }
}
string s,t;
void solve()
{
    cin>>s;
    t=init(s);
    manacher(t);
    int ans=1;
    for(int i=1;i<t.size()-1;i++)
    {
        ans=max(ans,p[i]-1);
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