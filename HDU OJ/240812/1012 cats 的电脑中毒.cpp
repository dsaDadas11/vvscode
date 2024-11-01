/*
 * @Author: dsaDadas11
 * @Date: 2024-08-13 15:44:14
 * @LastEditTime: 2024-08-13 16:05:38
 * @Description: go for it!
 */
/*
 解题思路：设两个字符串S1,S2有num位不相同
 那么他们要变化为最远的串，我们设为字符串tar
 若S1i=S2i,那么tar串与S1i和S2i都不相同(即有n-num位)
 不相同的情况tar串就各取中间值 num/2(num为偶) (num+1)/2和(num-1)/2(num为奇) //必须化为能整除的形式
 那么最坏情况下：
 当num为奇数：ans=n-num+(num-1)/2=n-(num+1)/2
 当num为偶数：ans=n-num+num/2=n-num/2
 可统一化为：ans=n-num+(num-1)/2=n-(num+1)/2
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
string t1,t2,t3;
int dif(string x,string y)
{
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		if(x[i]!=y[i]) cnt++;
	}
	return cnt;
}
void solve()
{
	cin>>n;
	cin>>t1>>t2>>t3;
	int d=max({dif(t1,t2),dif(t2,t3),dif(t1,t3)});
	cout<<n-(d+1)/2<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}