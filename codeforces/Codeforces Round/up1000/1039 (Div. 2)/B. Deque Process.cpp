/*
 * @Author: dsaDadas11
 * @Date: 2025-08-02 10:43:54
 * @LastEditTime: 2025-08-02 10:46:47
 * @Description: go for it!
 */
/*
 解题思路：
 我们可以保证 q1 < q2 > q3 < q4 > q5....
 我们可以按奇偶轮次挑选最大最小值
 首先我们挑最小即 min(p[l],p[r]),假设 p[l]最小
 那么再下一轮挑最大值时  max(p[l+1],p[r]) >= p[r]
 这样就能保证了最小最大依次轮回
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
int p[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>p[i];
    int l=1,r=n;
    int cnt=1;
    while(l<=r)
    {
        if(cnt&1)
        {
            if(p[l]<p[r])
            {
                cout<<"L";
                l++;
            }
            else
            {
                cout<<"R";
                r--;
            }
        }
        else
        {
            if(p[l]>p[r])
            {
                cout<<"L";
                l++;
            }
            else
            {
                cout<<"R";
                r--;
            }
        }
        cnt++;
    }
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}