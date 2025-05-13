/*
 * @Author: dsaDadas11
 * @Date: 2025-04-15 19:31:33
 * @LastEditTime: 2025-04-15 19:31:42
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
string s;
void solve()
{
    getline(cin,s);
    string ans="";
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='6')
        {
            int cnt=0;
            int j;
            bool ok=0;
            for(j=i;j<s.size();j++)
            {
                if(s[j]=='6') cnt++;
                else
                {
                    j--;
                    break;
                }
            }
            if(cnt>3&&cnt<=9) ans.push_back('9'),ok=1;
            else if(cnt>9) ans+="27",ok=1;
            if(ok) i=j;
            else ans.push_back(s[i]);
        }
        else ans.push_back(s[i]);
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