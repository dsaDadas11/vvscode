/*
 * @Author: dsaDadas11
 * @Date: 2025-09-02 14:41:28
 * @LastEditTime: 2025-09-02 14:41:36
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
int a[N],u[N];
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>u[i];

    priority_queue<int,vector<int>,greater<int> > t;
    priority_queue<int> s;

    for(int k=1;k<=m;k++)
    {
        for(int i=u[k-1]+1;i<=u[k];i++)
        {
            if(i==1) s.push(a[i]);
            else
            {
                if(a[i]>s.top()) t.push(a[i]);
                else s.push(a[i]);
            }
        }

        while(s.size()<k)
        {
            s.push(t.top());
            t.pop();
        }
        while(s.size()>k)
        {
            t.push(s.top());
            s.pop();
        }
        
        cout<<s.top()<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}