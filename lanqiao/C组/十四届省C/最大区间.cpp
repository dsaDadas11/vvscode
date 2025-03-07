/*
 * @Author: dsaDadas11
 * @Date: 2025-03-05 21:40:26
 * @LastEditTime: 2025-03-05 21:44:25
 * @Description: go for it!
 */
/*
 解题思路：
 很容易想到单调栈，但是不好处理
 我们可以找左边第一个比它小的数，右边第一个比它小的数，
 然后往中间缩一位，那就是 r[i]-l[i]-1
 初始化边界：l[i]为下标第一位的前一位 0，r[i]为下标最后一位的后一位 n+1
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
int a[N];
int l[N],r[N]; // 记录 i为最小值的左右边界
int stk[N];
int p;
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        l[i]=0,r[i]=n+1;
    }

    // 先找左边界
    for(int i=1;i<=n;i++)
    {
        while(p!=0&&a[i]<=a[stk[p]]) p--;
        if(p) l[i]=stk[p];
        stk[++p]=i;
    }
    
    p=0;
    // 再找右边界
    for(int i=n;i>=1;i--)
    {
        while(p!=0&&a[i]<=a[stk[p]]) p--;
        if(p) r[i]=stk[p];
        stk[++p]=i;
    }

    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,(r[i]-l[i]-1)*a[i]);
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}