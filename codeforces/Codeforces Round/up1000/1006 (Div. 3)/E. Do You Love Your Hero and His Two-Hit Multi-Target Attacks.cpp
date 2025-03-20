/*
 * @Author: dsaDadas11
 * @Date: 2025-03-17 19:02:21
 * @LastEditTime: 2025-03-17 19:07:31
 * @Description: go for it!
 */
/*
 解题思路：
 贪心贪的和题解不太一样，并且样例也不一样，试着交一发居然过了
 如果要曼哈顿距离和欧几里得距离相等，化简一下可以知道 x1=x2或 y1=y2
 那我们就让 x不相等，y相等
 对于相等的 y假设有 i个，那么能凑成对的个数则为 i*(i-1)/2
 那么我们贪心的从大到小找 i1 i2 i3...使得他们的和等于 k即可
 不过要注意的是每组间的 y值不能相等
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int k,mx;
int x,y;
vector<pair<int,int> > ans;
void find_ans()
{
    int tmp=0;
    for(int i=mx;i>=1;i--)
    {
        if(k>=i*(i-1)/2)
        {
            k-=i*(i-1)/2;
            mx=i;
            tmp=i;
            break;
        }
    }
    for(int i=1;i<=mx;i++)
    {
        ans.push_back({x++,y});
    }
    y++;
}
void solve()
{
    cin>>k;
    mx=500;
    x=0,y=0;
    ans.clear();

    while(k)
    {
        find_ans();
    }

    cout<<ans.size()<<endl;
    for(auto [x,y]:ans)
    {
        cout<<x<<' '<<y<<endl;
    }

}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}