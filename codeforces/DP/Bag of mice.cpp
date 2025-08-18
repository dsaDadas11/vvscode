/*
 * @Author: dsaDadas11
 * @Date: 2025-08-18 16:22:47
 * @LastEditTime: 2025-08-18 16:23:10
 * @Description: go for it!
 */
// URL:https://codeforces.com/problemset/problem/148/D
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=1e3+7;
int w,b;
double f[M][M]; // i只白鼠，j只黑鼠
void solve()
{
    cin>>w>>b;
    for(int i=1;i<=b;i++) f[0][i]=0;
    for(int i=1;i<=w;i++) f[i][0]=1;

    for(int i=1;i<=w;i++)
    {
        for(int j=1;j<=b;j++)
        {
            // 先手抓白的
            f[i][j]+=1.0*i/(i+j);

            // 黑 黑 逃走白
            if(j>=2) f[i][j]+=1.0*j/(i+j)*(j-1)/(i+j-1)*i/(i+j-2)*f[i-1][j-2];

            // 黑 黑 逃走黑
            if(j>=3) f[i][j]+=1.0*j/(i+j)*(j-1)/(i+j-1)*(j-2)/(i+j-2)*f[i][j-3];
        }
    }
    cout<<fixed<<setprecision(10)<<f[w][b]<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}