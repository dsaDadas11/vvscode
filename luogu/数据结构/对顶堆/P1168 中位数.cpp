/*
 * @Author: dsaDadas11
 * @Date: 2025-09-02 14:30:20
 * @LastEditTime: 2025-09-02 14:30:28
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n;
int a[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    priority_queue<int,vector<int>,greater<int> > t; // 小根堆
    priority_queue<int> s; // 大根堆
    //  [大根堆 1 2 3] [4 5 6小根堆]  (左  右)
    for(int i=1;i<=n;i++)
    {
        if(i==1) s.push(a[i]);
        else
        {
            if(a[i]>s.top()) t.push(a[i]);
            else s.push(a[i]);

            while(abs((int)s.size()-(int)t.size())>1)
            {
                if(s.size()>t.size())
                {
                    t.push(s.top());
                    s.pop();
                }
                else
                {
                    s.push(t.top());
                    t.pop();
                }
            }
        }

        if(i&1)
        {
            if(s.size()>t.size()) cout<<s.top()<<endl;
            else cout<<t.top()<<endl;
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