/*
 * @Author: HuangCe
 * @Date: 2025-02-11 13:02:19
 * @LastEditTime: 2025-02-11 13:02:26
 * @Description: go for it!
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
    for(int i=0;i<(int)s.size()-2;i++)
    {
        cout<<s[i];
    }
    cout<<"i"<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}