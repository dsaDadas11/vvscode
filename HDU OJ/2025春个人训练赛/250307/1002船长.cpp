/*
 * @Author: dsaDadas11
 * @Date: 2025-03-09 09:57:44
 * @LastEditTime: 2025-03-09 10:01:45
 * @Description: go for it!
 */
/*
 解题思路：
 这是一道概率模拟题，可以直接模拟比赛过程，用f[i]表示无威胁的概率
 但是 n为 1e9,不能用 n模拟，因此只能转换思路用 k 1e5模拟
 设 f[i]表示碰到对手的概率
 若模拟时碰到: ans*=1-f[i]
 若 f[i]和f[i+1]存在: 概率变成 (f[i]+f[i+1])/2 进入下一轮
 若只有 f[i]则直接让 f[i]进入下一轮

 要注意将编号都减一，这样两个比赛人的编号除 2后就相同，并且异或 1后就是对手的编号，便于维护
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
constexpr int mod=998244353;
int quickpow(int x,int y)
{
    int ans=1;
    while(y)
    {
        if(y&1) ans=ans*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return ans;
}
int ni(int x)
{
    return quickpow(x,mod-2);
}
int n,k,win,ni2;
void solve()
{
    cin>>n>>k>>win;
    win--;
    vector<int> p(k),f(k,1);
    for(int i=0;i<k;i++)
    {
        cin>>p[i];
        p[i]--;
    }
    sort(p.begin(),p.end());
    int ans=1;
    while(p.size())
    {
        vector<int> a,g;
        win>>=1;
        for(int i=0;i<p.size();)
        {
            if(win==(p[i]>>1))
            {
                ans=ans*(mod+1-f[i])%mod;
                i+=1;
            }
            else if(i+1<p.size()&&(p[i]>>1)==(p[i+1]>>1))
            {
                a.push_back((p[i]>>1));
                g.push_back((f[i]+f[i+1])*ni2%mod);
                i+=2;
            }
            else if((p[i]^1)<n)
            {
                a.push_back((p[i]>>1));
                g.push_back(f[i]*ni2%mod);
                i+=1;
            }
            else
            {
                a.push_back((p[i]>>1));
                g.push_back(f[i]);
                i+=1;
            }
        }
        n=(n+1)>>1;
        p=a,f=g;
    }
    cout<<(ans%mod+mod)%mod<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ni2=ni(2);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}