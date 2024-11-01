/*
 * @Author: dsaDadas11
 * @Date: 2024-05-14 20:04:10
 * @LastEditTime: 2024-05-14 20:07:33
 * @Description: go for it!
 */
#include <bits/stdc++.h>
using namespace std;
#define int ll
#define ll long long
#define buff ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
const int N=2e5+7;

void solve()
{
	string s,ans="";
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++)
	{
		if(s[i]==s[i+1]&&s[i]==s[i+2])
		{
			i+=2;
			continue;
		}
		ans.push_back(s[i]);
		int len1=ans.size();
		if(ans[len1-1-1-1]==ans[len1-1-1]&&ans[len1-1-1]==ans[len1-1])
		{
			ans.pop_back();
			ans.pop_back();
			ans.pop_back();
		}
	}
	if(ans.size()==0) cout<<"NAN"<<endl;
	else
	cout<<ans<<endl;
}

signed main()
{
	buff;
	int tt = 1;
	// cin >> tt;
	while (tt--)
	{
		solve();
	}
	return 0;
} 