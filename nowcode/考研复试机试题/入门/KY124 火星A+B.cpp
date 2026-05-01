/*
 * @Author: dsaDadas11
 * @Date: 2026-01-21 15:06:31
 * @LastEditTime: 2026-01-21 15:06:38
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
vector<int> p;
void init()
{
    for(int i=2;i<N;i++)
    {
        bool flag=0;
        for(int j=2;j*j<=i;j++)
        {
            if(i%j==0)
            {
                flag=1;
                break;
            }
        }
        if(!flag) p.push_back(i);
        if(p.size()>25) break;
    }
}
int read()
{
    string s;
    cin>>s;
    vector<int> v;
    for(int i=0;i<s.size();i++)
    {
        string tmp="";
        for(int j=i;j<s.size();j++)
        {
            if(s[j]==',')
            {
                i=j;
                break;
            }
            tmp+=s[j];
        }
        v.push_back(stoi(tmp));
    }

    int ans=0;
    int f=1;
    reverse(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
    {
        ans+=f*v[i];
        f*=p[i];
    }
    return ans;
}
void write(int n)
{
    vector<int> v;
    int cnt=0;
    while(n)
    {
        v.push_back(n%p[cnt]);
        n/=p[cnt];
        cnt++;
    }
    for(int i=v.size()-1;i>=0;i--)
    {
        cout<<v[i]<<",\n"[i==0];
    }
}
void solve()
{
    int a=read()+read();
    write(a);
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}