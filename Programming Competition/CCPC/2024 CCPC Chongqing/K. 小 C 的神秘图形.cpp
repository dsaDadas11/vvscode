/*
 * @Author: dsaDadas11
 * @Date: 2025-01-12 13:38:25
 * @LastEditTime: 2025-01-16 11:19:18
 * @Description: go for it!
 */
/*
 解题思路：
 题目条件为若 3^(n-1) <= i < 2*3^(n-1) 或者 3^(n-1) <= j < 2*3^(n-1) 才能往 n-1进行递推
 那么也就是三进制首位是 1才能往下递推
 而公式中又要求模上 3^(n-1) 就相当于把三进制首位给去掉了，也就是 pop掉了
 因此模拟即可
*/
#include<bits/stdc++.h>
#include<algorithm>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
string a,b;
void solve()
{
    cin>>n;
    cin>>a>>b;
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    while(n)
    {
        if(n==1)
        {
            if(a.back()=='1'||b.back()=='1')
            {
                cout<<"1"<<endl;
                return;
            }
            else
            {
                cout<<"0"<<endl;
                return;
            }
        }
        else
        {
            if(a.back()=='1'||b.back()=='1')
            {
                a.pop_back(),b.pop_back();
            }
            else
            {
                cout<<"0"<<endl;
                return;
            }
        }
        n--;
    }
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}