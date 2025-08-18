/*
 * @Author: dsaDadas11
 * @Date: 2025-07-28 19:22:29
 * @LastEditTime: 2025-07-28 19:22:38
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
string s1,s2,s3;
int fa[N];
int find_fa(int x)
{
    if(x==fa[x]) return x;
    return find_fa(fa[x]);
}
void merge_set(int x,int y)
{
    int fax=find_fa(x);
    int fay=find_fa(y);
    fa[fax]=fay;
}
void solve()
{
    cin>>s1>>s2>>s3;
    if(s1.size()!=s2.size()) return cout<<"NO"<<endl,void();
    if(s1.size()!=s3.size()) return cout<<"YES"<<endl,void();
    
    int len=s1.size();
    for(int i=0;i<=26;i++) fa[i]=i;
    for(int i=0;i<len;i++)
    {
        merge_set(s1[i]-'a'+1,s2[i]-'a'+1);
    }
    for(int i=0;i<len;i++)
    {
        if(find_fa(s1[i]-'a'+1)!=find_fa(s3[i]-'a'+1)) return cout<<"YES"<<endl,void();
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