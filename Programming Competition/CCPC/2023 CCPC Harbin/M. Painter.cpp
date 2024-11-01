/*
 * @Author: dsaDadas11
 * @Date: 2024-10-02 16:06:01
 * @LastEditTime: 2024-10-02 16:36:28
 * @Description: go for it!
 */
/*
 解题思路：
 这是我认为最容易re的一道题，因为数据范围是1e4，要开二维数组肯定是2e4*2e4，
 本地编译器能通过，但是在OJ上就会MLE
 所以我们只能在每次要打印的时候暴力枚举前面的条件，复杂度是远小于n*n*length的(想想就知道了)
 并且我们要将负数变为正数，大数变为小数
 例如区间 [1e8,1e8+7] 可以变为 [0,7], [-1,2]可以变为[0,2],也就是 x2-=x1,x1=0 
 接下来模拟就可以了
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=2e3+7;
constexpr int M=1e4+7;
int n;
string op;
vector<string> v;
struct cir
{
	int x,y,r;
	char col;
};
vector<cir> a;
struct rec
{
	int x1,y1,x2,y2;
	char col;
};
vector<rec> b;
struct ren
{
	int x1,y1,x2,y2;
};
vector<ren> c;
int cnt1,cnt2,cnt3;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x,y,r;
		char col;
		int x1,y1,x2,y2;
		cin>>op;
		v.push_back(op);
		if(op=="Circle")
		{
			cin>>x>>y>>r>>col;
			a.push_back({x,y,r,col});
		}
		else if(op=="Rectangle")
		{
			cin>>x1>>y1>>x2>>y2>>col;
			b.push_back({x1,y1,x2,y2,col});
		}
		else if(op=="Render")
		{
			cin>>x1>>y1>>x2>>y2;
			c.push_back({x1,y1,x2,y2});
		}
	}
	for(int i=0;i<n;i++)
	{
		op=v[i];
		if(op=="Render")
		{
			auto [x1,y1,x2,y2]=c[cnt3];
			cnt3++;
			vector<vector<char> > mp(y2-y1+5,vector<char>(x2-x1+5));
			x2-=x1,y2-=y1;
			int d1=x1,d2=y1;
			x1=0,y1=0;
			for(int j=0;j<i;j++)
			{
				if(v[j]=="Circle")
				{
					auto [x,y,r,col]=a[cnt1];
					x-=d1,y-=d2;
					cnt1++;
					for(int i=max(0LL,y-r);i<=min(y2,y+r);i++)
					{
						for(int j=max(0LL,x-r);j<=min(x2,x+r);j++)
						{
							if((i-y)*(i-y)+(j-x)*(j-x)<=r*r)
							{
								mp[i][j]=col;
							}
						}
					}
				}
				else if(v[j]=="Rectangle")
				{
					auto [xx1,xy1,xx2,xy2,col]=b[cnt2];
					xx2-=d1,xy1-=d2;
					xx1-=d1,xy2-=d2;
					cnt2++;
					for(int i=max(0LL,xy1);i<=min(y2,xy2);i++)
					{
						for(int j=max(0LL,xx1);j<=min(x2,xx2);j++)
						{
							mp[i][j]=col;
						}
					}
				}
			}
			for(int i=y2;i>=y1;i--)
			{
				for(int j=x1;j<=x2;j++)
				{
					if(mp[i][j]=='\0') cout<<'.';
					else cout<<mp[i][j];
				}
				cout<<endl;
			}
			cnt1=cnt2=0;
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}