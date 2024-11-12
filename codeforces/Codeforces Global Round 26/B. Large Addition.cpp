/*
 * @Author: dsaDadas11
 * @Date: 2024-11-07 11:03:58
 * @LastEditTime: 2024-11-07 22:46:59
 * @Description: go for it!
 */
/*
 解题思路：
 一个large数+一个large数，最后肯定会产生进位，并且个位的范围在[0,8]，其余位的范围因为进位在[1,9]
 然后我们模拟进位的反过程，看是否这个位向前一位借一位之后除以二还是小于5，那么是不行的，
 特判：
 首位，只能为1，因为借完位之后，如果首位不等于0的话，那么large的最高位一定小于5
 个位，因为没有后面的位数产生进位，因此不需要减1
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
	string x;
	cin>>x;
	int len=x.size();
	int t=0;
	for(int i=0;i<len;i++)
	{
		t=x[i]-'0';
		if(i==0)
		{
			if(t!=1) return cout<<"NO"<<endl,void();
		}
		else if(i==len-1)
		{
			if(t>=9) return cout<<"NO"<<endl,void();
			t=(t+10)/2;
			if(t<5) return cout<<"NO"<<endl,void();
		}
		else
		{
			if(t<1) return cout<<"NO"<<endl,void();
			t=(t+10-1)/2;
			if(t<5) return cout<<"NO"<<endl,void();
		}
	}
	cout<<"YES"<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}