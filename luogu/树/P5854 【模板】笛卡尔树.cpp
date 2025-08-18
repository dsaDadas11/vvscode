/*
 * @Author: dsaDadas11
 * @Date: 2025-07-29 17:39:47
 * @LastEditTime: 2025-07-29 17:39:54
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e7+7;
constexpr int M=2e3+7;
int n;
int a[N];
int ls[N],rs[N];
int stk[N],top;
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        while(a[stk[top]]>a[i]&&top) top--;
        if(!top) ls[i]=stk[top+1];
        else ls[i]=rs[stk[top]],rs[stk[top]]=i;
        stk[++top]=i;
    }
    int ans1=0,ans2=0;
    for(int i=1;i<=n;i++)
    {
        ans1^=i*(ls[i]+1);
        ans2^=i*(rs[i]+1);
    }
    cout<<ans1<<' '<<ans2<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}