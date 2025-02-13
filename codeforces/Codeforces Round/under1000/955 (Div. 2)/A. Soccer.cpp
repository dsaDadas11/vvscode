/*
 * @Author: dsaDadas11
 * @Date: 2025-01-22 11:17:50
 * @LastEditTime: 2025-01-22 11:18:17
 * @Description: go for it!
 */
/*
 解题思路：
 只要包含在区间里面就肯定能碰上
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int xx1,yy1;
int xx2,yy2;
void solve()
{
    cin>>xx1>>yy1;
    cin>>xx2>>yy2;
    if(xx1<=yy1&&xx2>=yy2)
    {
        cout<<"NO"<<endl;
        return;
    }
    if(yy1<=xx1&&xx2<=yy2)
    {
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}