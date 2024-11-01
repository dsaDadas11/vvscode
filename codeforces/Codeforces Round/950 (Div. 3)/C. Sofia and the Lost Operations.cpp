/*
 * @Author: dsaDadas11
 * @Date: 2024-10-08 22:01:19
 * @LastEditTime: 2024-10-08 22:02:33
 * @Description: go for it!
 */
/*
 解题思路：
 这道题就是看a,b不相等的数有没有出现再d中，
 并且d的最后一个元素一定要在b中，不然修改不合法
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=2e5+7;
constexpr int M=2e3+7;
int n,m;
int a[N],b[N],d[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    cin>>m;
    map<int,int> mp;
    for(int i=1;i<=m;i++) cin>>d[i],mp[d[i]]++;
    bool flag=0;
    for(int i=1;i<=n;i++)
    {
        if(b[i]==d[m]) flag=1;
    }
    if(!flag)
    {
        cout<<"NO"<<endl;
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=b[i])
        {
            if(mp[b[i]]==0)
            {
                cout<<"NO"<<endl;
                return;
            }
            mp[b[i]]--;

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