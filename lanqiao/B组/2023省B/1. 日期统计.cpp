/*
 * @Author: HuangCe
 * @Date: 2025-02-14 19:24:07
 * @LastEditTime: 2025-02-14 19:24:36
 * @Description: go for it!
 */
#include <iostream>
using namespace std;
int main()
{
  cout<<"235"<<endl;
  return 0;
}

/*
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
int a[107];
int cnt[17];
int month[17]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int ans;
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=12;i++)
    {
        int m1=0,m2=0;
        int t=i;
        m2=t%10;
        t/=10;
        m1=t%10;
        for(int j=1;j<=month[i];j++)
        {
            int d1=0,d2=0;
            int tmp=j;
            d2=tmp%10;
            tmp/=10;
            d1=tmp%10;
            vector<int> check;
            check.push_back(2);
            check.push_back(0);
            check.push_back(2);
            check.push_back(3);
            check.push_back(m1);
            check.push_back(m2);
            check.push_back(d1);
            check.push_back(d2);
            int p=0;
            for(int k=1;k<=100;k++)
            {
                if(a[k]==check[p])
                {
                    p++;
                }
                if(p==8)
                {
                    ans++;
                    break;
                }
            }
        }
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}
*/