/*
 * @Author: dsaDadas11
 * @Date: 2025-05-05 13:41:55
 * @LastEditTime: 2025-05-05 13:42:03
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
constexpr int inf=1e16;
int n,k,q,m;
string s,t;
int lstp[27]; // 记录字符出现的位置
int now[N]; // 记录从 si字符开始要经过多少步才能变为不是 s子序列
int dp[N][27]; // 第 i个位置跳到 a-z
void solve()
{
    cin>>n>>k;
    cin>>s;
    for(int i=1;i<=k;i++) lstp[i]=n+1;
    s=' '+s;
    for(int i=n;i>=1;i--)
    {
        now[i]=inf;
        for(int j=1;j<=k;j++)
        {
            dp[i][j]=lstp[j];
            now[i]=min(now[i],now[lstp[j]]+1);
        }
        lstp[s[i]-'a'+1]=i;
    }

    cin>>q;
    while(q--)
    {
        cin>>t;
        m=t.size();
        t=' '+t;
        int st=lstp[t[1]-'a'+1];
        int idx=2;
        while(idx<=m&&dp[st][t[idx]-'a'+1])
        {
            st=dp[st][t[idx]-'a'+1];
            idx++;
        }
        if(idx<m)
        {
            cout<<"0"<<endl;
            continue;
        }

        cout<<now[st]<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}