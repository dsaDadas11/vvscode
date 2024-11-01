/*
 * @Author: dsaDadas11
 * @Date: 2024-05-14 20:06:06
 * @LastEditTime: 2024-05-14 20:09:55
 * @Description: go for it!
 */
#include <bits/stdc++.h>
using namespace std;
#define int ll
#define ll long long
#define endl '\n'
#define buff ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
const int N=2e5+7;
const int inf=1e9;
int n,hpa,hpb;
int a[N],b[N];
int pre[N]; 
bool cmp(int x,int y)
{
	return x>y;
}
void solve()
{
	cin>>n>>hpa>>hpb;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==-1) cnt++;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
		if(b[i]==-1) b[i]=1e9;
	}
	sort(a+1,a+1+n,cmp);
	sort(b+1,b+1+n);
	int pos=n;
	for(int i=1;i<=n;i++)
	{
		pre[i]=pre[i-1]+b[i];
		if(pre[i]>=hpa)
		{
			pos=i-1;
			break;
		}
	}
	for(int i=1;i<=pos;i++)
	{
		if(b[i]==1e9)
		{
			continue;
		}
		else if(a[i]==-1)
		{
			cnt--;
			continue;
		}
		hpa-=b[i];
		hpb-=a[i];
		if(hpb<=0)
		{
			if(hpa<=0)
			{
				cout<<"no"<<endl;
				return;
			}
			cout<<"yes"<<endl;
			return;
		}
		if(hpa<=0)
		{
			cout<<"no"<<endl;
			return;
		}
	}
	int p=pos+cnt+1;
	if(p>n)
	{
		cout<<"no"<<endl;
		return;
	}
	if(b[p]==1e9||a[p]==-1)
	{
		if(hpb<=0)
		{
			if(hpa<=0)
			{
				cout<<"no"<<endl;
				return;
			}
			cout<<"yes"<<endl;
			return;
		}
		if(hpa<=0)
		{
			cout<<"no"<<endl;
			return;
		}
	}
	else
	{
		hpa-=b[p];
		hpb-=a[p];
		if(hpb<=0)
		{
			if(hpa<=0)
			{
				cout<<"no"<<endl;
				return;
			}
			cout<<"yes"<<endl;
			return;
		}
		if(hpa<=0)
		{
			cout<<"no"<<endl;
			return;
		}
	}
	cout<<"no"<<endl;
}

signed main()
{
	buff;
	int tt = 1;
	 cin >> tt;
	while (tt--)
	{
		solve();
	}
	return 0;
} 