#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=2e5+7;
constexpr int M=2e3+7;
int a[N];
void solve()
{
	int n; cin>>n;
	map<int,int> mp;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		int x; cin>>x;
		if(mp[x]==0) mp[x]=++cnt;
		a[mp[x]]++;
	}
	sort(a+1,a+1+cnt);
	int ans=0;
	for(int i=1;i<=a[cnt];i++)
	{
		int res=0;
		int st=1;
		for(int j=i;j<=a[cnt];j*=2)
		{
			int pos=lower_bound(a+st,a+1+cnt,j)-a;
			if(pos==cnt+1) break;
			else res+=j;
			st=pos+1;
		}
		ans=max(ans,res);
	}
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
  手写lower_bound有风险
  ac手写lower_bound:
  for(int j=i;j<=a[cnt];j*=2)
		{
			int l=st,r=cnt;
			while(l<r)
			{
				int mid=(l+r)>>1;
				if(a[mid]>=j) r=mid; //不加等号wa
				else l=mid+1;
			}
			//int pos=lower_bound(a+st,a+1+cnt,j)-a;
			if(l==cnt+1) break;
			else res+=j;
			st=l+1;
		}
*/