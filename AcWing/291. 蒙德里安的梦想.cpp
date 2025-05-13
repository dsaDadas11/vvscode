/*
 * @Author: dsaDadas11
 * @Date: 2025-05-13 20:45:14
 * @LastEditTime: 2025-05-13 21:00:16
 * @Description: go for it!
 */
/*
 解题思路：
 f[i][j] 表示前 i-1列已经摆好，且从 i-1列的状态 j伸出到第 i列的方案数
 其中 j中 1代表横着放长方形，伸出出至 i列，0代表不放，剩下的 0摆竖着的
 ans=f[m][0]
 预处理：
 1.若 s1,s2表示相邻两列的两种状态 如果 s1&s2!=0 就代表放的长方形重叠了，方案不可行
 2.摆完横的再将剩余的空摆竖的，这就要求两个 1之间的 0必须为偶数
 初始化 f[0][0]=1 因为第 0列只能竖着放，方案数为 1
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m;
void solve()
{
    vector<bool> vis(1<<11); // 标记可行的状态
    vector<vector<int> > s(1<<11); // 每个可行的状态可由哪些状态遍历而来

    // 先处理出偶数个 0的状态
    int cnt=0;
    for(int i=0;i<(1<<n);i++)
    {
        cnt=0;
        bool ok=1;
        for(int j=0;j<n;j++)
        {
            if((i>>j)&1)
            {
                if(cnt&1)
                {
                    ok=0;
                    break;
                }
                cnt=0;
            }
            else cnt++;
        }
        if(cnt&1) ok=0;
        if(ok) vis[i]=1;
    }

    // 再处理出两个状态可以合法转移的状态
    for(int i=0;i<(1<<n);i++)
    {
        for(int j=0;j<(1<<n);j++)
        {
            if((i&j)||vis[i|j]==0) continue;
            s[i].push_back(j);
        }
    }

    vector<vector<int> > f(12,vector<int>(1<<11)); // 从第 0列到 m-1列
    f[0][0]=1; // 第 0列只有竖着摆一种方法

    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<(1<<n);j++)
        {
            for(auto k:s[j])
            {
                f[i][j]+=f[i-1][k];
            }
        }
    }

    cout<<f[m][0]<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(cin>>n>>m&&n&&m){solve();}
    return 0;
}