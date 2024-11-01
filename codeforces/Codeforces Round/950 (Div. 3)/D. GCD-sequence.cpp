/*
 * @Author: dsaDadas11
 * @Date: 2024-10-08 22:37:42
 * @LastEditTime: 2024-10-08 22:40:56
 * @Description: go for it!
 */
/*
 解题思路：
 一开始想暴力枚举将[2,n-1]的点删掉，然后找是否有序，后面想想因为只能删一个点，
 那么贪心的想只能删最前面的那个使gcd数组不有序的点 (如果跳过这个往后删的话，前面gcd一定不是有序的)，
 然后这个点的左右两个点也会影响这两个gcd，
 因此把这三个点删掉再判断是否有序即可
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=2e5+7;
constexpr int M=2e3+7;
int n;
void solve()
{
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> b(a.begin(),a.end());
    vector<int> c(a.begin(),a.end());
    int pos=-1;
    for(int i=1;i<n-1;i++)
    {
        if(__gcd(a[i],a[i-1])>__gcd(a[i],a[i+1]))
        {
            pos=i;
            break;
        }
    }
    if(pos==-1) return cout<<"YES"<<endl,void();
    a.erase(a.begin()+pos);
    bool flag1=0;
    for(int i=1;i<n-2;i++)
    {
        if(__gcd(a[i],a[i-1])>__gcd(a[i],a[i+1]))
        {
            flag1=1;
        }
    }
    if(!flag1) return cout<<"YES"<<endl,void();
    bool flag2=0;
    b.erase(b.begin()+pos+1);
    for(int i=1;i<n-2;i++)
    {
        if(__gcd(b[i],b[i-1])>__gcd(b[i],b[i+1]))
        {
            flag2=1;
        }
    }
    if(!flag2) return cout<<"YES"<<endl,void();
    c.erase(c.begin()+pos-1);
    for(int i=1;i<n-2;i++)
    {
        if(__gcd(c[i],c[i-1])>__gcd(c[i],c[i+1]))
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