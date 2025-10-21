/*
 * @Author: dsaDadas11
 * @Date: 2025-09-16 21:33:03
 * @LastEditTime: 2025-09-16 21:34:35
 * @Description: go for it!
 */
/*
 鸽巢原理，首先判断前缀和是否满足为 n的倍数，如果不满足就取模，它们会落在区间 [1,n-1]中，
 因为有 n个数，所以一定会有两个数落在同一个位置，找这两个位置即可
 没有无解的情况
*/
#include<iostream>
#include<map>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
const int N=1e4+7;
const int M=2e3+7;
int n;
int s[N],a[N];
int mp[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    for(int i=1;i<=n;i++)
    {
        if(s[i]%n==0)
        {
            cout<<i<<endl;
            for(int j=1;j<=i;j++)
            {
                cout<<a[j]<<endl;
            }
            return;
        }
    }

    for(int i=1;i<=n;i++)
    {
        s[i]%=n;
    }

    
    for(int i=n;i>=1;i--)
    {
        if(mp[s[i]])
        {
            int pos=mp[i];
            cout<<pos-i<<endl;
            for(int j=i+1;j<=pos;j++)
            {
                cout<<a[j]<<endl;
            }
            return;
        }
        mp[s[i]]=i;
    }
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}