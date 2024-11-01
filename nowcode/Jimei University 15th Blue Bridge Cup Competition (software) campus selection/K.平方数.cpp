/*
 * @Author: dsaDadas11
 * @Date: 2024-01-20 20:32:53
 * @LastEditTime: 2024-01-20 20:32:58
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
const int N=1e6+7;
const int M=2e3+7;
int n,cnt,p[M];
bool a[M];
set<int> se;
void pre()
{
    memset(a,1,sizeof a);
    a[1]=0;
    for(int i=1;i<1010;i++)
    {
        if(a[i]) p[++cnt]=i;
        for(int j=1;j<=cnt&&(ll)p[j]*i<1010;j++)
        {
            a[p[j]*i]=0;
            if(!i%p[j]) break;
        }
    }
}
int getodd(int x)
{
    int ans=1;
    for(int i=1;i<=cnt&&p[i]*p[i]<=x;i++)
    {
        int t=0;
        while(x%p[i]==0) x/=p[i],t++;
        if(t&1) ans*=p[i];
    }
    int s=sqrt(x);
    if(s*s!=x) ans*=x;
    return ans;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	pre();
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x; cin>>x;
        se.insert(getodd(x));
    }
    cout<<se.size()<<endl;
	return 0;
}