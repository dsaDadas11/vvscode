/*
 * @Author: dsaDadas11
 * @Date: 2025-09-27 16:58:47
 * @LastEditTime: 2025-10-03 19:10:08
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=(1<<16)+7;
constexpr int M=18;
int n,a0,a1,a2,a3;
int dist[M][M];
int f[N][M],ans[N];
void init()
{
    memset(dist,0x3f,sizeof dist);
    for(int i=0;i<16;i++)
    {
        // 单点
        dist[i][i^1]=a0;
        dist[i][i^2]=a0;
        dist[i][i^4]=a0;
        dist[i][i^8]=a0;

        // 行
        dist[i][i^3]=a1;
        dist[i][i^12]=a1;

        // 列
        dist[i][i^5]=a2;
        dist[i][i^10]=a2;

        // 全部
        dist[i][i^15]=a3;
    }
    dist[15][15]=2*min({a0,a1,a2,a3});

    for(int k=0;k<16;k++)
    {
        for(int i=0;i<16;i++)
        {
            for(int j=0;j<16;j++)
            {
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }

    memset(f,0x3f,sizeof f);
    memset(ans,0x3f,sizeof ans);

    for(int i=0;i<16;i++)
    {
        f[1<<i][i]=dist[i][15];
    }

    for(int s=0;s<(1<<16);s++)
    {
        for(int i=0;i<16;i++)
        {
            if(!((s>>i)&1)) continue;
            for(int j=0;j<16;j++)
            {
                if((s>>j)&1) continue;
                f[s|(1<<j)][j]=min(f[s|(1<<j)][j],f[s][i]+dist[j^(i^15)][15]);
            }
        }
    }

    for(int s=0;s<(1<<16);s++)
    {
        for(int i=0;i<16;i++)
        {
            ans[s]=min(ans[s],f[s][i]);
        }
    }
}
void solve()
{
    cin>>n;
    int s=0;
    char c;
    for(int i=1;i<=n;i++)
    {
        int sum=0,base=0;
        for(int j=1;j<=2;j++)
        {
            for(int k=1;k<=2;k++)
            {
                cin>>c;
                if(c=='1') sum|=1<<base;
                base++;
            }
        }
        s|=1<<sum;
    }
    cout<<ans[s]<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T>>a0>>a1>>a2>>a3;
    init();
    while(T--){solve();}
    return 0;
}

/*
最短路
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int a0,a1,a2,a3;
int dist[20][20];
int dp[1<<16][18];
void init()
{
    memset(dist,0x3f,sizeof dist);
    memset(dp,0x3f,sizeof dp);

    for(int i=0;i<16;i++)
    {
        dist[i][i^1]=a0;
        dist[i][i^2]=a0;
        dist[i][i^4]=a0;
        dist[i][i^8]=a0;

        dist[i][i^3]=a1;
        dist[i][i^12]=a1;

        dist[i][i^5]=a2;
        dist[i][i^10]=a2;

        dist[i][i^15]=a3;
    }
    dist[15][15]=2*min({a0,a1,a2,a3});

    for(int k=0;k<16;k++)
    {
        for(int i=0;i<16;i++)
        {
            for(int j=0;j<16;j++)
            {
                dist[i][j]=min(dist[i][k]+dist[k][j],dist[i][j]);
            }
        }
    }

    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<> > pq;

    for(int i=0;i<16;i++)
    {
        dp[1<<i][i]=dist[i][15];
        pq.push({dist[i][15],1<<i,i});
    }

    while(!pq.empty())
    {
        auto [x,t,j]=pq.top();
        pq.pop();
        for(int k=0;k<16;k++)
        {
            int s=t|(1<<k);
            if(dp[s][k]>dp[t][j]+dist[j][k])
            {
                dp[s][k]=dp[t][j]+dist[j][k];
                pq.push({dp[s][k],s,k});
            }
        }
    }
}
int m;
string t;
void solve()
{
    cin>>m;
    int s=0;
    for(int i=1;i<=m;i++)
    {
        int tmp=0;
        cin>>t;
        if(t[0]=='1') tmp+=1;
        if(t[1]=='1') tmp+=2;
        cin>>t;
        if(t[0]=='1') tmp+=4;
        if(t[1]=='1') tmp+=8;
        s|=(1<<tmp);
    }
    int ans=N*N;
    for(int i=0;i<16;i++)
    {
        ans=min(ans,dp[s][i]);
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T>>a0>>a1>>a2>>a3;
    init();
    while(T--){solve();}
    return 0;
}
*/