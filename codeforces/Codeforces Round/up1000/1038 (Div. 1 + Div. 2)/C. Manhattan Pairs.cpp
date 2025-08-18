/*
 * @Author: dsaDadas11
 * @Date: 2025-07-20 15:25:01
 * @LastEditTime: 2025-07-20 15:37:25
 * @Description: go for it!
 */
/*
 解题思路：
 先按 x排序，保证 x的差异最大，
 然后在两个分组种按 y升序和 y降序，保证 y的差异更大
*/
// 高级写法：
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
void solve()
{
    cin>>n;
    vector<array<int,3> > p(n);
    for(int i=0;i<n;i++)
    {
        cin>>p[i][0]>>p[i][1];
        p[i][2]=i+1;
    }
    sort(p.begin(),p.end(),
        [](auto &a,auto &b) {
        if(a[0]!=b[0]) return a[0]<b[0];
        return a[1]<b[1];
    });

    int h=n/2;
    vector<array<int,3> > L(p.begin(),p.begin()+h);
    vector<array<int,3> > R(p.begin()+h,p.end());

    sort(L.begin(),L.end(),
        [](auto &a,auto &b) {
            return a[1]<b[1];
        });
    sort(R.begin(),R.end(),
        [](auto &a,auto &b) {
            return a[1]>b[1];
        });
    
    for(int i=0;i<h;i++)
    {
        cout<<L[i][2]<<' '<<R[i][2]<<endl;
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
 朴素写法：
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
struct po1
{
	int x,y;
	int idx;
	bool operator<(const po1& a) const
	{
		if(x==a.x) return y<a.y;
		return x<a.x;
	}
}p[N];
struct po2
{
	int x,y;
	int idx;
	bool operator<(const po2& a) const
	{
		return y<a.y;
	}
}l[N];
struct po3
{
	int x,y;
	int idx;
	bool operator<(const po3& a) const
	{
		return y>a.y;
	}
}r[N];
void solve()
{
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>p[i].x>>p[i].y;
		p[i].idx=i;
	}
	
	sort(p+1,p+1+n);
	
	for(int i=1;i<=n/2;i++)
	{
		l[i].x=p[i].x;
		l[i].y=p[i].y;
		l[i].idx=p[i].idx;
	}
	int h=n/2;
	for(int i=n/2+1;i<=n;i++)
	{
		r[i-h].x=p[i].x;
		r[i-h].y=p[i].y;
		r[i-h].idx=p[i].idx;
		
	}
	
	sort(l+1,l+1+h);
	sort(r+1,r+1+h);
	
	for(int i=1;i<=h;i++)
	{
		cout<<l[i].idx<<' '<<r[i].idx<<endl;
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