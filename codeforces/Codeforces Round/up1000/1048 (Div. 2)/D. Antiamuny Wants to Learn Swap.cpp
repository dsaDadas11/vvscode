/*
 * @Author: dsaDadas11
 * @Date: 2025-09-23 16:37:40
 * @LastEditTime: 2025-09-23 16:41:23
 * @Description: go for it!
 */
/*
 解题思路：
 找出区间 [l,r]中是否存在 i,j,k使得 ai >= aj >= ak
 对于每个 j，我们往前找最大位置的那个 ai >= aj，往后找最小位置的那个 ak <= aj (其实就是最接近 j的 i和 k)
 处理完后，我们让 i位置指向 k位置，也就是 R[i] = k，此时 [i,k]就是一个符合的区间，
 我们可以用 st表处理出 R[i]的区间最小值，每次询问时判断最小值是否 <= r即可
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=5e5+7;
constexpr int M=2e3+7;
int n,q;
int a[N];
int stk[N],p;
int R[N];
int f[N][20],lg[N];
void init()
{
    // 避免浮点运算，加快速度
    lg[1]=0;
    for(int i=2;i<N;i++)
    {
        lg[i]=lg[i-1]+((1<<(lg[i-1]+1))==i);
    }
}
void pre()
{
    for(int i=1;i<=n;i++) f[i][0]=R[i];
    for(int j=1;j<20;j++)
    {
        for(int i=1;i+(1<<j)-1<=n;i++)
        {
            f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
        }
    }
}
int query(int l,int r)
{
    int k=lg[r-l+1];
    return min(f[l][k],f[r-(1<<k)+1][k]);
}
void solve()
{
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i],R[i]=n+1;

    vector<int> maxl(n+2,0),minr(n+2,n+1);
    p=0;
    for(int i=1;i<=n;i++)
    {
        while(p&&a[stk[p]]<a[i]) p--;
        if(p) maxl[i]=stk[p];
        stk[++p]=i;
    }

    p=0;
    for(int i=n;i>=1;i--)
    {
        while(p&&a[stk[p]]>a[i]) p--;
        if(p) minr[i]=stk[p];
        stk[++p]=i;
    }

    // for(int i=1;i<=n;i++) cout<<maxl[i]<<' '<<minr[i]<<endl;
    for(int i=1;i<=n;i++)
    {
        R[maxl[i]]=min(R[maxl[i]],minr[i]);
    }
    pre();

    int l,r;
    while(q--)
    {
        cin>>l>>r;
        if(query(l,r)<=r) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
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