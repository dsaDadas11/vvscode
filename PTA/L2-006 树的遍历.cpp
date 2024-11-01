/*
 * @Author: dsaDadas11
 * @Date: 2024-04-24 19:09:59
 * @LastEditTime: 2024-04-24 19:11:28
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,vis;
int mid[37],ed[37];
struct Tree
{
	int val;
	Tree *lchild;
	Tree *rchild;
};
Tree *build(int l1,int r1,int l2,int r2)
{
	if(l1>r1||l2>r2) return NULL;
	Tree *root=new Tree;
	root->val=ed[r2];
	int pos=-1;
	for(int i=1;i<=n;i++)
	{
		if(mid[i]==ed[r2])
		{
			pos=i;
			break;
		}
	}
	root->lchild=build(l1,pos-1,l2,l2+pos-l1-1);
	root->rchild=build(pos+1,r1,l2+pos-l1,r2-1);
	return root;
}
void bfs(Tree *root)
{
	queue<Tree*> q;
	q.push(root);
	while(!q.empty())
	{
		Tree *temp=q.front();
		q.pop();
		if(temp)
		{
			if(!vis)cout<<temp->val;
			else cout<<' '<<temp->val;
			vis=1;
			q.push(temp->lchild);
			q.push(temp->rchild);
		}
	}
	cout<<endl;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>ed[i];
	for(int i=1;i<=n;i++) cin>>mid[i];
	Tree *root=build(1,n,1,n);
	bfs(root);
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}