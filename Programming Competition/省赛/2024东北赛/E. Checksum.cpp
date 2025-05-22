/*
 * @Author: dsaDadas11
 * @Date: 2025-05-15 18:15:59
 * @LastEditTime: 2025-05-15 18:16:08
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,k;
string a;
void solve()
{
    cin>>n>>k;
    int x=0;
    cin>>a;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]=='1') x++;
    }
    for(int y=0;y<=k;y++)
    {
        int sum=x+y;
        vector<int> v;
        while(sum)
        {
            v.push_back(sum&1);
            sum>>=1;
            if(v.size()==k) break;
        }
        int cnt=0;
        for(auto i:v)
        {
            if(i==1) cnt++;
        }
        if(y==cnt)
        {
            for(int i=1;i<=max(0LL,k-(int)v.size());i++)
            {
                cout<<"0";
            }
            reverse(v.begin(),v.end());
            for(auto i:v) cout<<i;
            cout<<endl;
            return;
        }
    }
    cout<<"None"<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}