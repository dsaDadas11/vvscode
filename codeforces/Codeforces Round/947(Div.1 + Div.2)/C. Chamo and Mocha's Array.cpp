/*
 * @Author: dsaDadas11
 * @Date: 2024-09-28 16:14:53
 * @LastEditTime: 2024-09-28 16:19:08
 * @Description: go for it!
 */
/*
 解题思路：
 这道题要找的是把区间[l,r]变成中位数，求能变成的最大的值
 n==2时就是取最小的了，
 n>=3时，可以三个三个的取中位数，然后求中位数的最大值就能将这个中位数覆盖到每一位
 比如：5 7 6 3 4 2
 我们可以先取区间[1,3]，那么数组变成 6 6 6 3 4 2
 再取[2,4]，再取[3,5]，一直这样往下衍生即可把所有数都变为 6
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e5+7;
constexpr int M=2e3+7;
int n;
int a[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n==2)
    {
        cout<<min(a[1],a[2])<<endl;
        return;
    }
    int ans=0;
    for(int i=2;i<n;i++)
    {
        vector<int> v;
        v.push_back(a[i-1]);
        v.push_back(a[i]);
        v.push_back(a[i+1]);
        sort(v.begin(),v.end());
        ans=max(ans,v[1]); // 求最大中位数
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}