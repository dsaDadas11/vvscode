/*
 * @Author: dsaDadas11
 * @Date: 2025-10-08 21:29:51
 * @LastEditTime: 2025-10-08 21:29:57
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#include<bits/extc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
using namespace __gnu_pbds;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> tr;
int n,op,x;
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>op>>x;
        if(op==1) tr.insert((x<<20)+i);
        else if(op==2) tr.erase(tr.lower_bound((x<<20)));
        else if(op==3) cout<<tr.order_of_key(x<<20)+1<<endl;
        else if(op==4)
        {
            int ans=*tr.find_by_order(x-1); // 下标从 0开始
            cout<<(ans>>20)<<endl;
        }
        else if(op==5)
        {
            int ans=*--tr.lower_bound(x<<20);
            cout<<(ans>>20)<<endl;
        }
        else
        {
            int ans=*tr.upper_bound((x<<20)+n);
            cout<<(ans>>20)<<endl;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}