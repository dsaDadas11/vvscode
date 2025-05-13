/*
 解题思路：
 算行和列的 1最大值
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,m;
string s[107];
int a[107][107];
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        s[i]=' '+s[i];
        for(int j=1;j<=m;j++)
        {
            a[i][j]=s[i][j]-'0';
        }
    }
    int ans1=0,ans2=0;
    for(int i=1;i<=n;i++)
    {
        int tmp=0;
        for(int j=1;j<=m;j++)
        {
            tmp^=a[i][j];
        }
        if(tmp!=0) ans1++;
    }

    for(int j=1;j<=m;j++)
    {
        int tmp=0;
        for(int i=1;i<=n;i++)
        {
            tmp^=a[i][j];
        }
        if(tmp!=0) ans2++;
    }

    cout<<max(ans1,ans2)<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}