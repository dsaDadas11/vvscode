/*
 * @Author: dsaDadas11
 * @Date: 2025-07-20 19:59:14
 * @LastEditTime: 2025-07-20 20:11:56
 * @Description: go for it!
 */
/*
 解题思路：
 很锻炼思维的一道题，我们可以遍历红块，然后找每个红块被限制在一个区间 [lst+1, b[j]-1]的范围
 然后再用一个指针 xi在这个范围内往后遍历的找可以和 a[i]一起被覆盖的最大的那个 xi
 然后再找这个纸张能被放在的区间范围 (换做是我的话，就会先放纸张，再求范围是否合适)
 纸张能放置的左区间 l=max(lst+1,a[xi]-k+1)
     能放置的右区间 r=min(b[j]-k,a[i])
     如果 l>r的话说明纸张不能放置，输出 -1
 然后我们知道了每个纸张都能够放置，如果有两个纸张重叠的话，就将前一个纸张往前移
 if(ans[i]-ans[i-1]+1<=k) ans[i-1]=ans[i]-k

*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m,k,w;
int a[N],b[N];
void solve()
{
    cin>>n>>m>>k>>w;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>b[i];
    b[++m]=w+1;
    sort(a+1,a+1+n);
    sort(b+1,b+1+m);
    int j=1,lst=0;
    int l=0,r=0;
    vector<int> ans;
    for(int i=1;i<=n;i++)
    {
        while(b[j]<a[i]) j++,lst=b[j-1];
        int xi=i;
        while(xi+1<=n&&a[xi+1]<b[j]&&(a[xi+1]-a[i]+1<=k)) xi++;
        // 纸张可以放在 [l,r]的任意位置
        l=max(lst+1,a[xi]-k+1);
        r=min(b[j]-k,a[i]);
        if(l>r) return cout<<"-1"<<endl,void();
        ans.push_back(l);
        i=xi;
        lst+=k;
    }
    cout<<ans.size()<<endl;
    for(int i=ans.size()-1;i>=1;i--)
    {
        if(ans[i]-ans[i-1]+1<=k) ans[i-1]=ans[i]-k;
    }
    for(auto i:ans) cout<<i<<' ';
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}