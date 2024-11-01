/*
 * @Author: dsaDadas11
 * @Date: 2024-10-02 12:24:34
 * @LastEditTime: 2024-10-02 16:21:58
 * @Description: go for it!
 */
/*
 解题思路：
 推导一下可以知道递推公式为 m(i)=m(i-1)/2+a[i]
 因为涉及到除法，如果用int或者long double算会丢失精度，包wa的
 因此我们想到分整数位和小数位 (但是不能用分子和分母，莫名其妙会re)
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e5+7;
constexpr int M=2e3+7;
int n;
int a[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int x=0,d=0;
    for(int i=1;i<=n;i++)
    {
        if(x%2!=0) d=x%2;
        x=x/2+a[i];
        if(x<0) cout<<"-";
        else if(x==0&&d==0) cout<<"0";
        else if(x==0&&d<0) cout<<"-";
        else cout<<"+";
    }
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}