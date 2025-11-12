/*
 * @Author: dsaDadas11
 * @Date: 2025-11-02 16:34:14
 * @LastEditTime: 2025-11-02 16:34:24
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e5+7;
constexpr int M=2e3+7;
int n,m;
string s;
int a[N];
void solve()
{
    cin>>n>>m;
    cin>>s;
    s=' '+s;
    set<int> se;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i];
        se.insert(a[i]);
    }
    int lst=2,now=1;

    for(int i=1;i<=n;i++)
    {
        lst=max(lst,now+1);
        if(s[i]=='A')
        {
            now++;
            se.insert(now);
        }
        else
        {
            // 跳一次
            while(se.count(lst)) lst++;
            se.insert(lst);
            lst++;
            // 跳第二次
            while(se.count(lst)) lst++;
            now=lst;
            lst++;
        }
    }

    cout<<se.size()<<endl;
    for(auto i:se) cout<<i<<' ';
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}