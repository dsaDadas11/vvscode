/*
 * @Author: dsaDadas11
 * @Date: 2024-01-17 21:53:38
 * @LastEditTime: 2024-01-17 21:55:21
 * @Description: go for it!
 */
/*
1.小蓝与钥匙

答案：1286583532342313400

小蓝是幼儿园的老师，他的班上有28 个孩子，今天他和孩子们一起进行了一个游戏。
小蓝所在的学校是奇宿制学校，28 个孩子分别有一个自己的房间，每个房间对应一把钥匙，每把钥匙只能打开自己的门。现在小蓝让这 28 个孩子分别将自己宿舍的钥匙上交，再把这28 把钥匙随机打乱分给每个孩子一把钥匙，有28!=28 x 27 × …•x 1种分配方案。小蓝想知道这些方案中，有多少种方案怡有一半的孩子被分到自己房间的钥匙（即有14 个孩子分到的是自己房间的钥匙，有14 个孩子分到的不是自己房间的钥匙）。

解题思路：

是一个全错排问题，在28个里面任意选择14个 C（28，14），乘以全错排D（14）；

全错排公式 D(n)=(n-1)*(D(n-1)+D(n-2))

计算C(28,14)时，可采用公式 C(n,k)=C(n-1,k-1)+C(n-1,k) 计算；
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
const int N=1e6+7;
const int M=2e3+7;
int c(int n,int k)
{
	if(k==0||k==n) return 1;
	else return c(n-1,k-1)+c(n-1,k);
}
int d(int n)
{
	if(n==0||n==1) return 0;
	else if(n==2) return 1;
	else return (n-1)*(d(n-1)+d(n-2));
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cout<<c(28,14)*d(14)<<endl;
	return 0;
}