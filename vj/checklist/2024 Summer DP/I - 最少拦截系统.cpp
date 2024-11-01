/*
 * @Author: dsaDadas11
 * @Date: 2024-08-05 09:54:58
 * @LastEditTime: 2024-08-05 09:56:56
 * @Description: go for it!
 */
/*
 用lower_bound()找ans[]中是否有 ans[i]>=a[i]的位置
 ans[]记录的是每个导弹系统的最后一个h[i](即最小的一个)
 如果没有就push_back()
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
int a[N];
void solve()
{
	for(int i=1;i<=n;i++) cin>>a[i];
	vector<int> ans;
	ans.push_back(a[1]);
	for(int i=2;i<=n;i++)
	{
		int pos=lower_bound(ans.begin(),ans.end(),a[i])-ans.begin();
		if(pos>=(int)ans.size()) ans.push_back(a[i]);
		else ans[pos]=a[i];
	}
	cout<<ans.size()<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	while(cin>>n) solve();
	return 0;
}