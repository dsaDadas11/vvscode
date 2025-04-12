/*
 * @Author: dsaDadas11
 * @Date: 2025-03-31 17:12:00
 * @LastEditTime: 2025-03-31 17:15:03
 * @Description: go for it!
 */
/*
 解题思路：
 先 cout再 flush才能强制清空缓冲区

 首先数据范围是 1500，但是只能查询 75次，因此能得到的有用信息为 300个，
 所以考虑逐渐缩小三角形的范围，将返回值作为一条边缩小
 这样做能做到 logn/log3
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,p;
int ask(int x,int y,int z)
{
    cout<<"? "<<x<<' '<<y<<' '<<z<<endl;
    cout<<flush;
    cin>>p;
    return p;
}
void print(int x,int y,int z)
{
    cout<<"! "<<x<<' '<<y<<' '<<z<<endl;
    cout<<flush;
}
int num[5];
void solve()
{
    cin>>n;
    num[1]=1,num[2]=2,num[3]=3;
    while(1)
    {
        int res=ask(num[1],num[2],num[3]);
        if(res==0)
        {
            print(num[1],num[2],num[3]);
            break;
        }
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distrib(1, 3);
        int x=distrib(gen);
        num[x]=res;
    }
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}