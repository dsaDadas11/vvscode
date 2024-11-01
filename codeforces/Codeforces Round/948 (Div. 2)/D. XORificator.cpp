/*
 * @Author: dsaDadas11
 * @Date: 2024-09-30 14:48:23
 * @LastEditTime: 2024-09-30 15:58:48
 * @Description: go for it!
 */
/*
 解题思路：
 这道题让我们操作一些行，把这个行整体取反，然后求每一列有一个1的最大列数
 因为答案要找多少列数，那么一定存在一列有贡献(即只有一个1)，
 并且当这列的状态确定了，整个矩阵也就确定了，
 因此我们枚举m列，假设第j列有贡献，然后枚举这一列的第i行为1，其他行为0，(***)
 算出此时最大的列数，然后取最大的列数即可

 要求出(***)步骤，就要用到哈希，不然会超时，
 我们先求这一列全变为0的哈希值，再分别算每个i位置变为1的哈希值，然后用map加一下，
 然后map中value最大的就是答案了(每一列如果取1的情况相同的话，哈希值相同，因此用map存个数再好不过了)
 最后遍历地找这个哈希值对应的序列

 我们想想怎么改变哈希?
 0原->0 48    1原->0 49   那么 0->0原 -48    0->1原 -49
 0原->1 49   1原->1 48  那么 1->0原 -49     1->1原 -48
 则 0->1 等价于 0->0原 + 0原->1 即 -48 + 49 
    1->0 等价于 1->0原 + 0原->0 即 -49 + 48
 我们可以这样想：我们将所有数变为0时'0'的贡献为48，'1'的贡献为49，那么变数的时候将0、1贡献交换即可
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=3e5+7;
constexpr int M=2e3+7;
constexpr int mod1=1e9+7;
constexpr int mod2=998244353;
int base1=29,base2=131;
int n,m;
int p1[N],p2[N];
string s[N];
void pre()
{
	p1[0]=1;
	for(int i=1;i<=3e5+3;i++)
	{
		p1[i]=(p1[i-1]*base1)%mod1;
	}
    p2[0]=1;
	for(int i=1;i<=3e5+3;i++)
	{
		p2[i]=(p2[i-1]*base2)%mod2;
	}
}
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>s[i];
    for(int i=1;i<=n;i++) s[i]=' '+s[i];
    map<pair<int,int>,int> mp; // 存双哈希
    // 将每一列固定
    for(int j=1;j<=m;j++)
    {
        int h1=0,h2=0;
        // 先求这一列全为0的哈希
        for(int i=1;i<=n;i++)
        {
            h1=((h1*base1+s[i][j])%mod1+mod1)%mod1;
            h2=((h2*base2+s[i][j])%mod2+mod2)%mod2;
        }
        // 把(i,j)变为1的哈希
        for(int i=1;i<=n;i++)
        {
            int hh1=h1,hh2=h2;
            // 0->1 就是这一位-48+49    1->1 就是这一位-49+48
            // 我们可以这样想：我们将所有数变为0时'0'的贡献为48，'1'的贡献为49，那么变数的时候将0、1贡献交换即可
            if(s[i][j]=='0')
            {
                hh1=((h1+p1[n-i])%mod1+mod1)%mod1;
                hh2=((h2+p2[n-i])%mod2+mod2)%mod2;
            }
            else
            {
                hh1=((h1-p1[n-i])%mod1+mod1)%mod1;
                hh2=((h2-p2[n-i])%mod2+mod2)%mod2;
            }
            mp[{hh1,hh2}]++;
        }
    }
    int ans=0;
    for(auto [x,y]:mp) ans=max(ans,y);
    cout<<ans<<endl;
    for(int j=1;j<=m;j++)
    {
        int h1=0,h2=0;
        // 先求这一列全为0的哈希
        for(int i=1;i<=n;i++)
        {
            h1=((h1*base1+s[i][j])%mod1+mod1)%mod1;
            h2=((h2*base2+s[i][j])%mod2+mod2)%mod2;
        }
        // 把(i,j)变为1的哈希
        for(int i=1;i<=n;i++)
        {
            int hh1=h1,hh2=h2;
            if(s[i][j]=='0')
            {
                hh1=((h1+p1[n-i])%mod1+mod1)%mod1;
                hh2=((h2+p2[n-i])%mod2+mod2)%mod2;
            }
            else
            {
                hh1=((h1-p1[n-i])%mod1+mod1)%mod1;
                hh2=((h2-p2[n-i])%mod2+mod2)%mod2;
            }
            // 判断这个变化是否为ans
            if(mp[{hh1,hh2}]==ans)
            {
                for(int k=1;k<i;k++) cout<<s[k][j];
                cout<<(s[i][j]=='1'?'0':'1');
                for(int k=i+1;k<=n;k++) cout<<s[k][j];
                cout<<endl;
                return;
            }
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    pre();
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}