/*
 * @Author: dsaDadas11
 * @Date: 2024-12-05 23:53:38
 * @LastEditTime: 2024-12-06 22:25:02
 * @Description: go for it!
 */
/*
 解题思路：
 一开始以为是 n方 
 想到了只能跑 10次，在外面加个循环还是不行，
 还是得用冒泡排序的思想模拟
 因为每个数最多只能往前转移 10次，因此时间复杂度为 O(10n)
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
string s;
int num[N];
void solve()
{
	cin>>s;
	int n=s.size();
	s=' '+s;
	for(int i=1;i<=n;i++)
	{
		num[i]=s[i]-'0';
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=i;j>=2;j--)
		{
			if(num[j]==0) break;
			if(num[j]<=num[j-1]+1) break;
			num[j]--;
			swap(num[j],num[j-1]);
		}
	}
	for(int i=1;i<=n;i++) cout<<num[i];
	cout<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}