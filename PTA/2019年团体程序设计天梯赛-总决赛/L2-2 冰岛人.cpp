/*
 * @Author: dsaDadas11
 * @Date: 2025-04-15 21:10:47
 * @LastEditTime: 2025-04-16 21:48:12
 * @Description: go for it!
 */
/*
 有点难理解题目是在什么环境出的
 344 ms通过
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e5+7;
constexpr int M=2e3+7;
int n,q;
struct People
{
    char sex;
    string father;
};
map<string,People> peo;
bool check(string a,string b)
{
    int i=1,j;
    for(string A=a;A!="";i++,A=peo[A].father)
    {
        j=1;
        for(string B=b;B!="";j++,B=peo[B].father)
        {
            if(i>=5&&j>=5) return 1; // 都大于 5才能返回 1
            if(A==B&&(i<5||j<5)) return 0; // 双方的五代内都不行
        }
    }
    return 1;
}
void solve()
{
    cin>>n;
    string a,b,c;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b;
        if(b.back()=='n') peo[a]={'m',b.substr(0,b.size()-4)};
        else if(b.back()=='r') peo[a]={'f',b.substr(0,b.size()-7)};
        else peo[a]={b.back(),""};
    }

    cin>>q;
    for(int i=1;i<=q;i++)
    {
        cin>>a>>c>>b>>c;
        if(peo.find(a)==peo.end()||peo.find(b)==peo.end()) cout<<"NA"<<endl;
        else if(peo[a].sex==peo[b].sex) cout<<"Whatever"<<endl;
        else cout<<(check(a,b)? "Yes" : "No")<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}

/*
172 ms unordered_map和count优化

#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e5+7;
constexpr int M=2e3+7;
int n,q;
struct People
{
    char sex;
    string father;
};
unordered_map<string,People> peo;
bool check(string a,string b)
{
    int i=1,j;
    for(string A=a;A!="";i++,A=peo[A].father)
    {
        j=1;
        for(string B=b;B!="";j++,B=peo[B].father)
        {
            if(i>=5&&j>=5) return 1; // 都大于 5才能返回 1
            if(A==B&&(i<5||j<5)) return 0; // 双方的五代内都不行
        }
    }
    return 1;
}
void solve()
{
    cin>>n;
    string a,b,c;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b;
        if(b.back()=='n') peo[a]={'m',b.substr(0,b.size()-4)};
        else if(b.back()=='r') peo[a]={'f',b.substr(0,b.size()-7)};
        else peo[a]={b.back(),""};
    }

    cin>>q;
    for(int i=1;i<=q;i++)
    {
        cin>>a>>c>>b>>c;
        if(!peo.count(a)||!peo.count(b)) cout<<"NA"<<endl;
        else if(peo[a].sex==peo[b].sex) cout<<"Whatever"<<endl;
        else cout<<(check(a,b)? "Yes" : "No")<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}
*/