/*
 * @Author: dsaDadas11
 * @Date: 2025-01-22 21:38:36
 * @LastEditTime: 2025-01-22 21:38:48
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,l,r;
int a[N];
void solve()
{
    cin>>n>>l>>r;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    vector<int> v1,v2,v3;
    for(int i=1;i<l;i++) v1.push_back(a[i]);
    for(int i=l;i<=r;i++) v2.push_back(a[i]);
    for(int i=r+1;i<=n;i++) v3.push_back(a[i]);

    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end(),greater<>());
    sort(v3.begin(),v3.end());
    
    int ans1=0,ans2=0;
    int len1=min((int)v1.size(),(int)v2.size());
    int sum1=0,sum2=0;
    for(int i=0;i<len1;i++)
    {
        if(v1[i]>=v2[i]) break;
        sum1+=v1[i];
        sum2+=v2[i];
    }
    ans1=sum2-sum1;

    int len2=min((int)v2.size(),(int)v3.size());
    sum2=0;
    int sum3=0;
    for(int i=0;i<len2;i++)
    {
        if(v3[i]>=v2[i]) break;
        sum3+=v3[i];
        sum2+=v2[i];
    }

    ans2=sum2-sum3;

    int ans=max(ans1,ans2);

    int sum=0;
    for(int i=l;i<=r;i++)
    {
        sum+=a[i];
    }
    cout<<sum-ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}