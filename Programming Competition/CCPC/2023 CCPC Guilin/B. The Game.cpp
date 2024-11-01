/*
 * @Author: dsaDadas11
 * @Date: 2024-10-15 13:03:59
 * @LastEditTime: 2024-10-15 21:58:00
 * @Description: go for it!
 */
/*
 解题思路：
 题目大意：每将一个数加+1，就将最小的数删去，
 首先贪心的想：b的m个数必须与a中最大的m个数匹配，但是如果有a[i]>b[i],就无法修改，直接return -1
 然后再算需要操作的次数cnt，我们最大的操作次数也就为n-m，如果超过这个界限则不合法，直接return -1

 一旦cnt<n-m，那么操作就有冗余了，我们就得先从小的数往后面加，用multiset维护每次加给最小的数，
 s1维护前n-m个，s2维护后m个，如果操作后的x大于s2中最小的数，那么就将x和s2最小的数替换，然后将cnt-1(相当于进行了+1操作)
 如果冗余操作没进行完 s1就为空了，那也不合法，return -1

 处理完冗余操作后，我们就对a的后m个数进行操作，
 果有a[i]>b[i],就无法修改，直接return -1
 每次删除s1中的数，然后将a[i]+1,
 如果操作后a[i]<b[i]并且不能进行删除操作(s1为空)，那么不合法，直接return -1

 具体的看代码
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m;
int a[N],b[N];
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) cin>>b[i];
	sort(a+1,a+1+n);
	sort(b+1,b+1+m);
	int cnt=0;
	for(int i=1;i<=m;i++)
	{
		if(b[i]<a[n-m+i]) return cout<<"-1"<<endl,void();
		cnt+=b[i]-a[n-m+i];
	}
	if(cnt>n-m) return cout<<"-1"<<endl,void();
	multiset<int> s1,s2;
	for(int i=1;i<=n-m;i++) s1.insert(a[i]);
	for(int i=n-m+1;i<=n;i++) s2.insert(a[i]);
	vector<int> ans;
	int tmp=n-m;
	while(tmp-cnt>0)
	{
		if(s1.empty()) return cout<<"-1"<<endl,void();
		int x=*s1.begin();
		s1.erase(s1.begin());
		ans.push_back(x);
		x++;
		if(x>*s2.begin())
		{
			int x2=*s2.begin();
			s2.erase(s2.begin());
			s1.insert(x2);
			s2.insert(x);
			cnt--;
		}
		else s1.insert(x);
		if(s1.size()) s1.erase(s1.begin());
		else s2.erase(s2.begin());
		tmp--;
	}
	for(int i=1;i<=m;i++)
	{
		int x=*s2.begin();
		s2.erase(s2.begin());
		if(x>b[i]) return cout<<"-1"<<endl,void();
		while(x<b[i]&&s1.size())
		{
			ans.push_back(x);
			x++;
			s1.erase(s1.begin());
		}
		if(x<b[i]) return cout<<"-1"<<endl,void();
	}
	cout<<ans.size()<<endl;
	for(auto i:ans) cout<<i<<' ';
	cout<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}