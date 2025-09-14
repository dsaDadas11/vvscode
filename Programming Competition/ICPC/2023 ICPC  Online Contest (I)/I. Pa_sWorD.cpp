/*
 * @Author: dsaDadas11
 * @Date: 2025-09-05 21:53:44
 * @LastEditTime: 2025-09-05 21:53:54
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e5+5;
constexpr int M=2e3+7;
constexpr int mod=998244353;
int n;
string s;
int f[2][62][2][2][2]; // lower upper digit
int sum[2][2][2][2];
int has(char c)
{
    if(c>='a'&&c<='z') return c-'a';
    if(c>='A'&&c<='Z') return c-'A'+26;
    return c-'0'+52;
}
void solve()
{
    cin>>n;
    cin>>s;
    s=' '+s;
    
    sum[0][0][0][0]=1;
    int now=1,lst=0;
    for(int i=1;i<=n;i++)
    {
        if(s[i]>='A'&&s[i]<='Z')
        {
            for(int l=0;l<2;l++)
            {
                for(int d=0;d<2;d++)
                {
                    f[now][has(s[i])][l][1][d]=(sum[lst][l][1][d]+sum[lst][l][0][d]-f[lst][has(s[i])][l][1][d]+mod)%mod;
                    sum[now][l][1][d]=(sum[now][l][1][d]+f[now][has(s[i])][l][1][d])%mod;
                }
            }
        }
        else if(s[i]>='a'&&s[i]<='z')
        {
            // 小写
            for(int u=0;u<2;u++)
            {
                for(int d=0;d<2;d++)
                {
                    f[now][has(s[i])][1][u][d]=(sum[lst][1][u][d]+sum[lst][0][u][d]-f[lst][has(s[i])][1][u][d]+mod)%mod;
                    sum[now][1][u][d]=(sum[now][1][u][d]+f[now][has(s[i])][1][u][d])%mod;
                }
            }

            // 大写
            for(int l=0;l<2;l++)
            {
                for(int d=0;d<2;d++)
                {
                    f[now][has(s[i])+26][l][1][d]=(sum[lst][l][1][d]+sum[lst][l][0][d]-f[lst][has(s[i])+26][l][1][d]+mod)%mod;
                    sum[now][l][1][d]=(sum[now][l][1][d]+f[now][has(s[i])+26][l][1][d])%mod;
                }
            }
        }
        else if(s[i]>='0'&&s[i]<='9')
        {
            for(int l=0;l<2;l++)
            {
                for(int u=0;u<2;u++)
                {
                    f[now][has(s[i])][l][u][1]=(sum[lst][l][u][1]+sum[lst][l][u][0]-f[lst][has(s[i])][l][u][1]+mod)%mod;
                    sum[now][l][u][1]=(sum[now][l][u][1]+f[now][has(s[i])][l][u][1])%mod;
                }
            }
        }
        else
        {
            // 小写
            for(int j=0;j<26;j++)
            {
                for(int u=0;u<2;u++)
                {
                    for(int d=0;d<2;d++)
                    {
                        f[now][j][1][u][d]=(sum[lst][1][u][d]+sum[lst][0][u][d]-f[lst][j][1][u][d]+mod)%mod;
                        sum[now][1][u][d]=(sum[now][1][u][d]+f[now][j][1][u][d])%mod;
                    }
                }
            }

            // 大写
            for(int j=26;j<52;j++)
            {
                for(int l=0;l<2;l++)
                {
                    for(int d=0;d<2;d++)
                    {
                        f[now][j][l][1][d]=(sum[lst][l][1][d]+sum[lst][l][0][d]-f[lst][j][l][1][d]+mod)%mod;
                        sum[now][l][1][d]=(sum[now][l][1][d]+f[now][j][l][1][d])%mod;
                    }
                }
            }

            // 数字
            for(int j=52;j<62;j++)
            {
                for(int l=0;l<2;l++)
                {
                    for(int u=0;u<2;u++)
                    {
                        f[now][j][l][u][1]=(sum[lst][l][u][1]+sum[lst][l][u][0]-f[lst][j][l][u][1]+mod)%mod;
                        sum[now][l][u][1]=(sum[now][l][u][1]+f[now][j][l][u][1])%mod;
                    }
                }
            }
        }

        memset(f[lst],0,sizeof f[lst]);
        memset(sum[lst],0,sizeof sum[lst]);

        swap(now,lst);
    }

    int ans=0;
    for(int j=0;j<62;j++)
    {
        ans=(ans+f[lst][j][1][1][1])%mod;
    }
    cout<<(ans%mod+mod)%mod<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}