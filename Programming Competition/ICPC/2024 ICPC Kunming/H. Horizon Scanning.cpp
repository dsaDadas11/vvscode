/*
 * @Author: dsaDadas11
 * @Date: 2025-08-04 09:44:43
 * @LastEditTime: 2025-08-04 09:48:41
 * @Description: go for it!
 */
/*
 解题思路：
 想到要排序取 [i,i+k]的最大值 (要取 k+1个数，为了防止角度偏移损失一个点)，但是不知道如何排序
 用 atan2(y,x)函数返回的是原点至点(x,y)的方位角，即与 x 轴的夹角,因此我们可以用这个计算后排序，
 并且 pi=acos(-1.0)，我们需要将前面的点都加上 2*pi，也就是多转一圈，因为有些弧不知道是优弧还是劣弧
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,k;
int x,y;
double pi=acos(-1.0);
void solve()
{
    cin>>n>>k;
    vector<double> v;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>y;
        v.push_back(atan2(y,x));
    }
    sort(v.begin(),v.end());
    
    for(int i=n;i<2*n;i++)
    {
        v.push_back(v[i-n]+2*pi);
    }
    
    double ans=0.0;
    for(int i=k;i<2*n;i++)
    {
        ans=max(ans,abs(v[i]-v[i-k]));
    }
    cout<<fixed<<setprecision(10)<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}