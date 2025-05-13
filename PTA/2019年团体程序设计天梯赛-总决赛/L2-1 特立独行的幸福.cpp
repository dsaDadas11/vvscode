/*
 * @Author: dsaDadas11
 * @Date: 2025-04-15 20:32:19
 * @LastEditTime: 2025-04-15 20:32:50
 * @Description: go for it!
 */
/*
 解题思路：
 用到了并查集的思想
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=2e4+7;
constexpr int M=2e3+7;
int l,r;
int cnt[N];
bool vis[N]; // 素数为 0
void init()
{
    vis[1]=1;
    for(int i=2;i*i<N;i++)
    {
        if(vis[i]) continue;
        for(int j=i*i;j<N;j+=i)
        {
            vis[j]=1;
        }
    }
}
int fa[N];
int calc(int x)
{
    int sum=0;
    while(x)
    {
        int tmp=x%10;
        sum+=tmp*tmp;
        x/=10;
    }
    return sum;
}
int find_fa(int x)
{
    int cnt=0;
    while(fa[x]!=x)
    {
        x=fa[x];
        cnt++;
        if(cnt>10000) return -1;
    }
    return x;
}
bool check(int x)
{
    for(int i=l;i<=r;i++)
    {
        if(fa[i]==x) return 0;
    }
    return 1;
}
void solve()
{
    cin>>l>>r;
    for(int i=1;i<N;i++) fa[i]=calc(i);
    bool flag=0;
    for(int i=l;i<=r;i++)
    {
        if(check(i)&&find_fa(i)==1)
        {
            flag=1;
            int cnt=1,x=i;
            while(calc(x)!=1)
            {
                x=calc(x);
                cnt++;
            }
            if(!vis[i]) cnt*=2;
            cout<<i<<' '<<cnt<<endl;
        }
    }
    if(!flag) cout<<"SAD"<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}