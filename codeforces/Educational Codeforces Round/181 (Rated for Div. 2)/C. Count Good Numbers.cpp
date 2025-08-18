/*
 * @Author: dsaDadas11
 * @Date: 2025-07-22 23:18:02
 * @LastEditTime: 2025-07-23 20:52:51
 * @Description: go for it!
 */
/*
 解题思路：
 题目要求大于等于 2位的质数，我们可以列举 1位质数：2 3 5 7
 然后进行容斥
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int p[7];
int calc(int x)
{
    int cnt=0;
    while(x)
    {
        if(x&1) cnt++;
        x>>=1;
    }
    return cnt;
}
int di(int x)
{
    if(x<=0) return 0;
    int ans=x;
    for(int i=1;i<16;i++)
    {
        int l=1;
        for(int j=1;j<=4;j++)
        {
            if(i&(1<<(j-1))) l*=p[j];
        }
        int dx=x/l,cnt=calc(i);
        if(cnt&1) ans-=dx;
        else ans+=dx;
    }
    return ans;
}
int l,r;
void solve()
{
    cin>>l>>r;
    cout<<di(r)-di(l-1)<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    p[1]=2,p[2]=3,p[3]=5,p[4]=7;
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}

/*
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int l,r;
vector<int> p{2,3,5,7};
// 如果 i从 1开始，ans=x
// 如果从 0开始，ans=0
int di(int x)
{
    int ans=1;
    // 4个质数有 16种不同的选举方案
    for(int i=0;i<(1<<4);i++)
    {
        int s=1;
        int cnt=0;
        for(int j=0;j<4;j++)
        {
            if(i&(1<<j)) s*=p[j],cnt++;
        }
        int dx=x/s;
        // 容斥
        if(cnt&1) ans-=dx;
        else ans+=dx;
    }
    return ans;
}
void solve()
{
    cin>>l>>r;
    cout<<di(r)-di(l-1)<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}
*/