/*
 * @Author: dsaDadas11
 * @Date: 2024-09-27 21:10:26
 * @LastEditTime: 2024-09-27 21:17:40
 * @Description: go for it!
 */
// URL: https://codeforces.com/contest/2013/problem/C
/*
 解题思路：
 这道题是一道交互题，交互题不仅要输入数据，还要输出数据看系统的返回值(如0/1)，
 需要看着代码理解
 这道题有个hack点在往右加子串时不能写
 if(ask('0'+ans)) ans='0'+ans;
 else  if(ask('1'+ans)) ans='1'+ans;
 else break;
 题目要求我们要在小于等于2*n的操作数找到答案，一般这样的情况是可以的，
 但是在极端的条件下
 假设向右的子串的长度为 n1,那么操作数就是 2*(n1+1) 因为最后一位的后一位也要判断，
 然后向左找子串的长度假设为 n2,那么操作数为2*n2 两者加一起为2*n+2很明显超2*n了，
 所以我们在向左找子串时完全可以去掉一个判断改用if，因为没有多余的情况需要判断了
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
bool ask(string s)
{
    cout<<"? "<<s<<endl;
    cout.flush();
    int res;
    cin>>res;
    return res; // 看看系统的返回值
}
void solve()
{
    cin>>n;
    string ans="";
    // 先往右边加子串
    while(ans.size()<n)
    {
        if(ask(ans+'0')) ans+='0';
        else if(ask(ans+'1')) ans+='1';
        else break; // 右边不能继续加了就退出
    }
    // 往左边加子串
    while(ans.size()<n)
    {
        if(ask('0'+ans)) ans='0'+ans;
        else ans='1'+ans;
    }
    cout<<"! "<<ans<<endl;
    cout.flush();
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}