/*
 * @Author: dsaDadas11
 * @Date: 2025-07-18 15:30:05
 * @LastEditTime: 2025-07-18 15:30:48
 * @Description: go for it!
 */
/*
 解题思路：
 整体思路是对的，但是有个 trick没处理好，最终还是过了 ^_^
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
string s;
void solve()
{
    cin>>s;
    int n=s.size();
    s=' '+s;
    bool flag=1;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='-') flag=0;
    }
    if(flag||s[1]=='-'||s[n]=='-') return cout<<"No"<<endl,void();

    // 先找出最右边的箭头
    int cnt=0;
    for(int i=n;i>=1;i--)
    {
        if(s[i]=='-') break;
        cnt++;
    }
    if(cnt<3) return cout<<"No"<<endl,void();

    int tmp=cnt;
    vector<pair<int,int> > ans;
    // 先把末尾处理
    cnt-=3;
    for(int i=0;i<=cnt;i++)
    {
        ans.push_back({1,n-i});
    }

    // 再找中间的 >
    for(int i=2;i<=n-tmp;i++)
    {
        if(s[i]=='-') continue;
        ans.push_back({i,n-i+1-(tmp-3)});
    }
    cout<<"Yes "<<ans.size()<<endl;
    for(auto [x,y]:ans) cout<<x<<' '<<y<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}