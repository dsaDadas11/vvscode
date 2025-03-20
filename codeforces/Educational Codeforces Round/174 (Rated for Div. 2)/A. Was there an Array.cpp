/*
 * @Author: dsaDadas11
 * @Date: 2025-03-09 10:26:57
 * @LastEditTime: 2025-03-09 10:27:19
 * @Description: go for it!
 */
/*
 解题思路：
 010是不行的
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
int b[107];
void solve()
{
    cin>>n;
    for(int i=2;i<=n-1;i++) cin>>b[i];
    for(int i=3;i<=n-2;i++)
    {
        if(b[i-1]==1&&b[i+1]==1&&b[i]==0) return cout<<"NO"<<endl,void();
    }
    cout<<"YES"<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}