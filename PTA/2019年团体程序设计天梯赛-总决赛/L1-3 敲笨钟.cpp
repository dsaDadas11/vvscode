/*
 * @Author: dsaDadas11
 * @Date: 2025-04-15 19:46:01
 * @LastEditTime: 2025-04-15 19:46:10
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
string s[27];
void solve()
{
    cin>>n;
    cin.ignore();
    for(int i=1;i<=n;i++)
    {
        getline(cin,s[i]);
    }

    for(int i=1;i<=n;i++)
    {
        int pos=0;
        for(int j=0;j<s[i].size();j++)
        {
            if(s[i][j]==',')
            {
                pos=j;
                break;
            }
        }
        string tar="ong";
        int cnt=0;
        int tt=0;
        for(int j=pos-3;j<pos;j++)
        {
            if(j<0) break;
            if(s[i][j]==tar[tt++]) cnt++;
        }
        if(cnt<3)
        {
            cout<<"Skipped"<<endl;
            continue;
        }
        cnt=0;
        tt=0;
        for(int j=s[i].size()-3;j<s[i].size();j++)
        {
            if(j<0) break;
            if(s[i][j]==tar[tt++]) cnt++;
        }
        if(cnt<3)
        {
            cout<<"Skipped"<<endl;
            continue;
        }
        cnt=0;
        while(cnt!=3)
        {
            if(s[i].back()==' ') cnt++;
            s[i].pop_back();
        }
        cout<<s[i];
        cout<<" qiao ben zhong."<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}