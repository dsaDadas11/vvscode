/*
 * @Author: dsaDadas11
 * @Date: 2025-06-07 11:25:08
 * @LastEditTime: 2025-06-07 11:36:25
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=5e2+7;
bool checkq(int x)
{
    int q=sqrt(x);
    if(x!=q*q) return 0;
    return 1;
}
void solve()
{
    int anss=1e16,ansa=0,ansb=0,ansc=0;
    for(int d1=1;d1<M;d1++)
    {
        for(int d2=1;d2<M;d2++)
        {
            for(int d3=1;d3<M;d3++)
            {
                int x1=517*d1;
                int x2=1316*d2;
                int x3=154*d3;

                if((x1*x3)%x2) continue;
                if((x1*x2)%x3) continue;
                if((x2*x3)%x1) continue;

                int a=x1*x3/x2;
                int b=x1*x2/x3;
                int c=x2*x3/x1;
                if(checkq(a)==0) continue;
                if(checkq(b)==0) continue;
                if(checkq(c)==0) continue;
                a=sqrt(a),b=sqrt(b),c=sqrt(c);

                int tmp=lcm(2*d1,lcm(5*d2,d3))*2091;
                int sum=sqrt(tmp);
                if(sum*(sum+1)!=tmp) continue;
                sum++;
                if(sum!=a+b+c) continue;

                if(sum<anss)
                {
                    anss=sum;
                    ansa=a,ansb=b,ansc=c;
                }

            }
        }
    }
    cout<<ansa<<' '<<ansb<<' '<<ansc<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}

/*
更简便的做法，只要通分后看分子求即可
void solve()
{
    int s1=517*5,s2=2632,s3=308*5;
    int g=gcd(s1*s3,gcd(s1*s2,s2*s3));
    cout<<s1*s3/g<<' '<<s1*s2/g<<' '<<s2*s3/g;
}
*/