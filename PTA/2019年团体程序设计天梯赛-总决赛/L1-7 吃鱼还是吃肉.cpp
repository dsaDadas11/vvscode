/*
 * @Author: dsaDadas11
 * @Date: 2025-04-15 20:03:33
 * @LastEditTime: 2025-04-15 20:03:41
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
int sex,h,m;
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>sex>>h>>m;
        string ans="";
        if(sex==1)
        {
            if(h<130) ans+="duo chi yu! ";
            if(h>130) ans+="ni li hai! ";
            if(h==130) ans+="wan mei! ";
            if(m<27) ans+="duo chi rou! ";
            if(m>27) ans+="shao chi rou! ";
            if(m==27) ans+="wan mei! ";
        }
        else
        {
            if(h<129) ans+="duo chi yu! ";
            if(h>129) ans+="ni li hai! ";
            if(h==129) ans+="wan mei! ";
            if(m<25) ans+="duo chi rou! ";
            if(m>25) ans+="shao chi rou! ";
            if(m==25) ans+="wan mei! ";
        }
        ans.pop_back();
        cout<<ans<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}