/*
 * @Author: dsaDadas11
 * @Date: 2024-11-24 11:13:02
 * @LastEditTime: 2024-11-24 11:23:18
 * @Description: go for it!
 */
/*
 解题思路：
 我们用双指针找左右的最值端点，答案就是 ansr-ansl+1
 1.首先如何更新 ansl,ansr：
 区间[l,r]中 ansl一定要在a[l]和a[r]的左端重叠区间中，并且是最大值
 ansr一定要在a[l]和a[r]的右端重叠区间中，并且是最小值

 2.如何更新 l,r:
 当此区间的长度 len=r-l+1 大于 a[l],那么证明 l这个点可以从区间任意一点 i先扩展到 r再扩展到 l,则 l++
 r同理，r--
 如果 l,r都不满足条件说明区间内任意一点都不能及时扩展到这两个端点，因此无解，答案为 0
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
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int l=1,r=n;
	int ansl=1,ansr=n;
	int len;
	while(l<=r)
	{
		ansl=max(ansl,l-a[l]+1);
		ansl=max(ansl,r-a[r]+1);
		
		ansr=min(ansr,l+a[l]-1);
		ansr=min(ansr,r+a[r]-1);

		len=r-l+1;
		
		if(a[l]<len&&a[r]<len) return cout<<"0"<<endl,void();
		if(a[l]>=len) l++;
		if(a[r]>=len) r--;
	}
	cout<<max(0LL,ansr-ansl+1)<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}