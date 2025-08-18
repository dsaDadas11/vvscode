/*
 * @Author: dsaDadas11
 * @Date: 2025-08-04 14:15:24
 * @LastEditTime: 2025-08-04 14:19:07
 * @Description: go for it!
 */
/*
 解题思路：
 a,b中的一个每次减少 gcd(a,b)
 从二进制角度来看，俩个数的最低位置的1一定是俩个数的一个公约数，这样每次都可以通过消除最低位置的1来减少
 将 5000减少到 1的次数非常少，最多 12*2+1=25  (2^12=4096, a和 b的12位都是 1)
 因此可以直接暴力搜索
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int a,b;
void solve()
{
    cin>>a>>b;
    queue<array<int,3> > q;
    q.push({a,b,0});
    while(!q.empty())
    {
        auto [x,y,stp]=q.front();
        q.pop();
        if(x==0||y==0)
        {
            cout<<stp+1<<endl;
            return;
        }
        int d=gcd(x,y);
        q.push({x-d,y,stp+1});
        q.push({x,y-d,stp+1});
    }
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}