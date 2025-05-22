/*
 * @Author: dsaDadas11
 * @Date: 2025-05-15 19:26:36
 * @LastEditTime: 2025-05-15 19:33:50
 * @Description: go for it!
 */
/*
 解题思路：
 这道题是非常好的思维题
 首先操作一是有序的，操作二是无序的，
 操作二只能在操作一完成后操作，也就是大括号中的所有小括号都添加完成时才能加入
 那么对于每个操作二的方案数就是该大括号后面的小括号和大括号的数量之和，再加上 1
 例如样例二：((()())()())(())，我们将小括号写成 1得： ((1 1)1 1)(1)
 用小括号的下标代表大括号的 ')'下标，这样我们就可以根据先后顺序遍历大括号并且统计答案
 答案为操作二的方案数连乘
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
constexpr int mod=998244353;
string s;
bool vis[N];
void solve()
{
    cin>>s;
    int len=s.size();
    s=' '+s;
    vector<int> pos; // 记录大括号的位置
    int p=0; // 记录小括号下表
    for(int i=1;i<=len;i++)
    {
        if(s[i]=='('&&s[i+1]==')'&&i+1<=len)
        {
            p++;
            i++;
        }
        else if(s[i]==')') pos.push_back(p);
    }
    int ans=1;
    for(int i=0;i<pos.size();i++)
    {
        ans*=p-pos[i]+1+pos.size()-i-1;
        ans%=mod;
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}