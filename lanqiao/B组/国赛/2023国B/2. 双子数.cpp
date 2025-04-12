/*
 * @Author: HuangCe
 * @Date: 2025-02-18 15:43:12
 * @LastEditTime: 2025-02-18 15:43:54
 * @Description: go for it!
 */
/*
 需要开 int128
*/
#include <iostream>
using namespace std;
int main()
{
  // 请在此输入您的代码
  cout<<"947293"<<endl;
  return 0;
}

/*
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int __int128
using namespace std;
constexpr int N=1e7+7;
constexpr int M=2e3+7;
int a[N],p[N];
int cnt;
void init()
{
    a[1]=1;
    for(int i=2;i<N;i++)
    {
        if(!a[i]) p[++cnt]=i;
        for(int j=1;j<=cnt&&p[j]*i<N;j++)
        {
            a[p[j]*i]=p[j];//数组a存该数的最小质因子
            if(!i%p[j]) break;
        }
    }
}
// [2333,23333333333333] 
int l=2333;
int r=23333333333333;

void solve()
{
    ll ans=0;
    for(int i=1;i<=cnt;i++)
    {
        int tt=p[i]*p[i];
        for(int j=i+1;j<=cnt;j++)
        {
            int tmp=tt*p[j]*p[j];
            if(tmp>r) break;
            if(tmp>=l) ans++;
        }
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}
*/