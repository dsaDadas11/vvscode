#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define int ll
char mp[1009][1009];
struct op
{
    int x, y;
};
bool find_edge(int x, int y)
{
    int cnt = 0;
    for (int i = x - 3; i <= x + 6; i++)
    {
        for (int j = y - 4; j <= y + 5; j++)
        {
            if (mp[i][j] == '#')
            {
                cnt++;
            }
        }
    }
    if (cnt == 88) return 1;
    else return 0;
}
bool find_hole(int x, int y)
{
    bool yi = 0, er = 0, san = 0, si = 0;
    bool bianjie = 0;
    if (mp[x][y + 1] == '.')
    {
        yi = 1;
    }
    if (mp[x + 1][y - 1] == '.' && mp[x + 1][y] == '.' && mp[x + 1][y + 1] == '.' && mp[x + 1][y + 2] == '.')
    {
        er = 1;
    }
    if (mp[x + 2][y - 1] == '.' && mp[x + 2][y] == '.' && mp[x + 2][y + 1] == '.' && mp[x + 2][y + 2] == '.')
    {
        san = 1;
    }
    if (mp[x + 3][y] == '.' && mp[x + 3][y + 1] == '.')
    {
        si = 1;
    }
    bianjie=find_edge(x, y);
    if (yi&&er&&san&&si&&bianjie) return 1;
    return 0;
}
void solve()
{
    int n, m,sum=0;
    cin >> n >> m;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            cin>>mp[i][j];
            if (mp[i][j]=='#')
            {
                sum++;
            }
        }
    }
    vector<op> pos;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            if (mp[i][j]=='.')
                if (find_hole(i, j))
                    pos.push_back({i, j});
    int len=pos.size();
    int C=0,S=0;
    C = (100 * len - sum)/54;
    cout<<C<<' '<<len-2*C<<endl;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T=1; //cin>>T;
	while(T--){solve();}
    return 0;
}
/*
更简短的ac代码：

#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e3+7;
constexpr int M=2e3+7;
int n, m, cntw, sumb;
char a[N][N];
vector<string> t={
	"######",
	"##..##",
	"#....#",
	"#....#",
	"##..##",
	"######"
};
int check(int x,int y){
	for(int i=0;i<=5;i++)
		for(int j=0;j<=5;j++)
			if (x<1||y<1||x+i>n||y+j>m||a[x+i][y+j]!=t[i][j])
				return 0;
	return 1;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			cin>>a[i][j];
	for(int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (a[i][j]=='#') sumb++;
	else cntw+=check(i-1,j-2);
	int x=(cntw*100-sumb)/54;
	cout<<x<<" "<<cntw-2*x<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}
*/