/*
 * @Author: dsaDadas11
 * @Date: 2025-01-20 00:20:45
 * @LastEditTime: 2025-01-21 17:18:11
 * @Description: go for it!
 */
/*
 解题思路：
 不连续的数也算斐波那契数，也能加 1
*/
/*
 * @Author: dsaDadas11
 * @Date: 2024-06-27 10:33:26
 * @LastEditTime: 2025-01-21 17:17:27
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int a1,a2,a4,a5;
void solve()
{
    cin>>a1>>a2>>a4>>a5;
    int a31=a1+a2;
    int ans1=1;
    if(a31+a2==a4) ans1++;
    if(a31+a4==a5) ans1++;

    int a32=a4-a2;
    int ans2=1;
    if(a1+a2==a32) ans2++;
    if(a32+a4==a5) ans2++;

    int a33=a5-a4;
    int ans3=1;
    if(a1+a2==a33) ans3++;
    if(a2+a33==a4) ans3++;
    
    cout<<max({ans1,ans2,ans3})<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}