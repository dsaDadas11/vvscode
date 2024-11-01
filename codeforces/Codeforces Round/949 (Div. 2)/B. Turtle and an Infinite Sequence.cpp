/*
 * @Author: dsaDadas11
 * @Date: 2024-10-06 19:59:30
 * @LastEditTime: 2024-10-06 20:03:03
 * @Description: go for it!
 */
/*
 解题思路：
 一开始题目读假了，看了眼题解之后发现
  m秒后 ai = ai-m ^ ai-m+1 ^ ... ^ ai ^ ... ^ ai+m
  这个数永远是奇数，因此我们先取它们二进制前面有多少的共同位，
  然后后面的二进制就是+1 +1 的进行，比如 01 10 11，因此异或完全是1，
  我们用pow求一下然后减1就求出这些1的值了，然后最后或上 n+m 即可
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m;
int quickpow(int x,int y)
{
    int ans=1;
    while(y)
    {
        if(y&1) ans*=x;
        x*=x;
        y>>=1;
    }
    return ans;
}
void solve()
{
    cin>>n>>m;
    int x1=max(0LL,n-m);
    int x2=n+m;
    vector<int> v1,v2;
    while(x1)
    {
        v1.push_back(x1&1);
        x1>>=1;
    }
    while(x2)
    {
        v2.push_back(x2&1);
        x2>>=1;
    }
    int len=max((int)(v1.size()),(int)v2.size());
    for(int i=v1.size();i<len;i++) v1.push_back(0);
    for(int i=v2.size();i<len;i++) v2.push_back(0);
    reverse(v1.begin(),v1.end());
    reverse(v2.begin(),v2.end());
    int cnt=0;
    for(int i=0;i<len;i++)
    {
        if(v1[i]==v2[i]) cnt++;
        else break;
    }
    cnt=len-cnt;
    cnt=quickpow(2,cnt)-1;
    cout<<((n+m)|cnt)<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}