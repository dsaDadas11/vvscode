/*
 * @Author: dsaDadas11
 * @Date: 2024-07-23 14:15:23
 * @LastEditTime: 2025-01-01 20:25:41
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=2e7+7;
constexpr int M=2e3+7;
int zz[N],pp[N];
void get_z(string s,int z[N])
{
	int len=s.size();
	s=' '+s;
	z[1]=len;
	for(int i=2,l=0,r=0;i<=len;i++)
	{
		if(i<=r) z[i]=min(z[i-l+1],r-i+1);
		while(s[z[i]+1]==s[i+z[i]]) z[i]++;
		if(i+z[i]-1>r) l=i,r=i+z[i]-1;
	}
}
void get_p(string s,int z[N],string t,int p[N])
{
	int lens=s.size();
	s=' '+s;
	int lent=t.size();
	t=' '+t;
	for(int i=1,l=0,r=0;i<=lent;i++)
	{
		if(i<=r) p[i]=min(z[i-l+1],r-i+1);
		while(s[p[i]+1]==t[i+p[i]]&&1+p[i]<=lens&&i+p[i]<=lent) p[i]++;
		if(i+p[i]-1>r) l=i,r=i+p[i]-1;
	}
}
void solve()
{
	string a,b;
	cin>>a>>b;
	get_z(b,zz);
	get_p(b,zz,a,pp);
	int ans1=0,ans2=0;
	for(int i=1;i<=b.size();i++)
	{
		ans1^=i*(zz[i]+1);
	}
	for(int i=1;i<=a.size();i++)
	{
		ans2^=i*(pp[i]+1);
	}
	cout<<ans1<<endl;
	cout<<ans2<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}

/*
详细版：
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=2e7+7;
constexpr int M=2e3+7;
string a,b;
int n,m;
int za[N],zb[N];
void get_zb()
{
    zb[1]=m;
    for(int i=2,l=1,r=0;i<=m;i++)
    {
        // 在盒内
        if(i<=r)
        {
            // 如果超过了盒子范围，暴力枚举
            if(zb[i-l+1]>=r-i+1)
            {
                zb[i]=r-i+1;
                while(b[1+zb[i]]==b[i+zb[i]]) zb[i]++;
            }
            // 否则直接用
            else
            {
                zb[i]=zb[i-l+1];
            }
        }
        // 在盒外
        else
        {
            while(b[1+zb[i]]==b[i+zb[i]]) zb[i]++;
        }
        
        // 更新l,r
        if(i+zb[i]-1>r)
        {
            r=i+zb[i]-1;
            l=i;
        }
    }
}
void get_za()
{
    for(int i=1,l=1,r=0;i<=n;i++)
    {
        // 在盒内
        if(i<=r)
        {
            // 如果超过了盒子范围，暴力枚举
            if(zb[i-l+1]>=r-i+1)
            {
                za[i]=r-i+1;
                while(1+za[i]<=m&&i+za[i]<=n&&b[1+za[i]]==a[i+za[i]]) za[i]++;
            }
            // 否则直接用
            else
            {
                za[i]=zb[i-l+1];
            }
        }
        // 在盒外
        else
        {
            while(1+za[i]<=m&&i+za[i]<=n&&b[1+za[i]]==a[i+za[i]]) za[i]++;
        }
        
        // 更新l,r
        if(i+za[i]-1>r)
        {
            r=i+za[i]-1;
            l=i;
        }
    }
}
void solve()
{
    cin>>a>>b;
    n=a.size(),m=b.size();
    a=' '+a,b=' '+b;
    get_zb();
    get_za();
    int ans1=0,ans2=0;
    for(int i=1;i<=m;i++)
    {
        ans1^=i*(zb[i]+1);
    }
    for(int i=1;i<=n;i++)
    {
        ans2^=i*(za[i]+1);
    }
    cout<<ans1<<endl;
    cout<<ans2<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}
*/