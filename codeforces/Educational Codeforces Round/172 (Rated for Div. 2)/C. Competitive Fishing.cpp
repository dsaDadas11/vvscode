/*
 * @Author: dsaDadas11
 * @Date: 2024-12-03 13:28:23
 * @LastEditTime: 2024-12-03 13:30:46
 * @Description: go for it!
 */
/*
 解题思路：
 2024山东邀请赛签到题的变形题
 https://codeforces.com/gym/105385/problem/F

 因为每次减的数是 组别-1
 那么第一次分第一个元素时的组别就为 1了，此时不做任何操作 (因为不用减)
 然后遍历从suf的最大值开始往小遍历找答案即可
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,k;
string s;
int suf[N];
void solve()
{
	cin>>n>>k;
	cin>>s;
	s=' '+s;
	suf[n+1]=0;
	for(int i=n;i>=1;i--)
	{
		suf[i]=suf[i+1]+(s[i]=='1'?1:-1);
	}
	int ans=1;
	vector<pair<int,int> > v;
	for(int i=2;i<=n;i++)
	{
		if(suf[i]>0)
		{
			v.push_back({suf[i],i});
		}
	}
	sort(v.begin(),v.end());
	for(int i=v.size()-1;i>=0;i--)
	{
		k-=suf[v[i].second];
		ans++;
		if(k<=0) return cout<<ans<<endl,void();
	}
	if(k<=0) cout<<ans<<endl;
	else cout<<"-1"<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}