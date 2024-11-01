/*
 * @Author: dsaDadas11
 * @Date: 2024-08-17 15:11:24
 * @LastEditTime: 2024-08-17 15:15:24
 * @Description: go for it!
 */
/*
 解题思路：
 1.如果全是单牌，那么后手可以选和先手一样的牌，直到先手没牌可选，此时后手胜
 2.如果既有单牌又有双牌，此时我们应该知道双方的单牌和双牌数量是一样的，
   如果是 双-单-双 这样出牌永远用不完，所以只能为 双-双-双
   每一轮对方减少一对双牌，因此先手胜
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
void solve()
{
	cin>>n;
	vector<int> a(n+1,0),b(n+1,0),cnt(n+1,0);
	bool flag=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cnt[a[i]]++;
		if(cnt[a[i]]==2) flag=1;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	if(!flag) cout<<"sha7dow"<<endl;
	else cout<<"shuishui"<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}