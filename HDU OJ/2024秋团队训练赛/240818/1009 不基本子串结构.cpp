/*
 * @Author: dsaDadas11
 * @Date: 2024-08-19 18:05:01
 * @LastEditTime: 2024-08-19 18:06:13
 * @Description: go for it!
 */
/*
 温馨提示：不能使用自然溢出
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
constexpr int mod=1e9+7;
int base1=29;
int base2=131;
int p1[N],haA1[N];
int p2[N],haA2[N];
int haB1[N],haB2[N];
string A,B;
void pre()
{
	p1[0]=1;
	for(int i=1;i<=1e6;i++)
	{
		p1[i]=(p1[i-1]*base1)%mod;
	}
	p2[0]=1;
	for(int i=1;i<=1e6;i++)
	{
		p2[i]=(p2[i-1]*base2)%mod;
	}
}
int getA1(int l,int r)
{
	return ((haA1[r]-haA1[l-1]*p1[r-l+1])%mod+mod)%mod;
}
int getA2(int l,int r)
{
	return ((haA2[r]-haA2[l-1]*p2[r-l+1])%mod+mod)%mod;
}
int getB1(int l,int r)
{
	return ((haB1[r]-haB1[l-1]*p1[r-l+1])%mod+mod)%mod;
}
int getB2(int l,int r)
{
	return ((haB2[r]-haB2[l-1]*p2[r-l+1])%mod+mod)%mod;
}
void solve()
{
	cin>>A>>B;
	if((int)A.size()>(int)B.size()) swap(A,B);
	int lenA=A.size();
	int lenB=B.size();
	string ta=A;
	string tb=B;
	A=' '+A;
	B=' '+B;
	// 双哈希
	for(int i=1;i<=lenA;i++)
	{
		haA1[i]=((haA1[i-1]*base1+A[i]-'a'+1)%mod+mod)%mod;
	}
	for(int i=1;i<=lenA;i++)
	{
		haA2[i]=((haA2[i-1]*base2+A[i]-'a'+1)%mod+mod)%mod;
	}
	for(int i=1;i<=lenB;i++)
	{
		haB1[i]=((haB1[i-1]*base1+B[i]-'a'+1)%mod+mod)%mod;
	}
	for(int i=1;i<=lenB;i++)
	{
		haB2[i]=((haB2[i-1]*base2+B[i]-'a'+1)%mod+mod)%mod;
	}
	// 查询A是否为B的子串
	int cnt=0;
	int hashA1=getA1(1,lenA);
	int hashA2=getA2(1,lenA);
	for(int i=1;i+lenA-1<=lenB;i++)
	{
		if(hashA1==getB1(i,i+lenA-1)&&hashA2==getB2(i,i+lenA-1)) cnt++;
		if(cnt>=2)
		{
			cout<<"-1"<<endl;
			return;
		}
	}
	if(cnt>=2)
	{
		cout<<"-1"<<endl;
		return;
	}
	// 如果B包含A 那么长度为B
	if(cnt)
	{
		cout<<lenB<<endl;
		return;
	}
	// 若成立，则找前后缀
	int l1=0,l2=0;
	int p1=0,p2=0;
	// 先找A的后缀为B的前缀
	for(int i=lenA;i>=1;i--)
	{
		if(getA1(i,lenA)==getB1(1,lenA-i+1)&&getA2(i,lenA)==getB2(1,lenA-i+1))
		{
			l1=max(l1,lenA-i+1);
			p1=lenA-i+1;
		}
	}
	// 再找B的后缀为A的前缀
	for(int i=lenB;i>=1;i--)
	{
		if(lenB-i+1>lenA) break;
		if(getB1(i,lenB)==getA1(1,lenB-i+1)&&getB2(i,lenB)==getA2(1,lenB-i+1))
		{
			l2=max(l2,lenB-i+1);
			p2=lenB-i+1;
		}
	}
	int ans=max(l1,l2);
	cout<<lenA+lenB-ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	pre();
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}