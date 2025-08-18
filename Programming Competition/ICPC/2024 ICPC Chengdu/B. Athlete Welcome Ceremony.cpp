/*
 * @Author: dsaDadas11
 * @Date: 2025-07-19 17:34:05
 * @LastEditTime: 2025-07-19 17:34:37
 * @Description: go for it!
 */
/*
 解题思路：
 三维 dp + 三维前缀和，有点难想
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=300+7;
constexpr int M=2e3+7;
constexpr int mod=1e9+7;
int n,q;
string t;
int cnt[3];
int dp[N][N][N][3],s[N][N][N];
void solve()
{
    cin>>n>>q;
    cin>>t;
    t=' '+t;
    for(int i=1;i<=n;i++)
    {
        if(t[i]!='?') cnt[t[i]-'a']++;
    }
    dp[1][0][0][0]=dp[0][1][0][1]=dp[0][0][1][2]=1;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;i+j<=n;j++)
        {
            for(int k=0;i+j+k<=n;k++)
            {
                if(t[i+j+k]=='a') dp[i][j][k][1]=dp[i][j][k][2]=0;
                if(t[i+j+k]=='b') dp[i][j][k][0]=dp[i][j][k][2]=0;
                if(t[i+j+k]=='c') dp[i][j][k][0]=dp[i][j][k][1]=0;
                dp[i+1][j][k][0]=(dp[i+1][j][k][0]+dp[i][j][k][1]+dp[i][j][k][2])%mod;
                dp[i][j+1][k][1]=(dp[i][j+1][k][1]+dp[i][j][k][0]+dp[i][j][k][2])%mod;
                dp[i][j][k+1][2]=(dp[i][j][k+1][2]+dp[i][j][k][0]+dp[i][j][k][1])%mod;
            }
        }
    }

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            for(int k=0;k<=n;k++)
            {
                if(i+j+k==n) s[i][j][k]=dp[i][j][k][0]+dp[i][j][k][1]+dp[i][j][k][2];
                if(i>0) s[i][j][k]+=s[i-1][j][k];
                if(j>0) s[i][j][k]+=s[i][j-1][k];
                if(k>0) s[i][j][k]+=s[i][j][k-1];
                if(i>0&&j>0) s[i][j][k]-=s[i-1][j-1][k];
                if(i>0&&k>0) s[i][j][k]-=s[i-1][j][k-1];
                if(j>0&&k>0) s[i][j][k]-=s[i][j-1][k-1];
                if(i>0&&j>0&&k>0) s[i][j][k]+=s[i-1][j-1][k-1];
                s[i][j][k]=(s[i][j][k]%mod+mod)%mod;
            }
        }
    }

    int x,y,z;
    while(q--)
    {
        cin>>x>>y>>z;
        x=min(x+cnt[0],n),y=min(y+cnt[1],n),z=min(z+cnt[2],n);
        cout<<s[x][y][z]<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}