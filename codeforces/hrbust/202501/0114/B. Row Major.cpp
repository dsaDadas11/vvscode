/*
 * @Author: dsaDadas11
 * @Date: 2025-01-14 20:43:22
 * @LastEditTime: 2025-01-15 11:41:04
 * @Description: go for it!
 */
/*
 解题思路：
 题目意思为 大小为 n 的字符串可被分为 di*dj (di*dj = n) 行列，
 且每行每列相邻单元格不能为同一字符
 首先要求每列不相同：那就是 abc....zabc....z...以此循环，
 所以我们应该选择一个[2,27]的模数使得一列的相邻单元格不相同，且 27 的阶乘远远大于 1e6,因此肯定有解
 那么这个模数应该如何选择？
 我们可以选择 n%p!=0 的 p，这样 n 分成不同行列后每行相邻的模数都不会相同
 证明：设 当前行(i,j)字符为 a+((i-1)*c+j) (mod p)
         下一行(i+1,j)字符为 a+(i*c+j) (mod p)
 如果 n%p=0 那么总有 c=p
 因此 (i,j)的字符为 a+j (mod p)  (i+1,j)的字符为 a+j , 两者相等了
 因此我们需要找 n%p!=0 且在 [2,27] 间的模数即可
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
void solve()
{
    cin>>n;
    if(n==1) return cout<<"a"<<endl,void();
    if(n==2) return cout<<"ab"<<endl,void();
    int mm=2;
    for(int i=2;i<n;i++)
    {
        if(n%i)
        {
            mm=i;
            break;
        }
    }
    string s;
    for(int i=1;i<=n;i++)
    {
        s.push_back((char)('a'+(i-1)%mm));
    }
    cout<<s<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}