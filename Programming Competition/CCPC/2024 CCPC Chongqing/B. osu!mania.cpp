/*
 * @Author: dsaDadas11
 * @Date: 2025-01-12 12:51:41
 * @LastEditTime: 2025-01-13 15:29:48
 * @Description: go for it!
 */
/*
 用 round 函数进行四舍五入
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int ppm;
int a,b,c,d,e,f;
void solve()
{
    cin>>ppm;
    cin>>a>>b>>c>>d>>e>>f;
    long double acc=(300.0*a+300.0*b+200.0*c+100.0*d+50.0*e)/(300.0*(a+b+c+d+e+f));
    long double tmp=(320.0*a+300.0*b+200.0*c+100.0*d+50.0*e-32.0*8*(a+b+c+d+e+f))/(320.0*(a+b+c+d+e+f));
    int pp=max(0LL,(int)round(tmp*5*ppm));
    cout<<fixed<<setprecision(2)<<round(acc*10000)/100<<"% "<<pp<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}


/*
 屎山代码
 高精度没学好只能暴力模拟了，代码写的烂爆了
 当 res = 0 时需要特判，
 不对
 这段代码应该是水过去了。。。

#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int ppm;
int a,b,c,d,e,f;
void solve()
{
    cin>>ppm;
    cin>>a>>b>>c>>d>>e>>f;
    int s1=1000*(300*a+300*b+200*c+100*d+50*e);
    int s2=3*(a+b+c+d+e+f);
    int res=0;
    for(int i=1;i<=4;i++)
    {
        int tmp=s1/s2;
        res+=tmp;
        s1-=s2*tmp;
    }
    if(res%10>=5) res+=10;
    string s=to_string(res);
    if(res==0)
    {
        s.push_back('0');
        s.push_back('0');
        s.push_back('0');
    }
    for(int i=0;i<s.size()-1;i++)
    {
        cout<<s[i];
        if(s.size()-i==4) cout<<".";
    }
    cout<<"% ";
    
    int s3=320*a+300*b+200*c+100*d+50*e;
    int s4=32*(a+b+c+d+e+f);
    if(s3>8*s4)
    {
        s3-=8*s4;
        s3*=5*ppm;
        s4*=10;
        int tmp=s3/s4;
        int ans=tmp;
        tmp=s3-tmp*s4;
        tmp*=10;
        if(tmp>=5*s4)
        {
            ans++;
        }
        cout<<ans<<endl;
    }
    else
    {
        cout<<"0"<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}
*/