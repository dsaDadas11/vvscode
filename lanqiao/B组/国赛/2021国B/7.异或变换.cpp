/*
 * @Author: dsaDadas11
 * @Date: 2025-06-14 13:02:08
 * @LastEditTime: 2025-06-14 13:02:16
 * @Description: go for it!
 */
/*
 循环次数和 2的倍数有关系
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,t;
string s;
char calc(int a,int b)
{
    return char((a^b)+'0');
}
void solve()
{
    cin>>n>>t;
    cin>>s;
    int c=1;
    while(c<n) c<<=1;
    t%=c;
    for(int k=1;k<=t;k++)
    {
        string t=s;
        for(int i=1;i<n;i++)
        {
            t[i]=calc(s[i]-'0',s[i-1]-'0');
        }
        s=t;
    }
    cout<<s<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}