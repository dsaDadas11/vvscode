/*
 * @Author: dsaDadas11
 * @Date: 2024-09-03 19:37:37
 * @LastEditTime: 2025-07-25 16:14:36
 * @Description: go for it!
 */
/*
 需要注意的是，数位dp解决的是数字出现个数的问题，比如11出现两个1
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int ten[20],dp[20];
int cnta[20],cntb[20];
int num[20];
void init()
{
	ten[0]=1;
	for(int i=1;i<=15;i++)
	{
		dp[i]=i*ten[i-1];
		ten[i]=ten[i-1]*10;
	}
}
void query(int x,int cnt[20])
{
	int len=0;
	while(x)
	{
		num[++len]=x%10;
		x/=10;
	}
	for(int i=len;i>=1;i--)
	{
		for(int j=0;j<=9;j++) cnt[j]+=num[i]*dp[i-1]; // 在后i-1位出现的个数
		for(int j=0;j<num[i];j++) cnt[j]+=ten[i-1]; // 在数num[i]以下，后面的位数可以随便取，就是10^(i-1)
		int num2=0;
		for(int j=i-1;j>=1;j--) num2=num2*10+num[j];
		cnt[num[i]]+=num2+1; // 处理数num[i]的种类，比如1234 第一位num[1]=1,那么就能有1234+1中(不要忽略0000)
		cnt[0]-=ten[i-1]; // 处理前导零
	}
}
void solve()
{
	int a,b;
	cin>>a>>b;
	// 差分区间 [1,a-1] [1,b]
	query(a-1,cnta),query(b,cntb);
	for(int i=0;i<=9;i++) cout<<cntb[i]-cnta[i]<<' ';
	cout<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	init();
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}

/*

dfs写法，只是不知道为什么sum会小于等于10。。。

#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int now;
int num[20];
int dp[20][20];
int dfs(int pos,int sum,bool lead,bool limit)
{
	int ans=0;
	if(pos==0) return sum;
	if(!lead&&!limit&&dp[pos][sum]!=-1) return dp[pos][sum];
	int up=(limit?num[pos]:9);
	for(int i=0;i<=up;i++)
	{
		if(i==0&&lead) ans+=dfs(pos-1,sum,1,limit&&(i==up));
		else if(i==now) ans+=dfs(pos-1,sum+1,0,limit&&(i==up));
		else ans+=dfs(pos-1,sum,0,limit&&(i==up));
	}
	if(!lead&&!limit) dp[pos][sum]=ans;
	return ans;
}
int query(int x)
{
	int len=0;
	while(x)
	{
		num[++len]=x%10;
		x/=10;
	}
	memset(dp,-1,sizeof dp);
	return dfs(len,0,1,1);
}
void solve()
{
	int a,b;
	cin>>a>>b;
	for(int i=0;i<=9;i++)
	{
		now=i;
		cout<<query(b)-query(a-1)<<' ';
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

20250725 重新写了一遍，发现 cnt即上面的 sum最多只会迭代 12次，不是所有 dfs累加
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int l,r;
int f[14][14];
int a[14];
int digit;
int dfs(int pos,bool limit,bool lead0,int cnt)
{
    if(pos==0) return cnt;
    if(!limit&&!lead0&&f[pos][cnt]!=-1) return f[pos][cnt];

    int up=limit?a[pos]:9;
    int res=0;
    for(int i=0;i<=up;i++)
    {
        int tmp=cnt+(i==digit);
        if(lead0&&i==0) tmp=0;
        res+=dfs(pos-1,limit&&i==up,lead0&&i==0,tmp);
    }
    if(!limit&&!lead0) f[pos][cnt]=res;
    return res;
}
int calc(int x)
{
    int len=0;
    while(x)
    {
        a[++len]=x%10;
        x/=10;
    }
    return dfs(len,1,1,0);
}
void solve()
{
    memset(f,-1,sizeof f);
    cin>>l>>r;
    for(int i=0;i<=9;i++)
    {
        digit=i;
        cout<<calc(r)-calc(l-1)<<' ';
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
*/