/*
 * @Author: dsaDadas11
 * @Date: 2024-02-03 14:56:16
 * @LastEditTime: 2024-02-03 14:58:47
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
double theory=100000*(19881.0/39601);
void solve()
{
	int n; cin>>n;
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		int x,y,r; cin>>x>>y>>r;
		if(abs(x)<=70&&abs(y)<=70) sum++;
	}
	if(abs(sum-theory)>2000) cout<<"buaa-noob"<<endl;
	else cout<<"bit-noob"<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}
//ac代码
/*
#include "bits/stdc++.h"

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x, y, r;
        cin >> x >> y >> r;
        if (x <= 9 && x >= -9 && y <= 9 && y >= -9) {
            ans++;
        }
    }
    
    if (ans <= n / 90) {
        cout << "bit-noob\n";
    } else {
        cout << "buaa-noob\n";
    }

    return 0;
}
*/


//卡范围卡过去的ac代码
/*
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
void solve()
{
    int n; cin>>n;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        int x,y,r; cin>>x>>y>>r;
        if(abs(x)<=90&&abs(y)<=90) cnt++;
    }
    if(39601*cnt>32761*n+40000*2000) cout<<"buaa-noob"<<endl;
    else cout<<"bit-noob"<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
    while(T--){solve();}
	return 0;
}
*/