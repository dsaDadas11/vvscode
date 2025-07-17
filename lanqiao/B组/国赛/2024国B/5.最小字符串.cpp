/*
 * @Author: dsaDadas11
 * @Date: 2025-06-07 15:07:05
 * @LastEditTime: 2025-06-07 15:09:09
 * @Description: go for it!
 */
/*
 解题思路：
 为什么 s[cnts]<=t[cntt]不能写 <
 因为 s是未排序的，t是已排序的，
 s的后一个字符可能更小，但 t的后一个字符一定更大，因此先排 s可以让后面小的排上去
hack：
7 3
lanqiao
lzz
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m;
string s,t;
void solve()
{
    cin>>n>>m;
    cin>>s>>t;
    sort(t.begin(),t.end());
    string ans="";
    int cnts=0,cntt=0;
    while(cnts<n&&cntt<m)
    {
        if(s[cnts]<=t[cntt])
        {
            ans+=s[cnts];
            cnts++;
        }
        else
        {
            ans+=t[cntt];
            cntt++;
        }
    }
    while(cnts<n)
    {
        ans+=s[cnts];
        cnts++;
    }
    while(cntt<m)
    {
        ans+=t[cntt];
        cntt++;
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