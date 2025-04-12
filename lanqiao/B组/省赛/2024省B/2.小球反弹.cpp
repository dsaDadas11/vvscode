/*
 * @Author: dsaDadas11
 * @Date: 2025-04-02 19:11:28
 * @LastEditTime: 2025-04-02 19:12:29
 * @Description: go for it!
 */
/*
 解题思路：
 首先反弹可以变为弹到下一个同样的正方形中，
 如果是从下边反弹就往下加长方形，如果是右边反弹就往右边加长方形，
 逐渐加到有n个x边长，m个y边长能到右下角的顶点，
 反弹的距离就是两倍的(nx*nx+my*my)，根据数学知识可以解出n,m
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
int x=343720,y=233333;
signed main()
{
    int fz=15*y,fm=17*x;
    int gg=gcd(fz,fm);
    fz/=gg;
    fm/=gg;
    int m=fm*y,n=fz*x;
    long double dis=sqrt(m*m+n*n)*2;
    cout<<fixed<<setprecision(2)<<dis<<endl;
    return 0;
}