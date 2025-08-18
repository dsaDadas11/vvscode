/*
 * @Author: dsaDadas11
 * @Date: 2025-08-18 16:55:36
 * @LastEditTime: 2025-08-18 18:11:34
 * @Description: go for it!
 */
/*
 概率 dp
*/
#include<iostream>
#include<cstring>
#define endl '\n'
using namespace std;
const int N=1e6+7;
const int M=2e3+7;
int n;
double p[1<<7][1<<7];
double f[8][1<<7]; // 第 i轮，j队获胜的概率
void solve()
{
    for(int i=0;i<(1<<n);i++)
    {
        for(int j=0;j<(1<<n);j++)
        {
            cin>>p[i][j];
        }
    }
    memset(f,0,sizeof f);
    for(int i=0;i<(1<<n);i++)
    {
        f[0][i]=1;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<(1<<n);j++)
        {
            for(int k=0;k<(1<<n);k++)
            {
                if(((j>>(i-1))^1)==(k>>(i-1)))
                {
                    f[i][j]+=f[i-1][j]*f[i-1][k]*p[j][k];
                }
            }
        }
    }

    double ans=0.0;
    int idx=0;
    for(int i=0;i<(1<<n);i++)
    {
        if(ans<=f[n][i])
        {
            ans=f[n][i];
            idx=i;
        }
    }
    cout<<idx+1<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(cin>>n&&n!=-1){solve();}
    return 0;
}