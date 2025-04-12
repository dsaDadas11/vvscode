/*
 * @Author: dsaDadas11
 * @Date: 2025-04-12 19:43:46
 * @LastEditTime: 2025-04-12 19:48:19
 * @Description: go for it!
 */
/*
 解题思路：
 看到苯环哥的做法豁然开朗了，原来不用维护块的左右最值(写似了这码量)
 首先将列(. #) 看成状态 1
 将列(# .) 看成状态 2，将列(# #)看成状态 3
 对于 (. .)状态直接跳过，然后后续用区间的间隔将(. .)补成 #
 接下来就看哪一状态到哪一状态的变化是否需要多补 #即可
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
string a,b;
void solve()
{
    cin>>a>>b;
    int ans=0;
    int lst=-1,sta=-1;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]=='.'&&b[i]=='.') continue;
        if(lst!=-1) ans+=i-lst-1;
        lst=i;
        if(a[i]=='.'&&b[i]=='#')
        {
            if(sta==2)
            {
                ans++;
                sta=3;
            }
            else
            {
                sta=1;
            }
        }
        else if(a[i]=='#'&&b[i]=='.')
        {
            if(sta==1)
            {
                ans++;
                sta=3;
            }
            else
            {
                sta=2;
            }
        }
        else if(a[i]=='#'&&b[i]=='#')
        {
            sta=3;
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