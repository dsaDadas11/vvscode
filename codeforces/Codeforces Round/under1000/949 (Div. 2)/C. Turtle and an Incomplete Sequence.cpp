/*
 * @Author: dsaDadas11
 * @Date: 2024-10-06 22:59:08
 * @LastEditTime: 2024-10-06 23:00:46
 * @Description: go for it!
 */
/*
 解题思路：
 用双指针两边往中间模拟即可 (一开始拆成二进制写了个屎山还不对)，
 如果除到等于1了，下一位就变成2，否则一直除2，
 双指针模拟完再判断一下就好
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=2e5+7;
constexpr int M=2e3+7;
int n;
int a[N];
void solve()
{
    cin>>n;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==-1) cnt++;
    }
    if(cnt==n)
    {
        for(int i=1;i<=n;i++)
        {
            cout<<(i%2)+1<<' ';
        }
        return cout<<endl,void();
    }
    vector<int> pos;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>0) pos.push_back(i);
    }
    for(int i=0;i<(int)pos.size()-1;i++)
    {
        int l=pos[i],r=pos[i+1];
        while(l+1<r)
        {
            if(a[l]>a[r])
            {
                if(a[l]==1) a[l+1]=2;
                else a[l+1]=a[l]/2;
                l++;
            }
            else
            {
                if(a[r]==1) a[r-1]=2;
                else a[r-1]=a[r]/2;
                r--;
            }
        }
        if (a[l]!=a[r]/2&&a[r]!=a[l]/2) return cout<<"-1"<<endl,void();
    }
    //处理左端
    int p=pos.front();
    cnt=1;
    for(int i=p-1;i>=1;i--)
    {
        if(cnt&1) a[i]=a[i+1]*2;
        else a[i]=a[i+1]/2;
        cnt++;
    }
    // 处理右端
    p=pos.back();
    cnt=1;
    for(int i=p+1;i<=n;i++)
    {
        if(cnt&1) a[i]=a[i-1]*2;
        else a[i]=a[i-1]/2;
        cnt++;
    }
    for(int i=1;i<=n;i++) cout<<a[i]<<' ';
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}