/*
 * @Author: dsaDadas11
 * @Date: 2024-02-05 19:41:54
 * @LastEditTime: 2024-02-06 14:18:39
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
bool mp[M][M];
bool vis[M][M];
void solve()
{
	int n,m,k; cin>>n>>m>>k;
	for(int i=1;i<=k;i++)
	{
		int x,y; cin>>x>>y;
		mp[x*2][y*2]=1;
	}
	for(int i=1;i<=n*2+6;i++)
	{
		for(int j=1;j<=m*2+6;j++)
		{
			if(mp[i][j])
			{
				if(vis[i-1][j]==0) vis[i-1][j]=1;
				if(vis[i][j-1]==0) vis[i][j-1]=1;
				if(vis[i][j+1]==0) vis[i][j+1]=1;
				if(vis[i+1][j]==0) vis[i+1][j]=1;
			}
		}
	}
	int cnt=0;
	for(int i=1;i<=n*2+6;i++)
	{
		for(int j=1;j<=m*2+6;j++)
		{
			if(vis[i][j]) cnt++;
		}
	}
	cout<<cnt<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}

//更简单的ac代码
/*
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    int s[305][304];
    int mw=4*k;
    for(int i=0;i<k;i++){
        int x=0,y=0;
        cin>>x>>y;
        s[x][y]+=1;
        mw-=s[x-1][y]+s[x][y-1]+s[x][y+1]+s[x+1][y];
    }
             
    cout<<mw;
    return 0;
     
    
}
*/