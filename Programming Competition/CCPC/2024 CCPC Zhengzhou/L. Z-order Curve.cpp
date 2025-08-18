/*
 * @Author: dsaDadas11
 * @Date: 2025-08-07 09:58:27
 * @LastEditTime: 2025-08-07 10:08:57
 * @Description: go for it!
 */
/*
 解题思路：
 这居然是签到题。。看不出来
 首先我们可以发现一个大 Z由四个小 z组合而成，
 2^k-1     2*2^k-1
 3*2^k-1   4*2^k-1
 我们可以发现四个小 z的 l,r在 z内二进制位上相同，但是在不同小 z中不同，
 因此如果 l,r的二进制位不同的话就说明大 z不能继续划分成更小的 z,否则就把此位置为 0,继续下一位
 置为 0就代表 左下、右上、右下的小 z递归到左上了，然后左上的小 z又可以看作新的大 z继续递归
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
    for(int i=63;i>=0;i--)
    {
        if(((l>>i)&1)!=((r>>i)&1))
        {
            cout<<l<<endl;
            return;
        }
        l&=((1LL<<i)-1);
        r&=((1LL<<i)-1);
    }
    cout<<l<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}