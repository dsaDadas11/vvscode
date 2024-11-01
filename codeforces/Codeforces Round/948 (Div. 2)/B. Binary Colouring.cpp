/*
 * @Author: dsaDadas11
 * @Date: 2024-09-29 18:18:49
 * @LastEditTime: 2024-09-29 18:22:47
 * @Description: go for it!
 */
/*
 解题思路：
 我们怎么能得到这个二进制序列 1 1 1 0 (两个1不能在一起)
 是不是得 1 0 0 0 0 减去 0 0 0 1 0
 因此我们只需要记录最后一位1，并且进一位1即可
 然后根据题意要求 1和-1也不能在一起
 如果它们相邻就有两种情况
 1. 2^i-2^(i-1)=2^(i-1)
 2. -2^i+2^(i-1)=-2^(i-1)
 最后除去后导零模拟即可
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int x;
void solve()
{
    cin>>x;
    vector<int> v;
    while(x)
    {
        v.push_back(x&1);
        x>>=1;
    }
    vector<int> ans;
    int len=v.size();
    for(int i=0;i<len;i++)
    {
        if(v[i]==1)
        {
            ans.push_back(-1);
            i++;
            for(;i<len;i++)
            {
                if(v[i]==0)
                {
                    ans.push_back(1);
                    break;
                }
                else ans.push_back(0);
            }
        }
        else ans.push_back(0);
    }
    // 特判一下边界，因为要进一位
    if(v[len-1]==1) ans.push_back(1);
    int lena=ans.size();
    for(int i=0;i<lena-1;i++)
    {
        if(ans[i]==-1&&ans[i+1]==1)
        {
            ans[i]=1;
            ans[i+1]=0;
        }
        if(ans[i]==1&&ans[i+1]==-1)
        {
            ans[i]=-1;
            ans[i+1]=0;
        }
    }
    // 除后导0
    for(int i=lena-1;i>=0;i--)
    {
        if(ans[i]==0) ans.pop_back();
        else break;
    }
    cout<<ans.size()<<endl;
    for(auto i:ans) cout<<i<<' ';
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}