/*
 * @Author: dsaDadas11
 * @Date: 2024-02-22 15:46:31
 * @LastEditTime: 2024-02-22 15:46:37
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
bool a[N];
int p[N];
vector<int> ans;
void dfs(int x)
{
    if(x==0) return;
    if(x==1)
    {
        ans.push_back(1);
        return;
    }
    for(int i=1;i<=x;i++)
    {
        if(a[i+x])
        {
            for(int j=i;j<=x;j++)
            {
                ans.push_back(j);
            }
            dfs(i-1);
            break;
        }
    }
    return;
}
void solve()
{
	int cnt=0;
    memset(a,1,sizeof a);
    int n; cin>>n;
    int now=n;
    for(int i=2;i<=2*n;i++)
    {
        if(a[i]) p[++cnt]=i;
        for(int j=1;j<=cnt&&p[j]*i<=2*n;j++)
        {
            a[p[j]*i]=0;
            if(!i%p[j]) break;
        }
    }
    dfs(n);
    for(int i=ans.size()-1;i>=0;i--) cout<<ans[i]<<' ';
    cout<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}