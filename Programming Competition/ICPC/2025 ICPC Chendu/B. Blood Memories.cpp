/*
 * @Author: dsaDadas11
 * @Date: 2025-10-29 19:56:22
 * @LastEditTime: 2025-10-29 19:57:16
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
struct matrix
{
    int c[65][65];
    matrix(){memset(c,0,sizeof c);}
};
int sz;
matrix operator*(matrix &x,matrix &y)
{
    matrix t;
    for(int i=0;i<sz;i++)
    {
        for(int k=0;k<sz;k++)
        {
            for(int j=0;j<sz;j++)
            {
                t.c[i][j]=max(t.c[i][j],x.c[i][k]+y.c[k][j]);
            }
        }
    }
    return t;
}
matrix quickpow(matrix x,int y)
{
    matrix ans;
    
    while(y)
    {
        if(y&1) ans=ans*x;
        x=x*x;
        y>>=1;
    }
    return ans;
}
int n,m,add,R;
int a[8],c[8];
void solve()
{
    cin>>n>>m>>add>>R;
    sz=(1<<n);

    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>c[i];
    }

    matrix w;

    vector<int> S;

    for(int i=0;i<sz;i++)
    {
        int hp=0;
        for(int k=0;k<n;k++)
        {
            if(i&(1<<k))
            {
                hp+=c[k];
            }
        }
        if(hp<=m) S.push_back(i);
    }

    for(int s1:S)
    {
        for(int k=0;k<n;k++)
        {
            if(s1&(1<<k))
            {
                c[k]+=add;
            }
        }

        for(int s2:S)
        {
            int atk=0,hp=0;
            for(int k=0;k<n;k++)
            {
                if(s2&(1<<k))
                {
                    hp+=c[k];
                    atk+=a[k];
                }
            }

            if(hp<=m) w.c[s1][s2]=atk;
        }

        for(int k=0;k<n;k++)
        {
            if(s1&(1<<k))
            {
                c[k]-=add;
            }
        }
    }

    w=quickpow(w,R);

    int ans=0;
    for(int i=0;i<sz;i++)
    {
        for(int j=0;j<sz;j++)
        {
            ans=max(ans,w.c[i][j]);
        }
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