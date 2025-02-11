/*
 * @Author: dsaDadas11
 * @Date: 2025-01-14 21:41:45
 * @LastEditTime: 2025-01-15 11:44:05
 * @Description: go for it!
 */
/*
 解题思路：
 我们贪心的找每个字符在 s 中最靠右的位置，将子序列往后挤即可
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
string s,l,r;
int m;
void solve()
{
    cin>>s;
    int len=s.size();
    s=' '+s;
    cin>>m;
    cin>>l>>r;
    l=' '+l,r=' '+r;
    int mpos=1;
    for(int i=1;i<=m;i++)
    {
        int tmp=1;
        for(int j=l[i]-'0';j<=r[i]-'0';j++)
        {
            bool ok=0;
            for(int k=mpos;k<=len;k++)
            {
                if(s[k]-'0'==j)
                {
                    tmp=max(tmp,k);
                    ok=1;
                    break;
                }
            }
            if(!ok) return cout<<"YES"<<endl,void();
        }
        mpos=max(mpos,tmp+1);
    }
    cout<<"NO"<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}