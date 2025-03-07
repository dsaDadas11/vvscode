/*
 * @Author: dsaDadas11
 * @Date: 2025-03-05 19:37:38
 * @LastEditTime: 2025-03-05 19:37:50
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=30;
int n,m;
bool dist[M][M];
bool vis[M];
int floyd()
{
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dist[i][j]|=dist[i][k]&&dist[k][j];
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(dist[i][i]) return 1; // 成环了
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j) continue;
            if(dist[i][j]==0&&dist[j][i]==0) return 0; // 还没排完
        }
    }
    return 2; // 可以排
}
char get_ans()
{
    for(int i=1;i<=n;i++)
    {
        if(vis[i]) continue;
        bool flag=1;
        for(int j=1;j<=n;j++)
        {
            //if(i==j) continue;
            if(!vis[j]&&dist[j][i])
            {
                flag=0;
                break;
            }
        }
        if(!flag) continue;
        vis[i]=1;
        return 'A'+i-1;
    }
    return 'A';
}
void solve()
{
    cin>>n>>m;
    char a,op,b;
    int flag=0;
    int cnt=0;
    for(int i=1;i<=m;i++)
    {
        cin>>a>>op>>b;
        //cout<<a<<" "<<op<<" "<<b<<endl;
        int u=a-'A'+1;
        int v=b-'A'+1;
        //cout<<u<<' '<<v<<endl;
        if(!flag) // 为0时才能继续走
        {
            dist[u][v]=1;
            flag=floyd();
            if(flag) cnt=i;
        }

    }
    if(flag==0) cout<<"Sorted sequence cannot be determined."<<endl;
    else if(flag==1)
    {
        cout<<"Inconsistency found after "<<cnt<<" relations."<<endl;
    }
    else
    {
        cout<<"Sorted sequence determined after "<<cnt<<" relations: ";
        for(int i=1;i<=n;i++) cout<<get_ans();
        cout<<"."<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}