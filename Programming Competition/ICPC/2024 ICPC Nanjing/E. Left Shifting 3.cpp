/*
 * @Author: dsaDadas11
 * @Date: 2025-07-20 16:19:45
 * @LastEditTime: 2025-07-20 16:20:57
 * @Description: go for it!
 */
/*
 解题思路：
 发现移位之后最多只能多产生 1的贡献，因此只需判断这个贡献需要移位多少次
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
    int ans=0;
    int p=0;
    while((p=s.find("nanjing",p))!=s.npos)
    {
        ans++;
        p++;
    }

    s=' '+s+s;
    p=1;
    int l=0,r=0;
    while((p=s.find("nanjing",p))!=s.npos)
    {
        l=p;
        r=l+7-1;
        if(r>=n) break;
        p++;
    }
    if(l<=n&&r>n&&r-n<=k) ans++;
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}