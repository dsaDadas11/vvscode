/*
 * @Author: dsaDadas11
 * @Date: 2025-11-01 16:34:28
 * @LastEditTime: 2025-11-01 16:34:36
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
string s;
void solve()
{
    cin>>n;
    cin>>s;
    s=' '+s;
    vector<int> a(n+1);
    vector<int> pos;
    pos.push_back(0);
    vector<int> q;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='1') a[i]=i,pos.push_back(i);
        else q.push_back(i);
    }

    pos.push_back(n+1);

    for(int i=0;i<pos.size()-1;i++)
    {
        int l=pos[i]+1,r=pos[i+1]-1;
        if(r-l+1==1)
        {
            cout<<"NO"<<endl;
            return;
        }
        for(int j=l;j<=r;j++)
        {
            q.push_back(j);
        }

        for(int j=l;j<=r;j++)
        {
            a[j]=q.back();
            q.pop_back();
        }
    }

    cout<<"YES"<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<a[i]<<' ';
    }
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}