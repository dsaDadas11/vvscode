/*
 * @Author: dsaDadas11
 * @Date: 2025-01-22 11:47:38
 * @LastEditTime: 2025-01-22 11:48:22
 * @Description: go for it!
 */
/*
 解题思路：
 找规律，发现最后 x 会反复变成 1，这个时候直接用除法算就可以了
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int x,y,k;
void solve()
{
    cin>>x>>y>>k;
    bool st=0;
    while(k)
    {
        int t=x/y;
        t++;
        int b=t*y;
        int yu=b-x;
        if(k>=yu)
        {
            k-=yu;
            x=t;
            while(x%y==0) x/=y;
        }
        else
        {
            x+=k;
            k=0;
            while(x%y==0) x/=y;
            break;
        }
        while(x%y==0) x/=y;
        if(x==1) break;
    }
    if(x==1)
    {
        int yu=k%(y-1);
        x+=yu;
    }
    cout<<x<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}