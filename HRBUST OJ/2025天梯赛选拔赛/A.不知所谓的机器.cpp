/*
 * @Author: dsaDadas11
 * @Date: 2025-03-30 10:11:38
 * @LastEditTime: 2025-03-30 20:29:35
 * @Description: go for it!
 */
// -1&x = x
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
#define GL (root<<1)
#define GR ((root<<1)|1)
using namespace std;
constexpr int N=2e5+7;
constexpr int M=2e3+7;
constexpr int inf=(1LL<<60)-1;
int n,m;
int a[N];
struct Tree
{
	int l,r,val;
}tree[N<<2];
int And[N<<2],Xor[N<<2];
void build(int root,int l,int r)
{
	tree[root].l=l;
	tree[root].r=r;
    And[root]=inf;
    Xor[root]=0;
	if(l==r)
	{
		tree[root].val=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(GL,l,mid);
	build(GR,mid+1,r);
}
void push_down(int root)
{
    if(And[root]!=inf||Xor[root])
    {
        And[GL]&=And[root];
        And[GR]&=And[root];
        Xor[GL]=(Xor[GL]&And[root])^Xor[root];
        Xor[GR]=(Xor[GR]&And[root])^Xor[root];
        And[root]=inf;
        Xor[root]=0;
    }
}
void update(int root,int l,int r,int qie,int yihuo)
{
	if(l<=tree[root].l&&tree[root].r<=r)
	{
        And[root]&=qie;
        Xor[root]=(Xor[root]&qie)^yihuo;
		return;
	}
	push_down(root);
	int mid=(tree[root].l+tree[root].r)>>1;
	if(l<=mid) update(GL,l,r,qie,yihuo);
	if(mid+1<=r) update(GR,l,r,qie,yihuo);
}
int query(int root,int pos)
{
	if(pos==tree[root].l&&tree[root].r==pos)
    {
        return ((tree[root].val&And[root])^Xor[root]);
    }
	push_down(root);
	int mid=(tree[root].l+tree[root].r)>>1;
	if(pos<=mid) return query(GL,pos);
	else return query(GR,pos);
}
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    vector<int> ans;
    int op,l,r,x;
    while(m--)
    {
        cin>>op;
        if(op==4)
        {
            cin>>x;
            ans.push_back(query(1,x));
        }
        else
        {
            cin>>l>>r>>x;
            if(op==1) update(1,l,r,x,0);
            else if(op==2) update(1,l,r,~x,x);
            else update(1,l,r,inf,x);
        }
    }
    for(int i=0;i<ans.size();i++)
    {
        if(i!=ans.size()-1) cout<<ans[i]<<endl;
        else cout<<ans[i];
    }
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}