/*
 * @Author: dsaDadas11
 * @Date: 2024-02-19 18:21:26
 * @LastEditTime: 2024-02-19 18:21:33
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
char mp[M][M];
int op[N],z[N];
void solve()
{
	int n,m,x,y; cin>>n>>m>>x>>y;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>mp[i][j];
        }
    }
    int p,q; cin>>p>>q;
    for(int j=1;j<=q;j++) cin>>op[j]>>z[j];
    for(int i=1;i<=p;i++)
    {
        for(int j=1;j<=q;j++)
        {
            if(op[j]==1)
            {
                char temp=mp[z[j]][m];
                for(int k=m;k>=2;k--)
                {
                    mp[z[j]][k]=mp[z[j]][k-1];
                }
                mp[z[j]][1]=temp;
            }
            else
            {
                char temp=mp[n][z[j]];
                for(int k=n;k>=2;k--)
                {
                    mp[k][z[j]]=mp[k-1][z[j]];
                }
                mp[1][z[j]]=temp;
            }
        }
    }
    cout<<mp[x][y]<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}