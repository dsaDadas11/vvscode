/*
 * @Author: dsaDadas11
 * @Date: 2024-11-24 13:46:32
 * @LastEditTime: 2024-11-25 13:27:56
 * @Description: go for it!
 */
/*
 解题思路：
 首先我们可以想到将序列先预转化，然后通过前缀和O(1)查询
 但是得判断一下边界，
 假如 i这个点是通过转化来的，那么它会影响到另一个字符串的 i-1和 i+1，
 另一个字符串的 i-1和 i+1会影响这个字符串的 i-2,i,i+2
 因此我们需要特判一下 [l,l+1] 和 [r-1,r]
 但是如果 r-l+1<=3时会有重叠情况，并且 r-l+1==3时中间的那个字符可能能被另一个字符串转化过来，因此还需特判

 下午把莫队解法补一补
 莫队解法已补，在下面
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=2e5+7;
constexpr int M=2e3+7;
int n,q;
string s,t;
int sum[N];
bool vis_s[N],vis_t[N];
void solve()
{
	cin>>n;
	cin>>s>>t;

	for(int i=0;i<=n+3;i++)
	{
		vis_s[i]=vis_t[i]=0;
	}

	s=' '+s,t=' '+t;
	string s1=s,t1=t;
	// 先将s和t序列都转化
	for(int i=1;i<=n-2;i++)
	{
		if(s1[i]=='0'&&s1[i+2]=='0')
		{
			if(t1[i+1]!='1')
			{
				t1[i+1]='1';
				vis_t[i+1]=1; // t这一位从s转移过来
			}
		}
	}
	for(int i=1;i<=n-2;i++)
	{
		if(t1[i]=='1'&&t1[i+2]=='1')
		{
			if(s1[i+1]!='1')
			{
				s1[i+1]='1';
				vis_s[i+1]=1; // s这一位从t转移过来
			}
		}
	}
	
	// 计算答案前缀
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+(s1[i]=='1');
	}

	// 查询
	cin>>q;
	int l,r;
	while(q--)
	{
		cin>>l>>r;
		// 特判一下重叠的情况
		int res=0;
		if(r-l+1<=2)
		{
			for(int i=l;i<=r;i++)
			{
				if(s[i]=='1') res++;
			}
			cout<<res<<endl;
			continue;
		}
		else if(r-l+1==3)
		{
			// 特判三个点
			if(s1[l]=='1'&&vis_s[l]==0) res++;
			if(s1[r]=='1'&&vis_s[r]==0) res++;
			if(s1[l+1]=='1'&&vis_s[l+1]==0) res++;
			
			if(s1[l+1]=='1'&&vis_s[l+1])
			{
				if(!(vis_t[l]||vis_t[r])) res++;
			}
			cout<<res<<endl;
			continue;
		}

		int ans=sum[r]-sum[l-1];
		int cnt=0; // 不能成立的 1
		// 判断一下前两位
		if(s1[l]=='1'&&vis_s[l]) cnt++;
		if(s1[l+1]=='1'&&vis_s[l+1])
		{
			if(vis_t[l])
			{
				cnt++;
			}
		}

		// 判断后两位
		if(s1[r]=='1'&&vis_s[r]) cnt++;
		if(s1[r-1]=='1'&&vis_s[r-1])
		{
			if(vis_t[r])
			{
				cnt++;
			}
		}
		cout<<ans-cnt<<endl;
	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}


/*
 莫队写法：
 也是需要特判[l,l+2] [r-2,r]
 用草稿列一下l的情况就行，r是对称的

#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m,len;
string s,t;
string s1,t1;
bool vis[N];
struct op
{
	int idx;
	int l,r;
	bool operator<(const op& that) const
	{
		if((l-1)/len!=(that.l-1)/len) return l<that.l;
		if(((l-1)/len+1)&1) return r<that.r;
		return r>that.r;
	}
}q[N];
int ans[N];
int res;
void add(int x,bool sign) // 0 l  1 r
{
	if(s1[x]=='1') res++;
	vis[x]=1;
	if(sign==0)
	{
		if(vis[x+2])
		{
			if(s1[x]=='0'&&s1[x+2]=='0')
			{
				t1[x+1]='1';
			}
			if(t1[x]=='1'&&t1[x+2]=='1')
			{
				if(s1[x+1]=='0') res++;
				s1[x+1]='1';
			}
		}
		if(vis[x+3])
		{
			if(t1[x+1]=='1'&&t1[x+3]=='1')
			{
				if(s1[x+2]=='0') res++;
				s1[x+2]='1';
			}
		}
	}
	else
	{
		if(x-2>=1)
		if(vis[x-2])
		{
			if(s1[x]=='0'&&s1[x-2]=='0')
			{
				t1[x-1]='1';
			}
			if(t1[x]=='1'&&t1[x-2]=='1')
			{
				if(s1[x-1]=='0') res++;
				s1[x-1]='1';
			}
		}
		
		if(x-3>=1)
		if(vis[x-3])
		{
			if(t1[x-1]=='1'&&t1[x-3]=='1')
			{
				if(s1[x-2]=='0') res++;
				s1[x-2]='1';
			}
		}
	}
}
void del(int x,bool sign)
{
	if(s1[x]=='1') res--;
	s1[x]=s[x],t1[x]=t[x];
	vis[x]=0;
	if(sign==0)
	{
		if(vis[x+1])
		{
			if(s1[x+1]=='1'&&s[x+1]=='0') res--;
			s1[x+1]=s[x+1],t1[x+1]=t[x+1];
		}
		if(vis[x+3])
		{
			if(s1[x+1]=='0'&&s1[x+3]=='0')
			{
				t1[x+2]='1';
			}
			if(t1[x+1]=='0'&&s1[x+2]=='1'&&s[x+2]=='0')
			{
				s1[x+2]='0';
				res--;
			}
		}
	}
	else
	{
		if(x-1>=1)
		if(vis[x-1])
		{
			if(s1[x-1]=='1'&&s[x-1]=='0') res--;
			s1[x-1]=s[x-1],t1[x-1]=t[x-1];
		}
		
		if(x-3>=1)
		if(vis[x-3])
		{
			if(s1[x-1]=='0'&&s1[x-3]=='0')
			{
				t1[x-2]='1';
			}
			if(t1[x-1]=='0'&&s1[x-2]=='1'&&s[x-2]=='0')
			{
				s1[x-2]='0';
				res--;
			}
		}
	}
}
void solve()
{
	cin>>n;
	cin>>s>>t;
	res=0;
	len=sqrt(n);
	for(int i=0;i<=n+5;i++) vis[i]=0;
	
	s=' '+s,t=' '+t;
	s1=s,t1=t;
	
	cin>>m;
	int l,r;
	for(int i=1;i<=m;i++)
	{
		cin>>l>>r;
		q[i]={i,l,r};
	}
	sort(q+1,q+1+m);
	
	for(int i=1,l=1,r=0;i<=m;i++)
	{
		while(q[i].l<l) add(--l,0);
		while(r<q[i].r) add(++r,1);
		while(l<q[i].l) del(l++,0);
		while(q[i].r<r) del(r--,1);
		
		ans[q[i].idx]=res;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<endl;
	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}
*/