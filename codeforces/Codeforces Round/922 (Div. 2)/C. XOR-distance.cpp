/*
 * @Author: dsaDadas11
 * @Date: 2024-01-15 17:40:03
 * @LastEditTime: 2024-11-25 22:28:49
 * @Description: go for it!
 */
/*
 解题思路：
 24级第二次新生赛的题，虽然 1400加上之前做过，但还是不会做 5_5

 首先，可以看出当a,b的二进制位上数字相同，那么异或不会改变结果，因此将 r此位置为 0即可
 其次，假设 a<b,我们可以将b的第一位 1(此时a的这一位肯定为 0) 异或成 1,(此时还是将 r此位置为 0)
 然后后面只需要异或修改 a的值,在不超过范围的条件下，尽可能的让异或后 a的位置尽可能的置 1
 如果 a该位为 1，那么 r此位置 0
 如果 a该位为 0，那么 r此位置 1
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
void solve()
{
	int a,b,r; cin>>a>>b>>r;
	int x1=0,x2=0;
	if(a<b) swap(a,b);
	for(int i=60;i>=0;i--)
	{
		int t=1ll<<i;
		if(x1+t>r) continue;
		if(abs((a^t)-(b^t))<abs(a-b))
			x1+=t;
	}
	for(int i=60;i>=0;i--)
	{
		int t=1ll<<i;
		if(x2+t>r) continue;
		if((a^t)<(b^t)) continue;
		if(abs((a^t)-(b^t))<abs(a-b))
			x2+=t;
	}
	cout<<min(abs((a^x1)-(b^x1)),abs((a^x2)-(b^x2)))<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}

/*
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int a,b,r;
void solve()
{
	cin>>a>>b>>r;
	if(a>b) swap(a,b);
	bool st=0;
	for(int i=60;i>=0;i--)
	{
		if(((a>>i)&1)==((b>>i)&1)) continue;
		if(!st)
		{
			st=1;
			continue;
		}
		if(((a>>i)&1)==0&&(1LL<<i)<=r)
		{
			r-=(1LL<<i);
			a^=(1LL<<i);
			b^=(1LL<<i);
		}
	}
	cout<<b-a<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}
*/