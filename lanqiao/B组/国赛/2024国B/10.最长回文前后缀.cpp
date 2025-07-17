/*
 * @Author: dsaDadas11
 * @Date: 2025-06-07 19:06:16
 * @LastEditTime: 2025-06-07 19:09:08
 * @Description: go for it!
 */
/*
 解题思路：
 二分答案，首先把已知的前后缀删去，然后从剩下的 s开始删前后缀，这样能避免出现删中间的情况
 还有 rha得反着算
 记得写初始化后要写 init，debug半天发现没写 init。。。
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int unsigned long long
using namespace std;
constexpr int N=5e5+7;
constexpr int M=2e3+7;
int base=131;
int p[N],ha[N],rha[N],n;
void init()
{
    p[0]=1;
    for(int i=1;i<N;i++)
    {
        p[i]=p[i-1]*base;
    }
}
int get(int l,int r)
{
    return ha[r]-ha[l-1]*p[r-l+1];
}
int getr(int l,int r)
{
    return rha[l]-rha[r+1]*p[r-l+1];
}
string s;
bool check(int len)
{
    // 去前缀
    for(int i=len;i<=n-len;i++)
    {
        if(get(i-len+1,i)==getr(n-len+1,n)) return 1;
    }

    // 去后缀
    for(int i=len+len;i<=n;i++)
    {
        if(get(1,len)==getr(i-len+1,i)) return 1;
    }

    return 0;
}
void solve()
{
    cin>>s;
    int L=0,R=s.size()-1;
    while(s[L]==s[R]&&L<R) L++,R--; // 由题可知，L不能等于 R，
    string t="";
    for(int i=L;i<=R;i++) t.push_back(s[i]);
    s=t;
    n=s.size();
    s=' '+s;
    for(int i=1;i<=n;i++)
    {
        ha[i]=ha[i-1]*base+s[i]-'a'+1;
    }
    for(int i=n;i>=1;i--)
    {
        rha[i]=rha[i+1]*base+s[i]-'a'+1;
    }
    int l=0,r=(n+1)/2;
    while(l<r)
    {
        int mid=(l+r+1)>>1;
        if(check(mid)) l=mid;
        else r=mid-1;
    }
    cout<<l+L<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}