/*
 * @Author: dsaDadas11
 * @Date: 2024-09-26 22:39:17
 * @LastEditTime: 2024-09-26 22:46:59
 * @Description: go for it!
 */
/*
 解题思路：
 这道题的意思就是找到一个长度 k,能够使得从数组中用 k来划分出的所有子数组都能够有相同的或运算和
 这类题一般都是用二分+数位记录
 一、我们想想为什么能用二分呢？
 1.当长度k不合法时，长度k-1更不会合法，因为当子数组的范围变小，那么二进制的情况肯定多种多样
 2.当长度k合法时，长度k+1肯定合法 (看样例看出来的...)
 二、怎么数位记录？
 我们可以模拟或运算来记录二进制中的1，0个数,
 当cnt1个数大于0，那么cnt0肯定为0，如果cnt1变0，cnt0为1了，我们需要记录cnt1的个数和cnt0的bool值就可以，
 但是最后二进制比较的时候只能都用bool值比较,因为二进制只有0和1，是不看cnt的个数的(不这样连样例都过不去)
 我们先存1-mid的二进制，然后往后双指针模拟就可以了
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e5+7;
constexpr int M=2e3+7;
int n;
int a[N];
int cnt1[37],cnt0[37]; // 记录每个数位上的1，0个数
int ycnt1[37],ycnt0[37]; // 最原始的1,0个数
bool check(int mid)
{
	for(int i=0;i<=25;i++)
	{
		cnt0[i]=cnt1[i]=0;
		ycnt0[i]=ycnt1[i]=0;
	}
	// 先处理1-mid的二进制
	for(int i=1;i<=mid;i++)
	{
		int t=a[i];
		vector<int> v;
		while(t)
		{
			v.push_back(t&1);
			t>>=1;
		}
		//reverse(v.begin(),v.end());
		int len=v.size();
		for(int i=0;i<len;i++)
		{
			if(v[i]==1) cnt1[i]++,ycnt1[i]++; //第i位的1加
		}
	}
	for(int i=0;i<=19;i++)
	{
		if(cnt1[i]==0)
		{
			cnt0[i]=1;
			ycnt0[i]=1;
		}
		//else cnt0[i]=-1,ycnt0[i]=-1;
	}
	// 双指针处理1-n
	for(int i=2;i+mid-1<=n;i++)
	{
		// 先把左边去除
		int t=a[i-1];
		vector<int> v;
		while(t)
		{
			v.push_back(t&1);
			t>>=1;
		}
		//reverse(v.begin(),v.end());
		int len=v.size();
		for(int i=0;i<len;i++)
		{
			if(v[i]==1)
			{
				cnt1[i]--; //第i位的1减
				if(cnt1[i]==0) cnt0[i]=1; // 没有1了这一位就成0了
			}
		}
		// 再把右端点加上
		t=a[i+mid-1];
		v.clear();
		while(t)
		{
			v.push_back(t&1);
			t>>=1;
		}
		//reverse(v.begin(),v.end());
		len=v.size();
		for(int i=0;i<len;i++)
		{
			if(v[i]==1)
			{
				cnt1[i]++;
				if(cnt1[i]==1)
				{
					cnt0[i]=0; // 有1就没0了
				}
			}
		}
		// 判断一下
		for(int i=0;i<=19;i++)
		{
			if((bool)cnt1[i]!=(bool)ycnt1[i]) return 0;
			if((bool)cnt0[i]!=(bool)ycnt0[i]) return 0;
		}
	}
	return 1;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int l=1,r=n;
	while(l<r) //尽量找小的
	{
		int mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	cout<<l<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}