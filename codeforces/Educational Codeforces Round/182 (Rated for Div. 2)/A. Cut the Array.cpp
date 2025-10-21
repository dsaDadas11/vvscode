/*
 * @Author: dsaDadas11
 * @Date: 2025-09-22 19:33:25
 * @LastEditTime: 2025-09-22 19:33:34
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
int a[47];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];

    int l=0,r=0;
    for(int i=1;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int s1=0,s2=0,s3=0;
            for(int x=1;x<=i;x++) s1+=a[x];
            for(int x=i+1;x<=j;x++) s2+=a[x];
            for(int x=j+1;x<=n;x++) s3+=a[x];

            s1%=3,s2%=3,s3%=3;
            if((s1!=s2&&s1!=s3&&s2!=s3)||(s1==s2&&s1==s3)) l=i,r=j;
        }
    }

    cout<<l<<' '<<r<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}