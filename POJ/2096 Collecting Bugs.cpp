/*
 * @Author: dsaDadas11
 * @Date: 2025-08-18 19:12:27
 * @LastEditTime: 2025-08-18 19:12:34
 * @Description: go for it!
 */
/*
 概率 dp
*/
#include<iostream>
#include<iomanip>
#define endl '\n'
using namespace std;
const int N=1e6+7;
const int M=1e3+7;
int n,s;
double f[M][M]; // i个 bug，j个分类的期望
void solve()
{
    cin>>n>>s;
    f[n][s]=0;
    for(int i=n;i>=0;i--)
    {
        for(int j=s;j>=0;j--)
        {
            if(i==n&&j==s) continue;
            f[i][j]=(f[i][j+1]*i*(s-j)+f[i+1][j]*(n-i)*j+f[i+1][j+1]*(n-i)*(s-j)+n*s)/(n*s-i*j);
        }
    }
    cout<<fixed<<setprecision(6)<<f[0][0]<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}