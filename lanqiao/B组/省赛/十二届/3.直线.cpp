/*
 * @Author: dsaDadas11
 * @Date: 2025-04-10 16:24:26
 * @LastEditTime: 2025-04-10 16:25:21
 * @Description: go for it!
 */
/*
 解题思路：
 这道题有个坑点，不能用斜率算截距，就算是 long double也有误差
 用两个点算截距
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
vector<pair<int,int> > p;
void solve()
{
    for(int i=0;i<20;i++)
    {
        for(int j=0;j<21;j++)
        {
            p.push_back({i,j});
        }
    }
    set<int> x,y;
    set<pair<long double,long double> > com;
    for(int i=0;i<20;i++)
    {
        for(int j=0;j<21;j++)
        {
            for(int k=0;k<20;k++)
            {
                for(int g=0;g<21;g++)
                {
                    if(k==i&&g==j) continue;
                    int dx=k-i,dy=g-j;
                    if(dx==0) x.insert(i);
                    else if(dy==0) y.insert(j);
                    else
                    {
                        long double xie=(long double)dy/dx;
                        long double b=((long double)k*j-i*g)/(k-i);
                        com.insert({xie,b});
                    }
                }
            }
        }
    }
    cout<<x.size()+y.size()+com.size()<<endl;
    

}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}