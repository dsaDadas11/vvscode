/*
 * @Author: dsaDadas11
 * @Date: 2025-09-12 17:11:55
 * @LastEditTime: 2025-09-12 17:12:04
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e4+7;
constexpr int M=2e3+7;
constexpr int mod=1e9+7;
int n;
string s;
int lst[N];
int pos[27];
int base=29;
int p[N],ha[N];
void init()
{
	p[0]=1;
	for(int i=1;i<N;i++)
	{
		p[i]=(p[i-1]*base)%mod;
	}
}

int get(int l,int r)
{
	return ((ha[r]-ha[l-1]*p[r-l+1])%mod+mod)%mod;
}

void solve()
{
    cin>>s;
    n=s.size();
    s=' '+s;
    for(int i=0;i<=n;i++) lst[i]=0;
    for(int i=0;i<=26;i++) pos[i]=0;
    for(int i=1;i<=n;i++)
    {
        lst[i]=pos[s[i]-'a'];
        pos[s[i]-'a']=i;
    }

    for(int i=1;i<=n;i++)
    {
        ha[i]=((ha[i-1]*base+s[i]-'a'+1)%mod+mod)%mod;
    }

    int ans=0;
    for(int i=1;i<n;i++)
    {
        int xl=i+1,xr=i;
        for(int r=i,l=i+1;l<=n&&r>=1;l++,r--)
        {
            if(xr<1||xl>n) break;
            if(get(xl,l)==get(r,xr))
            {
                ans++;
                xl=l+1,xr=r-1;
            }
        }
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}