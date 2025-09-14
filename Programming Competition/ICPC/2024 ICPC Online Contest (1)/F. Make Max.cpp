/*
 * @Author: dsaDadas11
 * @Date: 2024-09-15 21:56:53
 * @LastEditTime: 2025-09-02 12:26:18
 * @Description: go for it!
 */
/*
 解题思路：
 这道题的意思是求每个数的区间唯一最大值的范围,并且这个范围不能与其他数区间重合
 (因为每个区间中的长度就是区间里面的数可以变化为最大的数的操作数，但不包括那个最大的数，所以是r[i]-l[i])
 比如 1 2 3 3 4   第三个数的区间范围为[1,3]
 当我们用单调栈找l[i]和r[i]时要注意区间不能重合，要么l[i]不重合要么r[i]不重合，这样才能保证区间的唯一性
 hack：1 9 1 1 9
 下面有更简单的方法
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
int a[N];
stack<int> st; // 位置
// 找区间内唯一最大值
int l[N],r[N];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	st.push(0);
	for(int i=1;i<=n;i++)
	{
		while(st.size()>1&&a[st.top()]<a[i]) st.pop();
		l[i]=st.top()+1;
		st.push(i);
	}
	while(!st.empty()) st.pop();
	st.push(n+1);
	a[n+1]=0;
	for(int i=n;i>=1;i--)
	{
		while(st.size()>1&&a[st.top()]<a[i]) st.pop();
		r[i]=st.top()-1;
		if(a[r[i]+1]==a[i]) r[i]=i;
		st.push(i);
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		ans+=r[i]-l[i];
	}
	cout<<ans<<endl;
	while(!st.empty()) st.pop();
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}

/*
 l不重合，r重合的情况
    cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	st.push(0);
	for(int i=1;i<=n;i++)
	{
		while(st.size()>1&&a[st.top()]<a[i]) st.pop();
		l[i]=st.top()+1;
		if(a[l[i]-1]==a[i]) l[i]=i;
		st.push(i);
	}
	while(!st.empty()) st.pop();
	st.push(n+1);
	a[n+1]=0;
	for(int i=n;i>=1;i--)
	{
		while(st.size()>1&&a[st.top()]<a[i]) st.pop();
		r[i]=st.top()-1;
		st.push(i);
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		ans+=r[i]-l[i];
	}
	cout<<ans<<endl;
	while(!st.empty()) st.pop();
*/

/*
 20250306重新做了一遍发现没有这么麻烦
 先用单调栈找出左右大于等于他的区间 (板子部分)，如果 a[l[i]]==a[i]那就只算 i到 r[i]部分
 否则算 l[i]到 r[i]
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
int a[N];
int stk[N],p;
int l[N],r[N];
void solve()
{
    cin>>n;
    p=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        l[i]=0,r[i]=n+1;
    }
    for(int i=1;i<=n;i++)
    {
        while(p&&a[i]>a[stk[p]]) p--;
        if(p) l[i]=stk[p];
        stk[++p]=i;
    }
    p=0;
    for(int i=n;i>=1;i--)
    {
        while(p&&a[i]>a[stk[p]]) p--;
        if(p) r[i]=stk[p];
        stk[++p]=i;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(a[l[i]]==a[i]) ans+=r[i]-i-1;
        else ans+=r[i]-l[i]-2;
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}
*/

/*
用笛卡尔树 dfs解法：
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
int a[N];
int ls[N],rs[N];
int stk[N],top;
int ans;
void dfs(int u,int l,int r)
{
    if(ls[u])
    {
        if(a[u]>a[ls[u]]) ans+=u-1-l+1;
        dfs(ls[u],l,u-1);
    }
    if(rs[u])
    {
        if(a[u]>a[rs[u]]) ans+=r-(u+1)+1;
        dfs(rs[u],u+1,r);
    }
}
void solve()
{
    cin>>n;
    top=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        stk[i]=ls[i]=rs[i]=0;
    }

    for(int i=1;i<=n;i++)
    {
        while(a[stk[top]]<a[i]&&top) top--;
        if(!top) ls[i]=stk[top+1];
        else ls[i]=rs[stk[top]],rs[stk[top]]=i;
        stk[++top]=i;
    }

    ans=0;
    dfs(stk[1],1,n);
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}
*/