/*
 * @Author: dsaDadas11
 * @Date: 2024-05-21 22:01:42
 * @LastEditTime: 2024-05-21 22:05:41
 * @Description: go for it!
 */
/*
如果学过 LIS，里面有一种做法，从一个空数组（结果数组）开始，用二分替换的方式求一个给定数组的 LIS，其核心思想是插入数值，让结果数组变得更优，这道题也是属于利用插入。
一个显然的性质是：反转数组的最长上升（严格）子序列就是原数组的最长下降（严格）子序列，显然，这两个最多只能有一个下标的交集。
因此，对数组中有重复的数字，我们可以将它放入上升和下降两个子序列中（更多的同一重复数字没有作用）。那么没有重复的数字，我们就可以将它们等量地插入进这两个子序列中。当这个没有重复的数字个数 t tt 是奇数个时，我们可以将它当作两个序列公共的那个数字，因此答案只需要再加上一个有重复的数字个数 s
最终结果是:s+⌈t/2⌉
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,x;
void solve()
{
	cin>>n;
	map<int,int> mp;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		mp[x]++;
	}
	int cnt1=0,cnt2=0;
	// 大于等于2的只能对序列产生一点贡献
	// 只有一个的可以放在两边(奇数中有一个可以放中间)
	for(auto it:mp)
	{
		if(it.second>=2) cnt1++;
		else cnt2++;
	}
	cout<<cnt1+(cnt2+1)/2<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}