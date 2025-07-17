/*
 * @Author: dsaDadas11
 * @Date: 2025-06-14 12:10:12
 * @LastEditTime: 2025-06-14 12:10:20
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int month[17]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int calc(int x)
{
    int sum=0;
    while(x)
    {
        sum+=x%10;
        x/=10;
    }
    return sum;
}
bool check(int x)
{
    int t=sqrt(x);
    if(t*t==x) return 1;
    return 0;
}
void solve()
{
    int ans=0;
    for(int i=2001;i<=2021;i++)
    {
        if((i%4==0&&i%100!=0)||(i%400==0)) month[2]=29;
        else month[2]=28;
        for(int j=1;j<=12;j++)
        {
            for(int k=1;k<=month[j];k++)
            {
                int sum=calc(i)+calc(j)+calc(k);
                if(check(sum)) ans++;
            }
        }
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}