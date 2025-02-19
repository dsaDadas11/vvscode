/*
 * @Author: HuangCe
 * @Date: 2025-02-17 19:11:56
 * @LastEditTime: 2025-02-17 19:12:15
 * @Description: go for it!
 */
/*
 解题思路：
 后缀和
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=5e5+7;
constexpr int M=2e3+7;
int k;
string s;
char a,b;
int suf[N];
void solve()
{
    cin>>k;
    cin>>s>>a>>b;
    int len=s.size();
    s=' '+s;
    for(int i=len;i>=1;i--)
    {
        suf[i]=suf[i+1]+(s[i]==b);
    }
    int ans=0;
    for(int i=1;i<=len-k+1;i++)
    {
        if(s[i]==a)
        {
            ans+=suf[i+k-1];
        }
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}