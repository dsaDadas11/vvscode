/*
 * @Author: dsaDadas11
 * @Date: 2025-04-21 15:19:13
 * @LastEditTime: 2025-04-21 15:20:09
 * @Description: go for it!
 */
/*
 解题思路：
 可以让一个人变成 inf或者 -inf使得 s=sum
 sn题目没说 inf大小，我以为是 1e4，结果是无穷
 早应该过的。。。
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
constexpr int inf1=1e4;
constexpr int inf2=-1e4;
int n,s;
int a[N];
void solve()
{
    cin>>n>>s;
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    if(sum==s) return cout<<n<<endl,void();
    cout<<n-1<<endl;
    return;


    if(s>sum)
    {
        sort(a+1,a+1+n);
        int d=s-sum;
        for(int i=1;i<=n;i++)
        {
            d-=inf1-a[i];
            if(d<=0) return cout<<n-i<<endl,void();
        }
        cout<<"0"<<endl;
    }
    else
    {
        sort(a+1,a+1+n,greater<>());
        int d=s-sum;
        for(int i=1;i<=n;i++)
        {
            d-=inf2+a[i];
            if(d>=0) return cout<<n-i<<endl,void();
        }
        cout<<"0"<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}