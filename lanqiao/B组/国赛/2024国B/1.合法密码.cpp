/*
 * @Author: dsaDadas11
 * @Date: 2025-06-07 10:59:46
 * @LastEditTime: 2025-06-07 11:00:23
 * @Description: go for it!
 */
/*
 符号字符不包含数字和字母
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
string s="kfdhtshmrw4nxg#f44ehlbn33ccto#mwfn2waebry#3qd1ubwyhcyuavuajb#vyecsycuzsmwp31ipzah#catatja3kaqbcss2th";
map<string,int> mp;
void solve()
{
    cin>>s;
    int n=s.size();
    s=' '+s;
    for(int i=1;i<=n;i++)
    {
        if(i+8-1>n) break;
        // 先处理 7
        string t="";
        bool num=0,sym=0;
        for(int j=i;j<=i+6;j++)
        {
            t.push_back(s[j]);
            if(s[j]>='0'&&s[j]<='9') num=1;
            else if(s[j]<'a'||s[j]>'z') sym=1;
        }
        for(int len=8;len<=16;len++)
        {
            if(i+len-1>n) break;
            t.push_back(s[i+len-1]);
            if(s[i+len-1]>='0'&&s[i+len-1]<='9') num=1;
            else if(s[i+len-1]<'a'||s[i+len-1]>'z') sym=1;
            if(num&&sym) mp[t]++;
        }
    }
    int ans=0;
    for(auto [x,y]:mp)
    {
        ans+=y;
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