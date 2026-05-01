/*
 * @Author: dsaDadas11
 * @Date: 2026-01-20 18:45:13
 * @LastEditTime: 2026-01-20 18:45:22
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e3+7;
constexpr int M=2e3+7;
int a[N],b[N],c[N];
string add(string s1,string s2)
{
    memset(a,0,sizeof a);
    memset(b,0,sizeof b);
    memset(c,0,sizeof c);
    
    int len=s1.size();
    for(int i=0;i<len;i++)
    {
        a[len-i-1]=s1[i]-'0';
    }
    len=s2.size();
    for(int i=0;i<len;i++)
    {
        b[len-i-1]=s2[i]-'0';
    }

    len=max(s1.size(),s2.size());

    for(int i=0;i<len;i++)
    {
        c[i]+=a[i]+b[i];
        if(c[i]>=10)
        {
            c[i+1]+=1;
            c[i]-=10;
        }
    }

    while(c[len]) len++;
    string ans="";
    for(int i=len-1;i>=0;i--)
    {
        ans+=c[i]+'0';
    }
    return ans;
}
string sub(string s1,string s2)
{
    memset(a,0,sizeof a);
    memset(b,0,sizeof b);
    memset(c,0,sizeof c);
    
    bool sign=0;
    if(s1.size()<s2.size()||(s1.size()==s2.size()&&s1<s2))
    {
        sign=1;
        swap(s1,s2);
    }

    int len=s1.size();
    for(int i=0;i<len;i++)
    {
        a[len-i-1]=s1[i]-'0';
    }
    len=s2.size();
    for(int i=0;i<len;i++)
    {
        b[len-i-1]=s2[i]-'0';
    }
    
    len=s1.size();

    for(int i=0;i<len;i++)
    {
        if(a[i]<b[i])
        {
            a[i+1]--;
            a[i]+=10;
        }
        c[i]=a[i]-b[i];
    }
    while(c[len-1]==0&&len>1) len--;
    string ans="";
    if(sign) ans="-";
    for(int i=len-1;i>=0;i--)
    {
        ans+=c[i]+'0';
    }
    return ans;
}
string mul(string s1,string s2)
{
    memset(a,0,sizeof a);
    memset(b,0,sizeof b);
    memset(c,0,sizeof c);

    int len1=s1.size(),len2=s2.size();
    int len=len1+len2+1;
    for(int i=0;i<len1;i++)
    {
        a[len1-i-1]=s1[i]-'0';
    }
    for(int i=0;i<len2;i++)
    {
        b[len2-i-1]=s2[i]-'0';
    }

    for(int i=0;i<len1;i++)
    {
        for(int j=0;j<len2;j++)
        {
            c[i+j]+=a[i]*b[j];
            if(c[i+j]>=10)
            {
                c[i+j+1]+=c[i+j]/10;
                c[i+j]%=10;
            }
        }
    }
    
    while(c[len]>0)
    {
        if(c[len]>=10)
        {
            c[len+1]=c[len]/10;
            c[len]%=10;
        }
        len++;
    }

    while(c[len-1]==0&&len>1) len--;
    string ans="";
    for(int i=len-1;i>=0;i--)
    {
        ans+=c[i]+'0';
    }
    return ans;
}
void solve()
{
    string s1,s2;
    cin>>s1>>s2;
    cout<<add(s1,s2)<<endl;
    cout<<sub(s1,s2)<<endl;
    cout<<mul(s1,s2)<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}