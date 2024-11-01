/*
 * @Author: dsaDadas11
 * @Date: 2024-09-23 12:40:19
 * @LastEditTime: 2024-09-23 18:13:23
 * @Description: go for it!
 */
/*
 解题思路：
 首先读题不要读假，题目中随机一个timer时可以与之前的timer相同，也就是随到任何一个数的概率为1/t，然后求罚时最小的期望
 其次怎么算？
 我们设一个值c，当小于等于c时我们可以直接减到0，否则继续随机，每当随到小于等于c的数的期望为(1/t)*c*(c+1)/2，那么我们可以设p为c/t，s为(c+1)/2，
 那么期望表达式为E=s*p+(s+1)*(1-p)*p+(s+2)*(1-p)^2*p+...+(s+n)*(1-p)^n*p
 其中n趋于正无穷，我们只需要用等比数列求和，错位相减和求极限就能求出E的最后表达式为E=(c-1)/2+t/c，这是一个对勾函数，函数的最小值在根号2t取得，
 注意我们只能取整数，所以可能有两种情况：向下取整，向上取整，判断一下哪个更小就好了
 不过需要注意取模，可能会出现负数，所以要+mod再%mod
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int t;
void solve()
{
	cin>>t;
	int c=sqrt(2*t);
	int c1=0;
	if(c*c!=2*t) c1=c+1;
	int fenzi=c*c-c+2*t;
	int fenmu=2*c;
	int fenzi1=c1*c1-c1+2*t;
	int fenmu1=2*c1;
	int tt=__gcd(fenzi,fenmu);
	fenzi/=tt,fenmu/=tt;
	if(c1!=0)
	{
		int tt1=__gcd(fenzi1,fenmu1);
		fenzi1/=tt1,fenmu1/=tt1;
		if(fenzi*fenmu1<fenmu*fenzi1)
		{
			cout<<fenzi<<' '<<fenmu<<endl;
		}
		else
		{
			cout<<fenzi1<<' '<<fenmu1<<endl;
		}
	}
	else cout<<fenzi<<' '<<fenmu<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}