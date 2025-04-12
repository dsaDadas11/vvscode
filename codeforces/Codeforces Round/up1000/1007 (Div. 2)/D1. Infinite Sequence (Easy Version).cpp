/*
 * @Author: dsaDadas11
 * @Date: 2025-03-26 21:41:09
 * @LastEditTime: 2025-03-26 21:46:45
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
bool a[N];
bool pre[N];
bool dfs(int x)
{
    if(x<=2*n) return a[x];
    if((x/2)%2==0) return (pre[n]^dfs(x/2));
    else return pre[n];
}
void solve()
{
    cin>>n>>m>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        pre[i]=pre[i-1]^a[i];
    }
    if(n%2==0)
    {
        n++;
        a[n]=pre[n/2];
        pre[n]=pre[n-1]^a[n];
    }

    bool s=pre[n];
    for(int i=n+1;i<=2*n;i++)
    {
        a[i]=pre[i/2];
        pre[i]=pre[i-1]^a[i];
    }

    cout<<dfs(m)<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}

/*
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m;
bool a[N];
bool pre[N];
void solve()
{
    cin>>n>>m>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        pre[i]=pre[i-1]^a[i];
    }
    if(n%2==0)
    {
        n++;
        a[n]=pre[n/2];
        pre[n]=pre[n-1]^a[n];
    }

    bool s=pre[n];
    for(int i=n+1;i<=2*n;i++)
    {
        a[i]=pre[i/2];
        pre[i]=pre[i-1]^a[i];
    }
    bool ans=0;
    while(1)
    {
        if(m<=2*n)
        {
            ans^=a[m];
            break;
        }
        ans^=s;
        if((m/2-n)%2==0)
        {
            break;
        }
        m/=2;
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