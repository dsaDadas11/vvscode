/*
 * @Author: dsaDadas11
 * @Date: 2025-08-08 15:41:34
 * @LastEditTime: 2025-08-08 16:18:14
 * @Description: go for it!
 */
/*
 解题思路：
 什么样的数能被 [l,r]表示呢？
 1.当 l=1时所有的都能被表示，
 2.当 l=r且!=1时只有 l的倍数能被表示
 3.当 r>l时：
 带余除法，令 x = a*l + b  (0<=b<=l-1),但是 b没在 [l,r]范围内，
 于是 x = (a-1)*l + (b+l)  (l<=b+l<=2*l-1)
 于是我们可以发现如果 r>=2*l-1的话，x>l的数都能被表示出来
 如果 r<2*l-1，那么会发现区间覆盖会有空隙，设有两个区间 [a*l,a*r] [(a+1)*l,(a+1)*r]
 那么区间空隙 d = (a+1)*l - a*r -1 = l-1 - a*(r-l)
 会发现 d是关于 a的首项 a0=l-1,公差为 r-l的等差数列，n=floor( (r-l)/(l-1) ),总共有 n+1项
 不能被表示的数的数量 sum = (n+1)*(l-1)-(n*(n+1)/2)*(r-l)
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int l,r;
void solve()
{
    cin>>l>>r;
    if(l==1)
    {
        cout<<0<<endl;
        return;
    }
    if(l==r)
    {
        cout<<"infty"<<endl;
        return;
    }
    int n=(l-1)/(r-l);
    cout<<(n+1)*(l-1)-(n*(n+1)/2)*(r-l)<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}