/*
 * @Author: dsaDadas11
 * @Date: 2025-06-11 18:40:28
 * @LastEditTime: 2025-06-11 18:40:53
 * @Description: go for it!
 */
/*
 小时是小于等于 6的
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
void solve()
{
    for(int h=0;h<=6;h++)
    {
        for(int m=0;m<=59;m++)
        {
            for(int s=0;s<=59;s++)
            {
                double ds=s;
                double dm=(double)m+ds/60.0;
                double dh=(double)h+dm/60.0;

                double A=fabs(dh*30.0-dm*6.0);
                double B=fabs(dm*6.0-ds*6.0);

                A=min(A,360-A);
                B=min(B,360-B);

                if(fabs(A-2*B)==0)
                {
                    cout<<h<<' '<<m<<' '<<s<<endl;
                }
            }
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}