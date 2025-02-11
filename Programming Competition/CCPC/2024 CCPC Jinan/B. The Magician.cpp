/*
 * @Author: dsaDadas11
 * @Date: 2025-01-15 14:24:58
 * @LastEditTime: 2025-01-15 14:25:07
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
int t[7];
char x,y;
void solve()
{
    cin>>n;
    map<char,int> col;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>y;
        col[y]++;
    }
    for(int i=1;i<=6;i++) cin>>t[i];
    col['D']+=t[1]*3;
    col['C']+=t[2]*3;
    col['H']+=t[3]*3;
    col['S']+=t[4]*3;
    int ans=col['D']/5+col['C']/5+col['H']/5+col['S']/5;
    priority_queue<int> pq;
    pq.push(col['D']%5);
    pq.push(col['C']%5);
    pq.push(col['H']%5);
    pq.push(col['S']%5);
    int sum=t[5]+t[6];
    while(!pq.empty())
    {
        if(sum>=5-pq.top())
        {
            ans++;
            sum-=5-pq.top();
            pq.pop();
        }
        else break;
    }
    ans=min(ans,n/5);
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}