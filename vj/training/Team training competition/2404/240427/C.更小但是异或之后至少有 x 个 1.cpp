/*
 * @Author: dsaDadas11
 * @Date: 2024-04-28 18:16:49
 * @LastEditTime: 2024-04-28 18:25:16
 * @Description: go for it!
 */
/*
本题思路：
1.如果从后往前找第x位为 1 ，那么只要将第x位及后面的位取反即可
2.如果从后往前找第x位为 0 ，那么按第一点的做法就会使得b>a了，
  此时我们需要继续往前找到 1 ，然后将此位变为 0 ，后面的就按贪心做了，
  也就是根据位数来判定是否能取 1 
3.特判：
    (1) a的位数小于x
    (2) 当a的长度为1且a[0]=='0'且x==1
    (3) 前导0
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
	string a;
	int x;
	cin>>a>>x;
	int len=a.size();
	if(len<x)
	{
		cout<<"-1"<<endl;
		return;
	}
	if(len==1)
	{
		if(a[0]=='0')
		{
			if(x==0) cout<<'0'<<endl;
			else cout<<"-1"<<endl;
		}
		else
		{
			if(x==0) cout<<'1'<<endl;
			else cout<<'0'<<endl;
		}
		return;
	}
	if(x==0)
	{
		cout<<a<<endl;
		return;
	}
	string ans="";
	if(a[len-x]=='1')
	{
		for(int i=0;i<len-x;i++)
		{
			ans.push_back(a[i]);
		}
		for(int i=len-x;i<len;i++)
		{
			if(a[i]=='1') ans.push_back('0');
			else ans.push_back('1');
		}
	}
	else
	{
		int pos=0;
		for(int i=len-x-1;i>=0;i--)
		{
			if(a[i]=='1')
			{
				pos=i;
				break;
			}
		}
		for(int i=0;i<pos;i++)
		{
			ans.push_back(a[i]);
		}
		ans.push_back('0');
		x--;
		int cnt=len-pos-1;
		for(int i=pos+1;i<len;i++)
		{
			if(a[i]=='1'&&cnt>x)
			{
				cnt--;
				ans.push_back('1');
			}
			else if(a[i]=='1')
			{
				ans.push_back('0');
				x--;
				cnt--;
			}
			else
			{
				ans.push_back('1');
				x--;
				cnt--;
			}
		}
	}
	bool vis=0;
	for(int i=0;i<ans.size();i++)
	{
		if(ans[i]=='1') vis=1;
		if(vis) cout<<ans[i];
	}
	cout<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}