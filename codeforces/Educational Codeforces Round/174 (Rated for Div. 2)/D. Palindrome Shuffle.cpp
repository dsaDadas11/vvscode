/*
 * @Author: dsaDadas11
 * @Date: 2025-03-11 12:24:14
 * @LastEditTime: 2025-03-11 12:26:50
 * @Description: go for it!
 */
/*
 2e5不卡 nlogn方捏
 解题思路：
 1.没超过中心点，直接看左右两边字符的种类和数量是否相等，并且中间那一部分是否能构成回文
 2.超过中心点那就得看中间那一部分能否分到平均的字符，并且左右两边的字符数量能否匹配
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=2e5+7;
constexpr int M=2e3+7;
int n;
string s;
bool pmid(int l,int r)
{
    int xr=n+1-l,xl=n+1-r;
    map<char,int> mp1,mp2;
    for(int i=r+1;i<xl;i++)
    {
        if(s[i]!=s[n+1-i]) return 1;
    }
    
    for(int i=l;i<=r;i++) mp1[s[i]]++;
    for(int i=xl;i<=xr;i++) mp2[s[i]]++;
    if(mp1==mp2) return 0;
    else return 1;
}
bool smid(int l,int r)
{
    int xr=n+1-l,xl=r+1;
    map<char,int > mp;
    for(int i=l;i<=r;i++) mp[s[i]]++;
    for(int i=xl;i<=xr;i++) mp[s[i]]--;
    int sum=r-n/2;
    for(auto [x,y]:mp)
    {
        if(y<0) return 1;
        if(y%2) return 1;
        sum-=y/2;
        if(sum<0) return 1;
    }
    return 0;
}
bool check(int l,int r)
{
    if(r<=n/2) return pmid(l,r);
    return smid(l,r);
}
void solve()
{
    cin>>s;
    string t="";
    int x=0,y=s.size()-1;
    while(s[x]==s[y]&&x<y) x++,y--;
    if(x>y) return cout<<"0"<<endl,void();
    for(int i=x;i<=y;i++) t.push_back(s[i]);
    s=t;
    n=s.size();
    s=' '+s;
    
    int l=1,r=n;
    while(l<r)
    {
        int mid=(l+r)>>1;
        if(check(1,mid)) l=mid+1;
        else r=mid;
    }
    int ans=l;

    reverse(t.begin(),t.end());
    s=t;
    s=' '+s;

    l=1,r=n;
    while(l<r)
    {
        int mid=(l+r)>>1;
        if(check(1,mid)) l=mid+1;
        else r=mid;
    }

    cout<<min(ans,l)<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}