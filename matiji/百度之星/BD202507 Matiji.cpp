/*
 * @Author: dsaDadas11
 * @Date: 2025-08-08 15:06:49
 * @LastEditTime: 2025-08-08 15:07:09
 * @Description: go for it!
 */
/*
 解题思路：
 选比自己大的就行
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,s;
int a[N];
void solve()
{
    cin>>n>>s;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]>s) s=(s+a[i]+1)/2;
    }
    cout<<s<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}