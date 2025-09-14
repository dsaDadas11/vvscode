/*
 * @Author: dsaDadas11
 * @Date: 2025-09-10 20:27:14
 * @LastEditTime: 2025-09-10 20:27:26
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
#define lk cout<<"look"<<endl;
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
string s;
int x,y,z;
int ab,ac,bc,tab,tac,tbc;
bool check(int x,int y,int z)
{
    if(x+y-z<0) return 1;
    if((x+y-z)&1) return 1;
    return 0;
}
bool vis[N];
void solve()
{
    cin>>n; n<<=1;
    cin>>s; s=' '+s;

    for(int i=1;i<=n;i++)
    {
        if(s[i]=='A') x++;
        else if(s[i]=='B') y++;
        else z++;
    }
    if(check(x,y,z)||check(x,z,y)||check(y,z,x))
    {
        cout<<"NO"<<endl;
        return;
    }

    tab=ab=(x+y-z)/2;
    tac=ac=(x+z-y)/2;
    tbc=bc=(y+z-x)/2;

    // cout<<ab<<' '<<ac<<' '<<bc<<endl;

    vector<pair<int,int> > ans;

    // 先找 BC，尽量靠左
    stack<int> stk;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(bc<=0) break;
        if(s[i]=='C')
        {
            if(stk.empty()) continue;
            bc--;
            ans.push_back({stk.top(),i});
            vis[i]=vis[stk.top()]=1;
            stk.pop();
        }
        else if(s[i]=='B'&&cnt<tbc) stk.push(i),cnt++;
    }
    if(bc>0)
    {
        cout<<"NO"<<endl;
        return;
    }

    // 再找 AB，尽量靠右
    while(!stk.empty()) stk.pop();
    for(int i=1;i<=n;i++)
    {
        if(ab<=0) break;
        if(vis[i]) continue;
        if(s[i]=='B')
        {
            if(stk.empty()) continue;
            ab--;
            ans.push_back({stk.top(),i});
            vis[i]=vis[stk.top()]=1;
            stk.pop();
        }
        else if(s[i]=='A') stk.push(i);
    }
    if(ab>0)
    {
        cout<<"NO"<<endl;
        return;
    }

    // 再找 AC
    while(!stk.empty()) stk.pop();
    cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(ac<=0) break;
        if(vis[i]) continue;

        if(s[i]=='C')
        {
            if(stk.empty()) continue;
            ac--;
            ans.push_back({stk.top(),i});
            vis[i]=vis[stk.top()]=1;
            stk.pop();
        }
        else if(s[i]=='A'&&cnt<tac) stk.push(i),cnt++;
    }
    if(ac>0)
    {
        cout<<"NO"<<endl;
        return;
    }

    cout<<"YES"<<endl;
    for(auto [x,y]:ans)
    {
        cout<<x<<' '<<y<<endl;
    }

}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}