/*
 * @Author: dsaDadas11
 * @Date: 2025-07-18 20:40:53
 * @LastEditTime: 2025-07-18 20:47:59
 * @Description: go for it!
 */
/*
 解题思路：
 简单数学推出区间 gcd + 线段树维护区间 gcd
 称满足 a[i]>a[i+1]的下标 i为断点，，显然划分出的大小需要 a[i]和 a[i+1]在不同的划分序列中，
 因此答案的种类数是所有断点的 gcd因数的个数
 证明：
 设有 [1,a] [a+1,b] [b+1,c]
 那么 gg=gcd(a-1+1, b-a-1+1, c-b-1+1)=gcd(a, b-a, c-b)
 根据定理 gcd(a, b)=gcd(a, b-a) 可得原式 =gcd(a,b,c)
 也就是求所有断点的 gcd，但是题目要求把 a[p]变为 v,那么就需要用线段树维护 gcd
 将修改后的断点删去或添加

 hack: cnt[0]表示的是整个数组都是不递减,因此划分方案有 n种(划分为 1,2,3,...,n都可以)
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
#define GL (root<<1)
#define GR ((root<<1)|1)
using namespace std;
constexpr int N=2e5+7;
constexpr int M=2e3+7;
int n,q,a[N];
struct Tree
{
	int left,right,val;
}tree[N<<2];
void build(int root,int left,int right)
{
	tree[root].left=left;
	tree[root].right=right;
	if(left==right)
	{
		tree[root].val=0;
		return;
	}
	int mid=(left+right)>>1;
	build(GL,left,mid);
	build(GR,mid+1,right);
    tree[root].val=0;
}
void update(int root,int pos,int val)
{
	if(tree[root].left==tree[root].right)
	{
		tree[root].val=val;
		return;
	}
	int mid=(tree[root].left+tree[root].right)>>1;
	if(pos<=mid) update(GL,pos,val);
	else update(GR,pos,val);
    tree[root].val=gcd(tree[GL].val,tree[GR].val);
}
int query(int root,int left,int right)
{
	if(left<=tree[root].left&&tree[root].right<=right) return tree[root].val;
	int mid=(tree[root].left+tree[root].right)>>1;
	int ans=0;
	if(left<=mid) ans=gcd(ans,query(GL,left,right));
	if(mid+1<=right) ans=gcd(ans,query(GR,left,right));
	return ans;
}
int cnt[N];
void init()
{
    for(int i=1;i<N;i++)
    {
        for(int j=i;j<N;j+=i)
        {
            cnt[j]++;
        }
    }
}
void solve()
{
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    cnt[0]=n; // 这里要特判，如果一个数组都是不递减的话有 n种选择
    a[0]=a[n+1]=0;
    build(1,1,n);
    for(int i=1;i<n;i++)
    {
        if(a[i]>a[i+1]) update(1,i,i);
    }
    cout<<cnt[query(1,1,n)]<<endl;
    int p,v;
    while(q--)
    {
        cin>>p>>v;
        // p  p+1
        if(a[p]>a[p+1]&&v<=a[p+1])
        {
            update(1,p,0);
        }
        if(a[p]<=a[p+1]&&v>a[p+1])
        {
            update(1,p,p);
        }
        // p-1  p
        if(a[p-1]>a[p]&&v>=a[p-1])
        {
            update(1,p-1,0);
        }
        if(a[p-1]<=a[p]&&v<a[p-1])
        {
            update(1,p-1,p-1);
        }
        a[p]=v;
        cout<<cnt[query(1,1,n)]<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}