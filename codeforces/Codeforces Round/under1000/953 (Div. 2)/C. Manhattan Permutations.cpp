/*
 * @Author: dsaDadas11
 * @Date: 2024-11-23 18:21:31
 * @LastEditTime: 2024-11-23 18:27:29
 * @Description: go for it!
 */
/*
 解题思路：
 我们可以的出逆序是最大的值，如果这个值小于k的话无解，
 并且排序是将两个位置互换，因此贡献不会为奇数
 当我们用原本递增的顺序去交换 i 和 j 的顺序时，得出的贡献就是 2*abs(i-j)
 因此我们从1开始遍历，往后面找一个位置能符合条件，但是位置换过之后就不能再换了，因此每次要将后面的位置给除去
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,k,j;
void solve()
{
	cin>>n>>k;
	int sum=0;
	int cnt=1;
	vector<int> ans(n+1);
	for(int i=n;i>=1;i--)
	{
		sum+=abs(i-cnt);
		ans[cnt]=cnt;
		cnt++;
	}
	if(sum<k) return cout<<"No"<<endl,void();
	if(k%2) return cout<<"No"<<endl,void();
	k/=2;
	for(int i=1;i<=n;i++)
	{
		j=min(i+k,n-i+1);
		swap(ans[i],ans[j]);
		k-=abs(j-i);
		if(k==0) break;
	}
	cout<<"Yes"<<endl;
	for(int i=1;i<=n;i++) cout<<ans[i]<<' ';
	cout<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}