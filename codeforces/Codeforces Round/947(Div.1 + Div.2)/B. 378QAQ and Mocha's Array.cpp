/*
 * @Author: dsaDadas11
 * @Date: 2024-09-28 11:34:35
 * @LastEditTime: 2024-09-28 12:21:19
 * @Description: go for it!
 */
/*
 先排序找最小的那个数，然后遍历找出它不能整除的数，把这些数进行排序，
 找最小的那个数，如果遍历找到了它不能整除的数，那么就是NO,否则是YES
 不然其他大数不可能整除比它小的数
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
    sort(a+1,a+1+n);
    vector<int> v;
    for(int i=2;i<=n;i++)
    {
        if(a[i]%a[1]!=0)
        {
            v.push_back(a[i]);
        }
    }
    sort(v.begin(),v.end());
    for(int i=1;i<v.size();i++)
    {
        if(v[i]%v[0]!=0)
        {
            cout<<"NO"<<endl;
            return;
        }
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