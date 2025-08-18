/*
 * @Author: dsaDadas11
 * @Date: 2025-08-04 10:38:12
 * @LastEditTime: 2025-08-04 10:40:24
 * @Description: go for it!
 */
/*
 解题思路：
 我们可以把爆炸放在最后面，然后连锁爆炸产生最大值，前面先用攻击不会引发爆炸的随从攻击，h[i]=1时也能攻击一次，因此所有 h[i]=1产生 1攻击次数
 然后判断攻击次数和爆炸能否让 t[i]死亡并爆炸
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=5e5+7;
constexpr int M=2e3+7;
int n,m;
int h[N],t[N];
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>h[i];
    for(int i=1;i<=m;i++) cin>>t[i];
    sort(h+1,h+1+n);
    sort(t+1,t+1+m);

    int sum=0,cnt=0,ok=0;
    priority_queue<int,vector<int>,greater<int> > pq;
    for(int i=1;i<=n;i++)
    {
        if(h[i]==1)
        {
            sum++;
            ok=1;
        }
        else
        {
            h[i]--;
            cnt++;
            pq.push(h[i]);
        }
    }
    if(ok) cnt++;
    while(!pq.empty()&&pq.top()<=sum)
    {
        sum++;
        pq.pop();
    }
    
    for(int i=1;i<=m;i++)
    {
        if(t[i]<=sum)
        {
            sum++;
        }
        else
        {
            int atk=min(t[i]-sum,cnt);
            t[i]-=atk;
            cnt-=atk;
            if(t[i]<=sum)
            {
                sum++;
            }
        }
        while(!pq.empty()&&pq.top()<=sum)
        {
            sum++;
            pq.pop();
        }
    }
    if(t[m]>sum) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}