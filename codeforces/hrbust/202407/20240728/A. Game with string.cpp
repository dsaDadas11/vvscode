/*
 * @Author: dsaDadas11
 * @Date: 2024-07-28 15:47:32
 * @LastEditTime: 2024-07-28 15:47:41
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
string s;
string ans="";
void solve()
{
	cin>>s;
	int len=s.size();
	int cnt=0;
	for(int i=0;i<len;i++)
	{
		if(ans.size()&&ans[ans.size()-1]==s[i])
		{
			ans.pop_back();
			cnt++;
		}
		else ans.push_back(s[i]);
	}
	if(cnt%2==0) cout<<"NO"<<endl;
	else cout<<"YES"<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}