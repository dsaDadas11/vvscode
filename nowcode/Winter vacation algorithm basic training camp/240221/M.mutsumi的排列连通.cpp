/*
 * @Author: dsaDadas11
 * @Date: 2024-02-21 18:40:35
 * @LastEditTime: 2024-02-21 18:40:42
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e5+7;
constexpr int M=2e3+7;
int a[N],b[N];
void solve()
{
	int n; cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    int ans=0; bool flag=0;
    if(n==1) cout<<"-1"<<endl;
    else if(n==2)
    {
        if(a[1]==b[1]) cout<<"-1"<<endl;
        else cout<<1<<endl;
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            if(a[i]==b[i]&&i!=1&&i!=n) flag=1;
            if(a[i]==b[i+1]) flag=1;
            if(a[i]==b[i-1]) flag=1;
        }
        if(flag) cout<<"1"<<endl;
        else cout<<"2"<<endl;
    }
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}