/*
 * @Author: dsaDadas11
 * @Date: 2025-10-30 19:06:22
 * @LastEditTime: 2025-10-30 19:14:45
 * @Description: go for it!
 */
/*
 解题思路：
 1.22能被哪些范围的数表示？
 [1.215000...,1.224999...]
 因此我们会发现有一个 [-0.05000...,+0.04999...]的范围

 然后我们对 b[i]/m ≈ a[i] 推出 a[i]*m ≈ b[i]，两边求和变成 sum(a)*m ≈ m，
 那么 sum(a) ≈ 1，sum(d) ≈ 100

 那么我们可以令 m=100，然后用 d[i]上下浮动 [-0.05000...,+0.04999...]的范围，使得 sum(d) = 100 = m
 此时 b[i]/100 = a[i] = d[i]/100  =>   b[i] = d[i]
 处理浮点数不方便，因此可以把它们都扩大 10的次方倍数即可
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=2e5+7;
constexpr int M=2e3+7;
int n;
int d[N];
void solve()
{
    cin>>n;
    int m=0;
    for(int i=1;i<=n;i++)
    {
        cin>>d[i];
        d[i]*=10000000;
        if(d[i]>=5000000)
        {
            d[i]-=5000000;
            m+=d[i];
        }
    }

    for(int i=1;i<=n;i++)
    {
        if(m>=1000000000) continue;
        int tmp=min(1000000000-m,9999999LL);
        if(d[i]==0) tmp=min(tmp,4999999LL);
        d[i]+=tmp;
        m+=tmp;
    }

    if(m!=1000000000)
    {
        cout<<"NO"<<endl;
        return;
    }

    cout<<"YES"<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<d[i]<<' '; // 不需要除，因为 m和 d[i]同时乘了相同的倍数
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