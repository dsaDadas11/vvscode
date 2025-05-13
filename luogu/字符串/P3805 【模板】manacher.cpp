/*
 * @Author: dsaDadas11
 * @Date: 2025-05-12 16:21:27
 * @LastEditTime: 2025-05-12 16:33:29
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
//#define int ll
using namespace std;
constexpr int N=2e7+7;
constexpr int M=2e3+7;
int p[N<<1]; // 注意开双倍空间
void manacher(string s)
{
    int r=0,c; // 以 s[c]为中心的回文，p[c]=r
    for(int i=1;i<s.size()-1;i++) //两边都有特判符号，不需遍历
    {
        if(i<r) p[i]=min(p[2*c-i],r-i);
        else p[i]=1;
        while(s[i+p[i]]==s[i-p[i]]) p[i]++;
        if(p[i]+i>r)
        {
            r=p[i]+i;
            c=i;
        }
    }
}
void solve()
{
    string s;
    cin>>s;
    string t="$";
    for(int i=0;i<s.size();i++)
    {
        t.push_back('#');
        t.push_back(s[i]);
    }
    t+="#&";
    manacher(t);
    int ans=1;
    for(int i=0;i<t.size();i++) ans=max(ans,p[i]-1);
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}