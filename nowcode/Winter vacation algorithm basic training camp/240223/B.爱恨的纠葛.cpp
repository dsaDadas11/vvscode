/*
 * @Author: dsaDadas11
 * @Date: 2024-02-23 16:17:18
 * @LastEditTime: 2024-02-23 16:17:24
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
    vector<pair<int,char> > v;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        v.push_back({a[i],'a'});
    }
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        v.push_back({b[i],'b'});
    }
    sort(v.begin(),v.end());
    int pa=0,pb=0;
    for(int i=0;i<=2*n-1;i++)
    {
        if(v[i].second=='a')
        {
            pa=i;
            break;
        }
    }
    for(int i=0;i<=2*n-1;i++)
    {
        if(v[i].second=='b')
        {
            pb=i;
            break;
        }
    }
    int mm=abs(v[pa].first-v[pb].first);
    int st=max(pa,pb);
    int ra=pa,rb=pb;
    for(int i=st;i<=2*n-1;i++)
    {
        if(v[i].second=='a') pa=i;
        else pb=i;
        if(mm>abs(v[pa].first-v[pb].first))
        {
            mm=abs(v[pa].first-v[pb].first);
            ra=pa;
            rb=pb;
        }
    }
    int posa=0,posb=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==v[ra].first) posa=i;
        if(b[i]==v[rb].first) posb=i;
    }
    swap(a[posa],a[posb]);
    for(int i=1;i<=n;i++) cout<<a[i]<<' ';
    cout<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}