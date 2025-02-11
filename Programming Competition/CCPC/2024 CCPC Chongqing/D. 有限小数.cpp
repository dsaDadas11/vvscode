/*
 * @Author: dsaDadas11
 * @Date: 2025-01-13 14:48:00
 * @LastEditTime: 2025-01-16 14:11:02
 * @Description: go for it!
 */
/*
 解题思路：
 题目大意：a/b + c/d 要能除尽，a,b已知，求 c 最小值
 当一个分数为有限小数时（即能除尽），那么这个分数的分母只含 2,5 两个因数
 因此，当 b 只含 2,5 时 直接 c=0 d=1 即可
 其他情况下我们设 b = p * 2i * 5j (2i,5j皆为 2,5次方，p为素数)
 d = p * 2ii * 5jj
 那么将两分数相加可得 (a*2ii*5jj + c*2i*5j) / (p*(2I)*(5J)) (I=i+ii,J=j+jj)
 那么要能除尽，即 (a*2ii*5jj + c*2i*5j) 同余 0 (mod p)
 同余式左边可化为 (a*(d/p) + c*(b/p))
 那么同余式即为 c*(b/p) 同余 -a*(d/p) (mod p)
 那么就化为 ax 同余 b (mod m) 的形式了
 因为 gcd(b/p,p)=1 ,因此肯定有 gcd(b/p,p)整除 -a*(d/p)
 因此我们先用扩展欧几里得算出 x*(b/p) 同余 1 (mod p) 的 x
 那么 c=x*(-a*(d/p)) 注意不能为负数，因此要 (%p+p)%p


 其实 (a*2ii*5jj + c*2i*5j) 同余 0 (mod p) 这一步的等式就有解了，
 我们可以直接根据这个式子解出 c
 但是不知道为什么 ansc能算出负数。。。再取模一下就对了
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
constexpr int inf=1e9;
int exgcd(int a,int b,int &x,int &y)
{
	if(b==0)
	{
		x=1,y=0;
		return a;
	}
	int x1,y1,d;
	d=exgcd(b,a%b,x1,y1);
	x=y1;
	y=x1-(a/b)*y1;
	return d;
}
int p5[37],p2[37];
void init()
{
	p2[0]=p5[0]=1;
	for(int i=1;i<=32;i++)
	{
		p2[i]=p2[i-1]*2;
	}
	for(int i=1;i<=17;i++)
	{
		p5[i]=p5[i-1]*5;
	}
}
void solve()
{
	int a,b;
	cin>>a>>b;
	int p=b;
	while(p%5==0) p/=5;
	while(p%2==0) p/=2;
	if(p==1) return cout<<"0 1"<<endl,void();
	int c=inf,d;
	for(int i=0;i<=30;i++)
	{
		for(int j=0;j<=13;j++)
		{
			int cur_d=p2[i]*p5[j];  // d/p
			if(cur_d*p>inf) break;
			int tmp=(-(a*cur_d)%p+p)%p;
			int cur_x,cur_y;
			exgcd(b/p,p,cur_x,cur_y);
			cur_x=((cur_x*tmp)%p+p)%p; // c
			if(cur_x<c)
			{
				c=cur_x;
				d=cur_d*p;
			}
		}
	}
	cout<<c<<' '<<d<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	init();
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}

/*
 更简单的代码
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
constexpr int inf=1e9;
int a,b;
int exgcd(int a,int b,int &x,int &y)
{
	if(b==0)
	{
		x=1,y=0;
		return a;
	}
	int x1,y1,d;
	d=exgcd(b,a%b,x1,y1);
	x=y1;
	y=x1-(a/b)*y1;
	return d;
}
int p2[40],p5[30];
void init()
{
    p2[0]=p5[0]=1;
    for(int i=1;i<=30;i++)
    {
        p2[i]=p2[i-1]*2;
    }
    for(int i=1;i<=13;i++)
    {
        p5[i]=p5[i-1]*5;
    }
}
void solve()
{
    cin>>a>>b;
    int p=b;
    while(p%5==0) p/=5;
    while(p%2==0) p/=2;
    int yu=b/p;
    if(p==1) return cout<<"0 1"<<endl,void();
    int c=1e18,d=1;
    for(int i=0;i<=30;i++)
    {
        for(int j=0;j<=13;j++)
        {
            int D=p2[i]*p5[j];
            if(D>inf) break;
            if(D*p>inf) break;
            D=((-D*a%p)%p+p)%p;
            int x,y;
            exgcd(yu,p,x,y);
            int ansc=x*D%p;
            ansc=(ansc%p+p)%p;
            int dd=p2[i]*p5[j]*p;
            if(ansc<c)
            {
                c=ansc;
                d=dd;
            }
        }
    }
    cout<<c<<' '<<d<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}

*/