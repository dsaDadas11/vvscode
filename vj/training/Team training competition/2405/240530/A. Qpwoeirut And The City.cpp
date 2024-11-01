/*
 * @Author: dsaDadas11
 * @Date: 2024-05-30 20:46:40
 * @LastEditTime: 2024-05-30 20:50:35
 * @Description: go for it!
 */
/*
解题思路：
1.如果n为奇数 直接从2开始间隔2个遍历就行
2.如果n为偶数 设建筑 a b c d e f
  (1)我们可以从2开始间隔2个取 b d 
  (2)也可以从3开始间隔2个取 c e
  (3)也可以中间空着不取(也就是(1)和(2)的混合) b e
  因此我们可以用前缀和记录一下当前位置需要的总砖头数，在遍历情况(3)时可以用到
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int er[N],san[N];
int n,ans;
int a[N];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	ans=1e18;
	for(int i=1;i<=n;i++) er[i]=0,san[i]=0;
	int d1,d2;
	if(n%2)
	{
		ans=0;
		for(int i=2;i<n;i+=2)
		{
			if(a[i]>a[i-1]&&a[i]>a[i+1]) continue;
			d1=a[i-1]-a[i]+1;
			d2=a[i+1]-a[i]+1;
			ans+=max(d1,d2);
		}
	}
	else
	{
		int res1=0,res2=0;
		for(int i=2;i<n;i+=2)
		{
			if(a[i]>a[i-1]&&a[i]>a[i+1])
			{
				er[i]=er[i-2];
				res1=max(res1,er[i]);
				continue;
			}
			d1=a[i-1]-a[i]+1;
			d2=a[i+1]-a[i]+1;
			er[i]=er[i-2]+max(d1,d2);
			res1=max(res1,er[i]);
		}
		for(int i=3;i<n;i+=2)
		{
			if(a[i]>a[i-1]&&a[i]>a[i+1])
			{
				san[i]=san[i-2];
				res2=max(res2,san[i]);
				continue;
			}
			d1=a[i-1]-a[i]+1;
			d2=a[i+1]-a[i]+1;
			san[i]=san[i-2]+max(d1,d2);
			res2=max(res2,san[i]);
		}
		ans=min({ans,res1,res2});
	//	cout<<res1<<' '<<res2<<endl;
		for(int i=2;i<n;i+=2)
		{
			ans=min(ans,er[i]+res2-san[i+1]);
		}
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