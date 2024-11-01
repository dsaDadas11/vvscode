/*
 * @Author: dsaDadas11
 * @Date: 2024-10-05 19:20:13
 * @LastEditTime: 2024-10-05 19:24:13
 * @Description: go for it!
 */
/*
 解题思路：
 一开始题读假了，题目的意思是学一个类型的单词要学完才行，否则不能学
 举个例子，设一天能学3个单词，单词1有2个，单词2有4个，
 第一天学完单词1就不能学单词2了，因为剩余能学的单词数小于单词2的个数，
 接下来排序贪心就行
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,w;
int cnt[25];
void solve()
{
    cin>>n>>w;
    int x;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        cnt[x]++;
    }
    sort(cnt+1,cnt+1+13);
    int ans=0;
    for(int i=13;i>=1;i--)
    {
        if(cnt[i]==0) continue;
        ans++;
        int t=w-cnt[i];
        for(int j=i-1;j>=1;j--)
        {
            if(t>=cnt[j])
            {
                t-=cnt[j];
                cnt[j]=0;
            }
        }
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