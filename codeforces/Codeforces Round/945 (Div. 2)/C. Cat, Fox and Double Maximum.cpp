/*
 * @Author: dsaDadas11
 * @Date: 2024-09-27 17:18:45
 * @LastEditTime: 2024-09-27 17:22:18
 * @Description: go for it!
 */
/*
 解题思路：
 这道题的n一直是偶数，所以我们只要考虑偶数的情况
 然后我们考虑1这个数，要让1加一个数变成最大是更困难的，
 所以我们需要避开1的位置及其距离为2的位置 
 比如1的位置在5，那我们就需要避开1 2 3 5 7 9...等位置，让剩余位置变成最大，
 这样才能最大化ai>ai-1 ai>ai+1 的数量
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e5+7;
constexpr int M=2e3+7;
int n;
int p[N];
int q[N];
struct op
{
	int val,idx;
	bool operator<(const op&a) const
	{
		return val<a.val;
	}
};
void solve()
{
	cin>>n;
	vector<op> v1,v2;
	int pos;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		if(p[i]==1)
		{
			pos=i%2; // 这位置及其距离为2的位置都是最小值
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(i%2==pos) v2.push_back({p[i],i});
		else v1.push_back({p[i],i});
	}
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	int len1=v1.size(),len2=v2.size();
	int t=n;
	for(int i=0;i<len1;i++)
	{
		q[v1[i].idx]=t;
		t--;
	}
	for(int i=0;i<len2;i++)
	{
		q[v2[i].idx]=t;
		t--;
	}
	for(int i=1;i<=n;i++) cout<<q[i]<<' ';
	cout<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}