/*
 * @Author: dsaDadas11
 * @Date: 2024-08-09 15:03:11
 * @LastEditTime: 2024-08-09 15:03:45
 * @Description: go for it!
 */
/*
 大模拟罢了
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e5+7;
constexpr int M=2e3+7;
constexpr int inf=1e9;
int n,k,p; // 总数量 合成的物品 物品种类
struct Product
{
	bool type;
	int t; // 花费时间 t
	vector<pair<int,int> > p; // x a
}prod[N];
int val[N]; // 每种物品需要花费的时间
int temp,x,a;
int dfs(int x)
{
	if(val[x]!=0) return val[x];
	int len=prod[x].p.size();
	int sum=0;
	for(int i=0;i<len;i++)
	{
		int xx=prod[x].p[i].first; // 数量
		int aa=prod[x].p[i].second; // 种类
		if(val[aa]!=0)
		{
			sum+=val[aa]*xx;
		}
		else
		{
			val[aa]=dfs(aa);
			sum+=val[aa];
		}
	}
	return sum;
}
void solve()
{
	memset(prod,0,sizeof prod);
	memset(val,0,sizeof val);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>p;
		if(p==0)
		{
			prod[i].type=0;
			cin>>prod[i].t;
			val[i]=prod[i].t;
		}
		else
		{
			prod[i].type=1;
			cin>>temp;
			for(int j=1;j<=temp;j++)
			{
				cin>>x>>a;
				prod[i].p.push_back({x,a});
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(i==k) continue;
		if(prod[i].type==0) continue;
		val[i]=dfs(i);
	}
	int len=prod[k].p.size();
	vector<int> cho;
	for(int i=0;i<len;i++)
	{
		int xx=prod[k].p[i].first; // 数量
		int aa=prod[k].p[i].second; // 种类
		cho.push_back(xx*val[aa]);
	}
	sort(cho.begin(),cho.end());
	len=cho.size();
	int ans=0;
	for(int i=0;i<len-1;i++)
	{
		ans+=cho[i];
		if(ans>inf)
		{
			cout<<"Impossible"<<endl;
			return;
		}
	}
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}