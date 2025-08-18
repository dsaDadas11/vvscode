/*
 * @Author: dsaDadas11
 * @Date: 2025-07-21 19:08:21
 * @LastEditTime: 2025-07-21 19:20:12
 * @Description: go for it!
 */
/*
 解题思路：
 首先我们单独看 0或者 1，只有两个相邻的 0才能消去，换句话说同在奇数位或偶数位的 0是不能消去的，
 因此只有消去 奇数位和偶数位才能消去，如果此奇数位和偶数位不相邻时，中间必定有偶数个 1，然后可以消去，并且将此两个0消去，
 因此消去的贡献就是 cnt0=abs(cnt0奇-cnt0偶)，1也同理
 当加上 2后就是将 2变为 0或者 1
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
    cin>>s;
    int cnt2=0;
    int cnt[2][2]={0};
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='2') cnt2++;
        else cnt[i&1][s[i]-'0']++;
    }
    int cnt0=abs(cnt[0][0]-cnt[1][0]);
    int cnt1=abs(cnt[0][1]-cnt[1][1]);

    int tmp=min(cnt0,cnt2);
    cnt0-=tmp,cnt2-=tmp;

    tmp=min(cnt1,cnt2);
    cnt1-=tmp,cnt2-=tmp;

    cnt2%=2;

    cout<<cnt0+cnt1+cnt2<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}