/*
 * @Author: dsaDadas11
 * @Date: 2024-09-24 20:40:05
 * @LastEditTime: 2024-09-24 20:43:41
 * @Description: go for it!
 */
/*
 解题思路：
 因为beautiful三元组的定义是
 b1≠c1 and b2=c2 and b3=c3
 b1=c1 and b2≠c2 and b3=c3
 b1=c1 and b2=c2 and b3≠c3
 那么可以用map存一下这种不同的情况，不过需要减{b1,b2,b3}这个元组，因为其形式和上面的是一样，会重复
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=2e5+7;
constexpr int M=2e3+7;
int n;
int a[N];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	map<array<int,3>,int> mp; // 哈希三元组
	int ans=0;
	for(int i=1;i<=n-2;i++)
	{
		array<int,3> cc={a[i],a[i+1],a[i+2]};
		vector<array<int,3> > v=
		{
			{0,a[i+1],a[i+2]}, // 不相等就全定义成0
			{a[i],0,a[i+2]},
			{a[i],a[i+1],0}
		};
		for(auto ar:v)
		{
			ans+=mp[ar]-mp[cc]; // 减原来的
			mp[ar]++; //查完这个三元组再加
		}
		mp[cc]++;
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