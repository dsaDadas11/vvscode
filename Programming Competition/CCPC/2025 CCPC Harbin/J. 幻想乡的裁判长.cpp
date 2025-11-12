/*
 * @Author: dsaDadas11
 * @Date: 2025-11-11 13:16:59
 * @LastEditTime: 2025-11-11 13:17:17
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
// #define int ll
using namespace std;
constexpr int N=4e7+5;
constexpr int M=2e3+7;
char s[N],t1[N],t2[N];
int len1,len2;
int p[N],pos[N];
void manacher()
{
    t2[len2]='$';
    for(int i=1;i<=len1;i++)
    {
        t2[++len2]='#';
        t2[++len2]=t1[i];
    }
    t2[++len2]='#';
    t2[++len2]='&';


    int r=0,c;
    for(int i=1;i<len2;i++)
    {
        if(i<r) p[i]=min(p[2*c-i],r-i);
        else p[i]=1;
        
        while(t2[i-p[i]]==t2[i+p[i]]) p[i]++;

        if(i+p[i]>r)
        {
            r=i+p[i];
            c=i;
        }
    }


    // for(int i=1;i<len2;i++)
    // {
    //     cout<<t2[i];
    // }
    // cout<<endl;
    // for(int i=1;i<len2;i++)
    // {
    //     cout<<p[i]<<' ';
    // }
    // cout<<endl;
}
bool is_lw(int l)
{
    return pos[l]==pos[l-1];
}
bool is_rw(int r)
{
    return pos[r]==pos[r+1];
}
int n;
int calc(int x)
{
    if(t2[x]=='#') return (p[x]/2)*2;
    else return (p[x]/2)*2-1;
}
int lv[N],rv[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>s[i];

    len1=len2=0;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='w')
        {
            t1[++len1]='v';
            pos[len1]=i;
            t1[++len1]='v';
            pos[len1]=i;
        }
        else
        {
            t1[++len1]=s[i];
            pos[len1]=i;
        }
    }
    pos[0]=-1,pos[len1+1]=-1;


    lv[0]=0,rv[len1+1]=0;
    for(int i=1;i<=len1;i++)
    {
        if(s[i]=='v') lv[i]=i;
        else lv[i]=lv[i-1];
    }
    for(int i=len1;i>=1;i--)
    {
        if(s[i]=='v') rv[i]=i;
        else rv[i]=rv[i+1];
    }

    manacher();

    int ansl=1,ansr=1;
    for(int i=1;i<len2;i++)
    {
        int idx=i/2,len=calc(i);
        if(t2[i]=='#'&&len==1) continue;

        len/=2;
        if(len==0) continue;

        int l,r;
        if(t2[i]=='#')
        {
            l=idx-len+1,r=idx+len;
        }
        else
        {
            l=idx-len,r=idx+len;
        }

        if(!is_lw(l)&&!is_rw(r))
        {
            if(pos[r]-pos[l]+1>ansr-ansl+1)
            {
                ansl=pos[l],ansr=pos[r];
            }
        }
        else
        {
            if(rv[pos[l]]==0||rv[pos[l]]>pos[r]) continue;
            int res1=rv[pos[l]]-pos[l]+1,res2=pos[r]-lv[pos[r]]+1;
            int dl=pos[l],dr=pos[r];
            if(res1<=res2&&is_lw(l))
            { // 多跨越一个块
                dl+=res1,dr-=res1-1;
            }
            else if(res2<=res1&&is_rw(r))
            {
                dl+=res2-1,dr-=res2;
            }
            else
            { // 都要多跨越一个块
                int mm=min(res1,res2);
                dl+=mm,dr-=mm;
            }

            if(dr-dl+1>ansr-ansl+1)
            {
                ansl=dl,ansr=dr;
            }
        }
    }

    for(int i=ansl;i<=ansr;i++) cout<<s[i];
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}