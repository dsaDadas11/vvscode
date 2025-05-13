/*
 * @Author: dsaDadas11
 * @Date: 2025-04-17 20:38:38
 * @LastEditTime: 2025-04-17 20:41:12
 * @Description: go for it!
 */
/*
 解题思路：
 题读假了，题目意思是前 k个可以随意染色，最后一个染色要从前 k个相邻的位置染，然后计算最大贡献
 1.k=1时，这时候我们只能将最后一个染色染到边界的情况
 2.k>=2时，染到的最后位置是任意的，因此就是取前 k+1个最大的数
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e4+7;
constexpr int M=2e3+7;
int n,k;
int a[N];
void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(k==1)
    {
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(i==1||i==n) ans=max(ans,a[1]+a[n]);
            else ans=max(ans,a[i]+max(a[1],a[n]));
        }
        cout<<ans<<endl;
    }
    else
    {
        int ans=0;
        sort(a+1,a+1+n,greater<>());
        for(int i=1;i<=k+1;i++) ans+=a[i];
        cout<<ans<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}