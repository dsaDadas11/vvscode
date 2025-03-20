/*
 * @Author: dsaDadas11
 * @Date: 2025-03-20 21:33:55
 * @LastEditTime: 2025-03-20 21:34:35
 * @Description: go for it!
 */
/*
 不要化简为繁
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,x,k;
string s;
void solve()
{
    cin>>n>>x>>k;
    cin>>s;

    int tmp=x;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='L') tmp--;
        else tmp++;
        if(tmp==0)
        {
            cnt=i+1;
            break;
        }
    }
    if(cnt==0) return cout<<"0"<<endl,void();

    tmp=0;
    int xun=2e18;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='L') tmp--;
        else tmp++;
        if(tmp==0)
        {
            xun=i+1;
            break;
        }
    }
    k-=cnt;
    int ans=1;
    ans+=k/xun;
    cout<<ans<<endl;
    
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}