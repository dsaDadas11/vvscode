/*
 * @Author: dsaDadas11
 * @Date: 2025-07-29 20:08:12
 * @LastEditTime: 2025-07-29 20:23:22
 * @Description: go for it!
 */
/*
 解题思路：
 1.gcd(a[l],...,a[r])=gcd(a[l+1]-a[l],....,a[r]-a[r-1])
 因此我们可以发现区间的 gcd不会随着区间值整体的增加而改变
 2.如果要求[1,n]是否为可整除序列，暴力法是 O(n^2),
 但是用笛卡尔树建立一颗小根堆的树，判断父节点能否整除子节点即可，时间复杂度大概 O(n)
 3.我们对整个数组进行分解因数，即将它们的 gcd分解出来，然后将最小的那个数变成 fac[i]所需的 add,
 将整个数组加上 add,建立并且跑一遍笛卡尔树判断是否成立，stk[1]是根节点
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=2e5+7;
constexpr int M=2e3+7;
int n,k;
int a[N],b[N];
int ls[N],rs[N],top,stk[N];
void build(int add)
{
    top=0;
    for(int i=1;i<=n;i++)
    {
        b[i]=a[i]+add;
        ls[i]=rs[i]=stk[i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        while(a[stk[top]]>a[i]&&top) top--;
        if(!top) ls[i]=stk[top+1];
        else ls[i]=rs[stk[top]],rs[stk[top]]=i;
        stk[++top]=i;
    }
}
bool dfs(int l,int r,int u,int fax)
{
    if(fax&&b[u]%b[fax]) return 0;
    if(l>=r) return 1;
    return dfs(l,u-1,ls[u],u)&&dfs(u+1,r,rs[u],u);
}
bool check(int x)
{
    build(x);
    return dfs(1,n,stk[1],0);
}
void solve()
{
    cin>>n>>k;
    int minn=1e12;
    for(int i=1;i<=n;i++) cin>>a[i],minn=min(minn,a[i]);
    int g=0;
    for(int i=2;i<=n;i++) g=gcd(g,a[i]-a[i-1]);
    if(g==0) // 只有一个数或者所有数都相等
    {
        cout<<k<<' '<<k*(k+1)/2<<endl;
        return;
    }
    vector<int> fac; // 找 g的公因数
    for(int i=1;i*i<=g;i++)
    {
        if(g%i==0)
        {
            fac.push_back(i);
            if(i*i!=g) fac.push_back(g/i);
        }
    }

    int cnt=0,sum=0;
    for(auto d:fac)
    {
        int x=d-minn;
        if(x<1||x>k) continue;
        if(check(x)) cnt++,sum+=x;
    }
    cout<<cnt<<' '<<sum<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}