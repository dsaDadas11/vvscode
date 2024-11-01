/*
 * @Author: dsaDadas11
 * @Date: 2024-08-30 16:39:55
 * @LastEditTime: 2024-08-30 17:05:06
 * @Description: go for it!
 */
// 动态链表，要用到 new 和 delete
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m;
struct node
{
	int data;
	node *next;
};
void solve()
{
	cin>>n>>m;
	node *head,*pre,*now,*p;
	head=new node;
	head->data=1,head->next=NULL;
	now=head;
	for(int i=2;i<=n;i++)
	{
		p=new node;
		p->data=i,p->next=NULL;
		now->next=p;
		now=p;
	}
	now->next=head;
	now=head,pre=head;
	while(n>1)
	{
		for(int i=1;i<m;i++)
		{
			pre=now;
			now=now->next;
		}
		cout<<now->data<<' ';
		pre->next=now->next;
		delete now;
		now=pre->next;
		n--;
	}
	cout<<now->data<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}

// 静态链表，用到结构体
/*
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
struct node
{
	int id;
	int next;
}a[107];
int n,m;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		a[i].id=i;
		a[i].next=i+1;
	}
	a[n].next=1;
	int now=1,pre=1;
	while(n>1)
	{
		for(int i=1;i<m;i++)
		{
			pre=now;
			now=a[now].next;
		}
		cout<<a[now].id<<' ';
		a[pre].next=a[now].next;
		now=a[pre].next;
		n--;
	}
	cout<<a[now].id<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}
*/

//使用 c++ stl中list的双向链表
/*
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m;
list<int> li;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		li.push_back(i);
	}
	auto it=li.begin();
	while(n>1)
	{
		for(int i=1;i<m;i++)
		{
			it++;
			if(it==li.end()) it=li.begin();
		}
		cout<<*it<<' ';
		auto next=++it;
		if(next==li.end()) next=li.begin();
		li.erase(--it);
		it=next;
		n--;
	}
	cout<<*it<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}
*/