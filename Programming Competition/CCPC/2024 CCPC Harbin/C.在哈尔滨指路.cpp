/*
 * @Author: dsaDadas11
 * @Date: 2024-10-20 20:33:20
 * @LastEditTime: 2024-10-20 20:33:26
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
vector<string> ans;
char c[17];
int x[17];
void solve()
{
	cin>>n;
	char st='~';
	for(int i=1;i<=n;i++)
	{
		cin>>c[i]>>x[i];
		if(st=='~') st=c[i];
	}
	string s="Z "+to_string(x[1]);
	ans.push_back(s);
	for(int i=2;i<=n;i++)
	{
		if(c[i-1]=='N')
		{
			if(c[i]=='W')
			{
				ans.push_back("L");
			}
			else
			{
				ans.push_back("R");
			}
		}
		else if(c[i-1]=='S')
		{
			if(c[i]=='W')
			{
				ans.push_back("R");
			}
			else
			{
				ans.push_back("L");
			}
		}
		else if(c[i-1]=='W')
		{
			if(c[i]=='N')
			{
				ans.push_back("R");
			}
			else
			{
				ans.push_back("L");
			}
		}
		else
		{
			if(c[i]=='N')
			{
				ans.push_back("L");
			}
			else
			{
				ans.push_back("R");
			}
		}
		s="Z "+to_string(x[i]);
		ans.push_back(s);
	}
	cout<<(int)ans.size()<<' '<<st<<endl;
	for(auto s:ans) cout<<s<<endl;
	ans.clear();
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}
/*
1
2
S 2
E 1

ans:
3 S
Z 2
L
Z 1
*/