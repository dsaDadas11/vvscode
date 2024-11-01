/*
 * @Author: dsaDadas11
 * @Date: 2024-10-04 16:16:29
 * @LastEditTime: 2024-10-04 21:22:43
 * @Description: go for it!
 */
/*
 解题思路：
 题目说的很明白了，贪心的将人选入最好的职位，人满了再分配进另一个职位，
 然后我们要记录每个人的选择的职位，
 我们先预处理出 n个人进职位1 m+1个人进职位2 的 val1
 和 n+1个人进职位1 m个人进职位2 的 val2
 然后如果第i个人选的是职位1，就用val2-a[i]
 否则就用 val1-b[i]
 本质就是将多余的人去掉
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=2e5+7;
constexpr int M=2e3+7;
int n,m;
int a[N],b[N];
void solve()
{
    cin>>n>>m;
    int sum=n+m+1;
    for(int i=1;i<=sum;i++) cin>>a[i];
    for(int i=1;i<=sum;i++) cin>>b[i];
    // 先记录 n m+1 的val
    vector<int> pro1,tes1;
    vector<bool> cho1(sum+1,0); // 每个人的选择
    for(int i=1;i<=sum;i++)
    {
        if(a[i]>b[i])
        {
            if(pro1.size()<n) pro1.push_back(i),cho1[i]=1;
            else tes1.push_back(i),cho1[i]=0;
        }
        else
        {
            if(tes1.size()<m+1) tes1.push_back(i),cho1[i]=0;
            else pro1.push_back(i),cho1[i]=1;
        }
    }
    int ans1=0;
    for(auto p:pro1) ans1+=a[p];
    for(auto p:tes1) ans1+=b[p];
    // 再记录 n+1 m 的val
    vector<int> pro2,tes2;
    for(int i=1;i<=sum;i++)
    {
        if(a[i]>b[i])
        {
            if(pro2.size()<n+1) pro2.push_back(i);
            else tes2.push_back(i);
        }
        else
        {
            if(tes2.size()<m) tes2.push_back(i);
            else pro2.push_back(i);
        }
    }
    int ans2=0;
    for(auto p:pro2) ans2+=a[p];
    for(auto p:tes2) ans2+=b[p];
    // 开始寻找答案
    for(int i=1;i<=sum;i++)
    {
        if(cho1[i]==1) cout<<ans2-a[i]<<' ';
        else cout<<ans1-b[i]<<' ';
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