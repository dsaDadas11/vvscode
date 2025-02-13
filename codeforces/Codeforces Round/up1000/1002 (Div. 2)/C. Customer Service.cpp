/*
 * @Author: dsaDadas11
 * @Date: 2025-02-03 20:20:05
 * @LastEditTime: 2025-02-12 18:40:02
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=307;
int n;
int a[M][M];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
        }
    }
    priority_queue<int,vector<int>,greater<> > pq;
    for(int i=1;i<=n;i++)
    {
        int j=n+1;
        while(j-1>=1&&a[i][j-1]==1) j--;
        pq.push(n-j+1);
    }
    int ans=0;
    while(!pq.empty())
    {
        if(pq.top()>=ans) ans++;
        pq.pop();
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

/*
 不用优先队列的做法：
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=300+7;
int n;
int a[M][M];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
        }
    }
    vector<int> v;
    for(int i=1;i<=n;i++)
    {
        int cnt=0;
        for(int j=n;j>=1;j--)
        {
            if(a[i][j]==1) cnt++;
            else break;
        }
        v.push_back(cnt);
    }
    sort(v.begin(),v.end());
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(v[i]>=ans) ans++;
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
*/