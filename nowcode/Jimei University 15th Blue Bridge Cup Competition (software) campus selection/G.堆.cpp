/*
 * @Author: dsaDadas11
 * @Date: 2024-01-20 20:32:06
 * @LastEditTime: 2024-01-20 20:32:11
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
const int N=1e6+7;
const int M=2e3+7;
priority_queue<int, vector<int>, greater<int>> que;
int sum = 0;

void solve()
{
    int op, x;
    cin >> op;
    switch (op)
    {
    case 1:
        cin >> x;
        que.push(x - sum);
        break;
    case 2:
        cout << que.top() + sum << endl;
        que.pop();
        break;
    case 3:
        cin >> x;
        sum += x;
        break;
    }
}

signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;cin >> t;
    while (t--){solve();}
    return 0;
}