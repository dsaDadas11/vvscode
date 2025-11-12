/*
 * @Author: dsaDadas11
 * @Date: 2025-11-07 21:35:58
 * @LastEditTime: 2025-11-07 21:36:07
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=2e5+7;
constexpr int inf=1e16;
int n;
string s;
int calc(char c)
{
    vector<int> b{0};
    int sumb=0;
    for(int i=1;i<=n;i++)
    {
        if(s[i]==c) b.push_back(i),sumb+=i;
    }

    int ans=inf;
    int len=b.size()-1;
    int psum=0;
    for(int i=1;i<=len;i++)
    {
        int pre=i-1;
        int suf=len-i;

        ans=min(ans,abs(b[i]*pre-pre*(pre+1)/2-psum)+abs(b[i]*suf+suf*(suf+1)/2+b[i]-(sumb-psum)));

        psum+=b[i];
    }

    return ans;
}
void solve()
{
    cin>>n;
    cin>>s;
    s=' '+s;
    
    cout<<min(calc('a'),calc('b'))<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}