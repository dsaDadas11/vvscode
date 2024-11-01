/*
 * @Author: dsaDadas11
 * @Date: 2024-10-03 21:59:08
 * @LastEditTime: 2024-10-03 22:06:50
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
    cin>>n>>s;
    int pos=-1;
    // 数字在字母前
    for(int i=0;i<n;i++)
    {
        if(s[i]>='a'&&s[i]<='z')
        {
            if(pos==-1) pos=i;
            for(int j=i+1;j<n;j++)
            {
                if(s[j]>='0'&&s[j]<='9')
                {
                    cout<<"NO"<<endl;
                    return;
                }
            }
        }
    }
    // 字母字典序
    for(int i=pos;i<n-1;i++)
    {
        if(s[i]>s[i+1])
        {
            cout<<"NO"<<endl;
            return;
        }
    }
    // 数字字典序
    for(int i=0;i<pos-1;i++)
    {
        if(s[i]>s[i+1])
        {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}