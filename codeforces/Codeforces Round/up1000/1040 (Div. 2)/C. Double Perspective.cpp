/*
 * @Author: dsaDadas11
 * @Date: 2025-08-08 11:00:27
 * @LastEditTime: 2025-08-08 11:00:35
 * @Description: go for it!
 */
/*
 解题思路：
 选左端点最靠右的位置即可，这样可以保证不会出现环，且线段范围最大
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
void solve()
{
    cin>>n;
    vector<int> R(2*n+1),idx(2*n+1,-1);
    for(int i=1;i<=n;i++)
    {
        int l,r;
        cin>>l>>r;
        if(r>R[l])
        {
            R[l]=r;
            idx[l]=i;
        }
    }
    vector<int> ans;
    for(int i=1;i<=2*n;i++)
    {
        if(idx[i]!=-1) ans.push_back(idx[i]);
    }
    cout<<ans.size()<<endl;
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