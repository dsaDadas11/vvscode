/*
 * @Author: dsaDadas11
 * @Date: 2025-07-16 19:32:38
 * @LastEditTime: 2025-07-16 19:35:01
 * @Description: go for it!
 */
/*
 解题思路：
 1.1的个数小于等于操作次数直接可以
 2.当 n>=2*k时，Bob一定可以使 1的个数一直保持在 k+1
 3.其余情况，Bob一定会将中间置为 1，Alice可以删除除中间外的 1，使得 1个数越来越少
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,k;
string s;
void solve()
{
    cin>>n>>k;
    cin>>s;
    s=' '+s;
    int cnt=0;
    bool ok=0;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='0') continue;
        cnt++;
    }
    if(cnt<=k)
    {
        cout<<"Alice"<<endl;
        return;
    }
    if(n>=2*k)
    {
        cout<<"Bob"<<endl;
        return;
    }
    cout<<"Alice"<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}