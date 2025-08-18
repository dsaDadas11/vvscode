/*
 * @Author: dsaDadas11
 * @Date: 2025-08-10 19:16:27
 * @LastEditTime: 2025-08-10 19:19:49
 * @Description: go for it!
 */
/*
 解题思路：
 n为奇数时全设为 l即可
 n为偶数时将 a[1]-a[n-2]设为 l, a[n-1],a[n]设为 tarr即可
 tarr就是大于 l且 tarr&l=0的数，也就是 l的最高位 1的后一位
 注意：n=2时不可以，因为没有 l了
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,l,r,k;
int p[67];
void init()
{
    p[0]=1;
    for(int i=1;i<=61;i++) p[i]=p[i-1]*2LL;
}
void solve()
{
    cin>>n>>l>>r>>k;
    if(n&1)
    {
        cout<<l<<endl;
        return;
    }
    if(n-2==0)
    {
        cout<<-1<<endl;
        return;
    }

    int tarl=l;
    vector<int> v;
    while(tarl)
    {
        v.push_back(tarl&1);
        tarl>>=1LL;
    }
    int len=v.size();
    int tarr=p[len];
    if(tarr==0||tarr>r) cout<<-1<<endl;
    else
    {
        if(k<=n-2) cout<<l<<endl;
        else cout<<tarr<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}