/*
 * @Author: dsaDadas11
 * @Date: 2025-09-28 13:55:13
 * @LastEditTime: 2025-09-28 13:57:21
 * @Description: go for it!
 */
/*
 解题思路：
 算 a,b的总逆序对数就是答案，(不知道怎么来的)
 每次循环位移会使逆序对的奇偶性变换 r-l次，
 每交换 1次，奇偶性变换 1次，每次循环位移交换 r-l次
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int lowbit(int x)
{
    return x&(-x);
}
int n;
int a[N],b[N];
int tr[N];
int l,r,d;
char c;
void add(int p,int val)
{
    for(int i=p;i<=n;i+=lowbit(i)) tr[i]+=val;
}
int ask(int p)
{
    int ans=0;
    for(int i=p;i;i-=lowbit(i)) ans+=tr[i];
    return ans;
}
void pri(int ans)
{
    if(ans&1) cout<<"A";
    else cout<<"B";
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) tr[i]=0;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        ans+=i-1-ask(a[i]);
        add(a[i],1);
    }
    for(int i=1;i<=n;i++) tr[i]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        ans+=i-1-ask(b[i]);
        add(b[i],1);
    }
    pri(ans);
    for(int i=1;i<n;i++)
    {
        cin>>c>>l>>r>>d;
        ans+=(r-l)*d; // 每循环位移一次，逆序对变换 r-l次
        pri(ans);
    }
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}