/*
 * @Author: dsaDadas11
 * @Date: 2025-03-20 22:13:43
 * @LastEditTime: 2025-03-20 22:19:40
 * @Description: go for it!
 */
/*
 解题思路：
 居然能二分答案，
 本人以为二分之后不会得到 l==a[i]就没想下去了，也算是学到了
 我们二分答案，然后找如果要修改成 mid的最小操作次数，如果可以则 true，否则 false
 1.a[i]<=x 的不用管，对答案没影响
 2.s[i]=='B'&&a[i]>x 这时候必须涂了，不涂则影响答案
 3.s[i]=='R'&&a[i]>x 这个时候不能涂
 因此我们从第二点用双指针枚举到第三点记录 cnt即可
 不过注意的 hack点是 j必须要写外面，不然 j循环完了还没有 if就不能给 i赋值了，可以参考样例：
 4 1
 BRBR
 9 3 5 4
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=3e5+7;
constexpr int M=2e3+7;
int n,k;
string s;
int a[N];
bool check(int x)
{
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='B'&&a[i]>x)
        {
            cnt++;
            int j;
            for(j=i;j<=n;j++)
            {
                if(s[j]=='R'&&a[j]>x) break;
            }
            i=j;
        }
    }
    if(cnt<=k) return 0;
    return 1;
}
void solve()
{
    cin>>n>>k;
    cin>>s;
    s=' '+s;
    for(int i=1;i<=n;i++) cin>>a[i];
    int l=0,r=*max_element(a+1,a+1+n);
    while(l<r)
    {
        int mid=(l+r)>>1;
        if(check(mid)) l=mid+1;
        else r=mid;
    }
    cout<<l<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}