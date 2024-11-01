/*
 * @Author: dsaDadas11
 * @Date: 2024-02-05 19:41:34
 * @LastEditTime: 2024-02-05 19:41:40
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
void solve()
{
	int a,b,c; cin>>a>>b>>c;
    int cnt=0;
    if(a==150) cnt+=1;
    if(a==200) cnt+=2;
    if(b==34||b==36||b==38||b==40) cnt+=1;
    if(b==45) cnt+=2;
    if(c==34||c==36||c==38||c==40) cnt+=1;
    if(c==45) cnt+=2;
    cout<<cnt<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}