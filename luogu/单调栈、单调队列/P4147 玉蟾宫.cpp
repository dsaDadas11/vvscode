/*
 * @Author: dsaDadas11
 * @Date: 2025-03-12 20:52:21
 * @LastEditTime: 2025-03-16 10:51:53
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=1e3+7;
struct op
{
	int val,len;
};
int n,m;
int a[M][M];
op stk[M];
int p;
char ch;
int calc(int x)
{
	int res=0;
	p=0;
	for(int i=1;i<=m;i++)
	{
		int w=0;
		while(p&&a[x][i]<=stk[p].val)
		{
			w+=stk[p].len;
			res=max(res,w*stk[p].val);
			p--;
		}
		stk[++p]={a[x][i],w+1};
	}
	int w=0;
	while(p)
	{
		w+=stk[p].len;
		res=max(res,stk[p].val*w);
		p--;
	}
	return res;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>ch;
			if(ch=='F') a[i][j]=a[i-1][j]+1;
			else a[i][j]=0;
		}
	}
	
	int ans=0;
	for(int i=1;i<=n;i++) ans=max(ans,calc(i));
	cout<<3*ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}

/*
 并查集做法：
 从每一列最高的开始合并，枚举到 p时看 p的左右两边是否遍历到，
 遍历到则说明比 p高度大，可以合并

#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=1e3+7;
int n,m;
char ch;
int h[M][M];
int sz[M],fa[M];
bool vis[M];
int find_fa(int x)
{
    if(fa[x]==x) return x;
    return fa[x]=find_fa(fa[x]);
}
void merge_set(int x,int y)
{
    int fax=find_fa(x);
    int fay=find_fa(y);
    fa[fax]=fay;
    sz[fay]+=sz[fax];
}
int calc(int x)
{
    for(int i=1;i<=m;i++) fa[i]=i,sz[i]=1,vis[i]=0;
    vector<pair<int,int> > v(m+1);
    for(int j=1;j<=m;j++) v[j]={h[x][j],j};
    sort(v.begin()+1,v.end(),greater<>());
    int res=0;
    for(int j=1;j<=m;j++)
    {
        auto [val,p]=v[j];
        if(vis[p-1]) merge_set(p-1,p);
        if(vis[p+1]) merge_set(p+1,p);
        vis[p]=1;
        res=max(res,val*sz[find_fa(p)]);
    }
    return res;
}
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>ch;
            if(ch=='F') h[i][j]=h[i-1][j]+1;
        }
    }

    int ans=0;
    for(int i=1;i<=n;i++) ans=max(ans,calc(i));

    cout<<ans*3<<endl;

}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}

*/

/*
 悬线法：只要枚举左右区间，并且保证与 i-1的左右区间维持最小
 注意限制条件

#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m;
char ch[M][M];
int h[M][M];
int l[M][M],r[M][M];
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>ch[i][j];
            if(ch[i][j]=='F') h[i][j]=h[i-1][j]+1;
        }
    }

    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(ch[i][j]=='R') l[i][j]=0;
            else l[i][j]=l[i][j-1]+1;
        }

        for(int j=m;j>=1;j--)
        {
            if(ch[i][j]=='R') r[i][j]=0;
            else r[i][j]=r[i][j+1]+1;
        }


        for(int j=1;j<=m;j++)
        {
            if(ch[i][j]=='R'||ch[i-1][j]=='R'||i<=1) continue;
            l[i][j]=min(l[i][j],l[i-1][j]);
            r[i][j]=min(r[i][j],r[i-1][j]);
        }
        for(int j=1;j<=m;j++)
        {
            if(ch[i][j]=='R') continue;
            ans=max(ans,h[i][j]*(l[i][j]+r[i][j]-1));
        }
    }

    cout<<ans*3<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}
*/