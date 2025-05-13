/*
 * @Author: dsaDadas11
 * @Date: 2025-05-05 11:55:53
 * @LastEditTime: 2025-05-05 11:56:01
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
char ch[N];
void prin(char c)
{
    if(c=='A') cout<<"Alice"<<endl;
    else cout<<"Bob"<<endl;
}
void solve()
{
    cin>>n;
    int suma=0,sumb=0;
    for(int i=1;i<=n;i++)
    {
        cin>>ch[i];
        if(ch[i]=='A') suma++;
        else sumb++;
    }
    if(n==2)
    {
        prin(ch[1]);
        return;
    }
    if(ch[1]==ch[n])
    {
        prin(ch[1]);
        return;
    }
    if(ch[n]=='B'&&sumb==1)
    {
        prin('A');
        return;
    }

    if(ch[1]=='B') prin(ch[n-1]);
    else prin('B');

}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}