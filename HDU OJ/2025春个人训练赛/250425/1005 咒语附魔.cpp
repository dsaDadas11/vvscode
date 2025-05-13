/*
 * @Author: dsaDadas11
 * @Date: 2025-04-26 16:02:05
 * @LastEditTime: 2025-04-26 16:03:10
 * @Description: go for it!
 */
/*
 解题思路：
 n^2情况下每往下走一步的概率都是 1/2
 因此 O(n^2)时间复杂度变为 O(nlogn)
 可以直接遍历找最大前缀 1数量
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m;
string a,b;
int pre[N]; // 前缀长度
void solve()
{
    cin>>n>>m;
    cin>>a>>b;
    a=' '+a,b=' '+b;
    int mx=0;
    for(int i=1;i<=m;i++)
    {
        pre[i]=0;
        for(int j=i;j+n-1<=m;j++)
        {
            if(a[j-i+1]!=b[j]) pre[i]++;
            else break;
        }
        mx=max(mx,pre[i]);
    }

    vector<int> v;
    for(int i=1;i<=m-n+1;i++)
    {
        if(pre[i]==mx) v.push_back(i);
    }
    vector<string> s;
    for(auto pos:v)
    {
        string tmp="";
        for(int i=pos;i<=pos+n-1;i++)
        {
            if(a[i-pos+1]!=b[i]) tmp.push_back('1');
            else tmp.push_back('0');
        }
        s.push_back(tmp);
    }
    sort(s.begin(),s.end());
    string t=' '+s.back();

    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(t[i]=='1') ans++;
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}