/*
 * @Author: dsaDadas11
 * @Date: 2025-07-16 17:41:02
 * @LastEditTime: 2025-07-16 17:41:11
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
int cnt[4];
void solve()
{
    cin>>n;
    for(int i=0;i<4;i++) cnt[i]=0;
    for(int i=0;i<n;i++)
    {
        cnt[i%4]++;
    }
    for(int i=0;i<=3;i++)
    {
        if(cnt[i]<=0) continue;
        cnt[abs(3-i)]-=cnt[i];
        if(cnt[abs(3-i)]<0)
        {
            cout<<"Alice"<<endl;
            return;
        }
        cnt[i]=0;
    }
    for(int i=0;i<=3;i++)
    {
        if(cnt[i]>0)
        {
            cout<<"Alice"<<endl;
            return;
        }
    }
    cout<<"Bob"<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}