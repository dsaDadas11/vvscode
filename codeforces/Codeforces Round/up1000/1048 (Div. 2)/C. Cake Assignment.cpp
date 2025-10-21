/*
 * @Author: dsaDadas11
 * @Date: 2025-09-23 15:43:26
 * @LastEditTime: 2025-09-23 15:44:04
 * @Description: go for it!
 */
/*
 解题思路：
 正难则反，由结果推向初始值
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int k,x;
void solve()
{
    cin>>k>>x;
    int tar=(1LL<<k);
    int a=x,b=(1LL<<(k+1))-x;
    if(a==tar)
    {
        cout<<0<<endl;
        cout<<endl;
        return;
    }
    vector<int> ans;
    while(a!=tar)
    {
        if(a<tar)
        {
            b-=a;
            a<<=1LL;
            ans.push_back(1);
        }
        if(b<tar)
        {
            a-=b;
            b<<=1LL;
            ans.push_back(2);
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for(auto i:ans) cout<<i<<' ';
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}