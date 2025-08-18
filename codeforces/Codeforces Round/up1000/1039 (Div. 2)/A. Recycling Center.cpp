/*
 * @Author: dsaDadas11
 * @Date: 2025-08-02 10:28:02
 * @LastEditTime: 2025-08-02 10:28:11
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int n,c;
void solve()
{
    cin>>n>>c;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    while(a.size())
    {
        vector<int> b;
        int pos=lower_bound(a.begin(),a.end(),c)-a.begin();
        if(pos>=a.size()) pos--;
        if(a[pos]>c&&pos) pos--;
        if(a[pos]>c) break;
        for(int i=0;i<a.size();i++)
        {
            if(i==pos) continue;
            b.push_back(a[i]*2LL);
        }
        a=b;
    }
    cout<<a.size()<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}