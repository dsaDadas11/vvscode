/*
 * @Author: HuangCe
 * @Date: 2025-02-11 13:11:59
 * @LastEditTime: 2025-02-11 13:12:06
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
    int n=s.size();
    s=' '+s;
    int p=0;
    for(int i=1;i<n;i++)
    {
        if(s[i]==s[i+1])
        {
            p=i;
        }
    }
    if(p) cout<<"1"<<endl;
    else cout<<n<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}