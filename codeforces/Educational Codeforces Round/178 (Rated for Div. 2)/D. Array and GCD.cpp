/*
 * @Author: dsaDadas11
 * @Date: 2025-05-05 12:55:56
 * @LastEditTime: 2025-05-05 12:58:41
 * @Description: go for it!
 */
/*
 解题思路：
 让 n个整数互质，那我们先预处理出质数的前缀和 sum
 然后我们可以找 n个整数中的最大的 x项与质数的最小的 x项比较大小，
 如果 s[x]>=sum[x]，那就说明这 x项可以变为对应的质数，
 那么题目就变成了找 x的最大值
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e7+7;
constexpr int M=4e5+7;
int cnt;
int a[N],p[N];
int sum[M];
void init()
{
    for(int i=2;i<N;i++)
    {
        if(!a[i]) p[++cnt]=i;
        for(int j=1;j<=cnt&&p[j]*i<N;j++)
        {
            a[p[j]*i]=p[j];
            if(!i%p[j]) break;
        }
    }
    for(int i=1;i<M;i++)
    {
        sum[i]=sum[i-1]+p[i];
    }
}
int n;
int b[M];
int s[M];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>b[i];
    sort(b+1,b+1+n,greater<int>());
    for(int i=1;i<=n;i++)
    {
        s[i]=s[i-1]+b[i];
    }
    for(int i=n;i>=0;i--)
    {
        if(s[i]>=sum[i]) return cout<<n-i<<endl,void();
    }
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    init();
    while(T--){solve();}
    return 0;
}