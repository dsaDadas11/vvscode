/*
 * @Author: dsaDadas11
 * @Date: 2025-06-11 19:54:01
 * @LastEditTime: 2025-06-11 19:54:58
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,a,b;
int ans;
vector<int> num;
void dfs(int x,int res)
{
	if(x==num.size())
	{
		ans=max(ans,res);
		return;
	}
	
    int cur=num[x];

    int da=min(a,9-cur);
    a-=da;
    int val=cur+da;
    dfs(x+1,res*10+val);
    a+=da;

    if(b>=cur+1)
    {
        b-=(cur+1);
        dfs(x+1,res*10+9);
        b+=(cur+1);
    }
}
void solve()
{
	cin>>n>>a>>b;
	int tmp=n;
	ans=n;
	while(tmp!=0)
	{
		num.push_back(tmp%10);
		tmp/=10;
	}
	reverse(num.begin(),num.end());
	dfs(0,0);
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}

/*
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,a,b;
int ans;
vector<int> num;
void dfs(int x,int cnta,int cntb)
{
	if(x==num.size())
	{
		int base=1LL;
		int res=0LL;
		for(int i=num.size()-1;i>=0;i--)
		{
			res+=num[i]*base;
			base*=10LL;
		}
		ans=max(ans,res);
		return;
	}
	if(num[x]==9) dfs(x+1,cnta,cntb);
	else
	{
		// 用 A
		if(cnta>=0)
		{
			int d=9-num[x];
			int tmp=num[x];
			if(cnta>=d)
			{
				num[x]=9;
				dfs(x+1,cnta-d,cntb);
				num[x]=tmp;
			}
			else
			{
				num[x]+=cnta;
				dfs(x+1,0,cntb);
				num[x]-=cnta;
			}
		}
		
		// 用 B
		if(cntb>=0)
		{
			int d=num[x]+1;
			int tmp=num[x];
			if(cntb>=d)
			{
				num[x]=9;
				dfs(x+1,cnta,cntb-d);
				num[x]=tmp;
			}
		}
		
		// dfs(x+1,cnta,cntb); 加上这句就是错的。。。
	}
}
void solve()
{
	cin>>n>>a>>b;
	int tmp=n;
	ans=n;
	while(tmp!=0)
	{
		num.push_back(tmp%10);
		tmp/=10;
	}
	reverse(num.begin(),num.end());
	dfs(0,a,b);
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}
*/