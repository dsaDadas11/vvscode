/*
 * @Author: dsaDadas11
 * @Date: 2025-08-11 15:34:25
 * @LastEditTime: 2025-08-11 15:41:56
 * @Description: go for it!
 */
/*
 解题思路：
 g^(p-1) = 1 (mod p) (^是异或哈)
 我们可以转换成 g^(p-1) = k*p+1，两边同时异或 p-1得 g = (k*p+1)^(p-1)
 异或的性质：a-b <= a^b <= a+b
 由此我们可以得到：(k-1)*p+2 <= g <= (k+1)*p (k>=0)
 当 (k+1)*p <= m时这个不等式恒成立，因此先将 ans置为 m/p向下取整
 然后就是上界大于 m，下界小于等于 m的情况，我们可以令 k=m/p。
 会发现下界变为 m-p+2是 <= m的，如果 m/p是向下取整的那就是 <m，如果向上取整就 >m
 因此我们从 m/p枚举到 (m+p-1)/p，判断是否小于等于 m即可
 要注意异或的优先级非常低，要加括号
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int p,m;
void solve()
{
    cin>>p>>m;
    int ans=m/p;
    for(int k=m/p;k<=(m+p-1)/p;k++)
    {
        if(((k*p+1)^(p-1))<=m) ans++;
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}