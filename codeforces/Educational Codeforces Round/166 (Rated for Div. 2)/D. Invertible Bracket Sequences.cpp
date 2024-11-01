/*
 * @Author: dsaDadas11
 * @Date: 2024-10-04 20:30:22
 * @LastEditTime: 2024-10-04 21:18:32
 * @Description: go for it!
 */
/*
 解题思路：
 这道题是求将哪一些区间的括号反转还能匹配的上的答案数
 首先我们设b[i]为第i位时左括号不匹配的数量
 如果一段区间[l,r]要想反转后还能匹配，那么则有
 1.b[r]-b[l-1]==0 (区间[l,r]的左右括号数必须相等，否则反转则出现一个括号多，另一个括号少的情况)
 2.任意i∈[l,r],都有b[i]-b[l-1]<=b[l-1]
    ([l,i]的不匹配的左括号数量一定要小于等于[1,l],反证法：大于的话反转后[1,l]左括号数量和[l,i]右括号数量不匹配)
 对于第一点，我们用mp<int,vector<int> > 存相同b[i]值的位置，然后用lowerbound和upperbound寻找满足条件的位置区间，然后ans+=r-l
 对于第二点，我们需要了解当有一个点的b[p]-b[l-1]<=b[l-1],那么l这个位置不可能从p及p后面的位置产生贡献，
 我们可以移项变为b[i]<=2*b[l-1],这就变成一个典型的区间最值问题(RMQ)，我们可以用st表处理
 假设一个点i,一开始要从[i+1,n-1](1和n位置一定不能反转)找满足b[x]<=2*b[i]的位置，因为处理了区间最值,我们直接二分区间即可
 具体的看代码
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
string s;
int b[N];
int f[N][18];
bool check(int l,int r,int c)
{
    int len=r-l+1;
    int k=log(len)/log(2);
    int ans=max(f[l][k],f[r-(1<<k)+1][k]);
    if(ans<=2*c) return 1;
    return 0;
}
void solve()
{
    cin>>s;
    int len=s.size();
    s=' '+s;
    map<int,vector<int> > mp;
    for(int i=1;i<=len;i++)
    {
        if(s[i]=='(') b[i]=b[i-1]+1;
        else b[i]=b[i-1]-1;
        mp[b[i]].push_back(i);
    }
    for(int j=0;j<18;j++)
	{
		for(int i=1;i+(1<<j)-1<=len;i++)
		{
			if(j==0) f[i][j]=b[i];
			else f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
		}
	}
    int ans=0;
    for(int i=1;i<len;i++)
    {
        int l=i+1,r=len-1;
        while(l<r)
        {
            int mid=(l+r)>>1;
            if(check(i+1,mid,b[i])) l=mid+1;
            else r=mid;
        }
        int x=lower_bound(mp[b[i]].begin(),mp[b[i]].end(),i+1)-mp[b[i]].begin();
        int y=upper_bound(mp[b[i]].begin(),mp[b[i]].end(),l)-mp[b[i]].begin();
        ans+=y-x;
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

/*
 下面是题解的ac代码，非常简短
 思路就是用map存前i的位置的每个b的数量，然后看在这个位置能匹配到多少相等的b，
 然后再删除不合法位置
*/
/*
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    map<int, int> cnt;
    int b = 0;
    long long ans = 0;
    for (auto& c : s) {
      b += (c == '(' ? +1 : -1);
      ans += cnt[b];
      ++cnt[b];
      while (cnt.begin()->first * 2 < b)
        cnt.erase(cnt.begin());
    }
    cout << ans << '\n';
  }
}
*/