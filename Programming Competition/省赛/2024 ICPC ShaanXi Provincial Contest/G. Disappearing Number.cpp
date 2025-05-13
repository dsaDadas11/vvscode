/*
 * @Author: dsaDadas11
 * @Date: 2024-09-01 22:32:25
 * @LastEditTime: 2024-09-01 22:43:39
 * @Description: go for it!
 */
/*
 解题思路：
 这道题直接正向思维就好，然后从高位到低位遍历
 有两种情况：（假设这个位置的数为now，我们需要从now-1开始计算，然后用now的数遍历下一位）
 1.now-1包含x，那么这位数上的取值只有now-1种（包括0），并且后面的位置都是9种，相乘即可
 2.now-1不包含x,那么这位数上的取值有now种
 3.当我们想遍历到下一位时，我们当前的now不能为x，如果为x的话后面不管怎么取都是不合法的，所以直接break
 4.注意不能用pow，第一，pow的返回值是double 第二，pow会爆int
 5.000000....也是合法序列，所以最后答案+1
 最好再判断一下个位数的情况，虽然说不判断也能过，但是能被hack 比如 1 1 这个样例
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,x;
string s;
int quickpow(int x,int y)
{
	int ans=1;
	while(y)
	{
		if(y&1) ans*=x;
		x*=x;
		y>>=1;
	}
	return ans;
}
void solve()
{
	cin>>n>>x;
	s=to_string(n);
	int len=s.size();
	s=' '+s;
	int ans=0;
    if(len==1)
	{
		if(n>=x) cout<<n<<endl;
		else cout<<n+1<<endl;
		return;
	}
	for(int i=1;i<=len;i++)
	{
		int now=s[i]-'0';
		if(now-1>=x)
		{
			ans+=(now-1)*quickpow(9,len-i);
		}
		else
		{
			ans+=now*quickpow(9,len-i);
		}
		if(now==x)
		{
			break;
		}
	}
	cout<<ans+1<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}