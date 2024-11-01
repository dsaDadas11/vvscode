/*
 * @Author: dsaDadas11
 * @Date: 2024-02-19 18:21:08
 * @LastEditTime: 2024-02-19 19:32:25
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int a[N];
void solve()
{
	int n; cin>>n;
    int even=0;
    for(int i=1;i<=n;i++)
    {
        int x; cin>>x;
        if(x%2==0) even++;
    }
    if(even%2) cout<<"gui"<<endl;
    else cout<<"sweet"<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}

/*
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int a[N];
void solve()
{
	int n; cin>>n;
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        int x; cin>>x;
        sum+=x-1; //每堆x个要x-1次才能分完
    }
    if(sum%2) cout<<"gui"<<endl;
    else cout<<"sweet"<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}
*/