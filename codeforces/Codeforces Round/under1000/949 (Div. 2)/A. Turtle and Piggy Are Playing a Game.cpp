/*
 * @Author: dsaDadas11
 * @Date: 2024-10-06 19:13:37
 * @LastEditTime: 2024-10-06 19:13:55
 * @Description: go for it!
 */
/*
 解题思路：
 找一个区间内有多少个2即可
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int l,r;
int p[50];
void pre()
{
    p[0]=1;
    for(int i=1;i<=35;i++)
    {
        p[i]=p[i-1]*2;
    }
}
void solve()
{
    cin>>l>>r;
    vector<int> ans;
    for(int i=0;i<=35;i++)
    {
        if(p[i]>=l&&p[i]<=r)
        {
            ans.push_back(i);
        }
    }
    cout<<ans.back()<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    pre();
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}