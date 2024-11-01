/*
 * @Author: dsaDadas11
 * @Date: 2024-07-20 17:38:03
 * @LastEditTime: 2024-07-20 18:02:35
 * @Description: go for it!
 */
/*
  这道题的答案就是 路径最大值-路径最小值+1(沿主对角线对称时两边路径相等，算一条)
  而路径最大值-路径最小值就是计算(x1,y1)和(x2,y2)包含的交点数目(每个交点差值+1)
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
	int x1,x2,y1,y2;
	cin>>x1>>y1>>x2>>y2;
	cout<<(x2-x1)*(y2-y1)+1<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}