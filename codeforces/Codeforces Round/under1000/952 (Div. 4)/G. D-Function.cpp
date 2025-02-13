/*
 * @Author: dsaDadas11
 * @Date: 2024-11-10 21:41:54
 * @LastEditTime: 2024-11-10 21:59:47
 * @Description: go for it!
 */
/*
 解题思路：
 1.当k>=10时改变了数位，是肯定不行的，因此答案为0
  因为每当进一位就相当于减少了9 (进一位+1,当前位清零-10，即最终-9)

 2.当k<10时
  我们单独看每一位：每一位的种类数为[9/k]+1 (包括0)，首位为 [9/k] (不能为0)
  对于10^i <= n < 10^i
  方案数为：9/k*(9/k+1)^i-1
  因此对10^l <= n < 10^r 可进行等比数列求和，最后结果为：
  (9/k+1)^r-(9/k+1)^l
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
constexpr int mod=1e9+7;
int l,r,k;
int qpow(int x,int y)
{
	int ans=1;
	while(y)
	{
		if(y&1) ans=(ans*x)%mod;
		x=(x*x)%mod;
		y>>=1;
	}
	return ans;
}
void solve()
{
	cin>>l>>r>>k;
	if(k>=10) return cout<<"0"<<endl,void();
	int t=9/k;
	cout<<((qpow(t+1,r)-qpow(t+1,l))%mod+mod)%mod<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}