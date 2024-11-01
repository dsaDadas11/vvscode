/*
 * @Author: dsaDadas11
 * @Date: 2024-08-14 15:10:04
 * @LastEditTime: 2024-08-14 15:12:37
 * @Description: go for it!
 */
/*
 解题思路：首先将数列排成前面n-1个1,第n位为s-n+1
 所以这段数列的子数列和不可能在[n,s-n]之间
 令k=n,易得s-k也在区间中
 最后只需要判断s-n是否大于等于n即可
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,s;
void solve()
{
	cin>>n>>s;
	if(s<2*n)
	{
		cout<<"NO"<<endl;
		return;
	}
	cout<<"YES"<<endl;
	for(int i=1;i<n;i++) cout<<"1 ";
	cout<<s-n+1<<endl;
	cout<<n<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}