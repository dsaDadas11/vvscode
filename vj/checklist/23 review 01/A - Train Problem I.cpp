/*
 * @Author: dsaDadas11
 * @Date: 2024-05-23 09:07:24
 * @LastEditTime: 2024-05-23 09:07:38
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
string o1,o2;
void solve()
{
	stack<char> st;
	vector<string> ans;
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		st.push(o1[i]);
		ans.push_back("in");
		while(!st.empty())
		{
			if(st.top()==o2[cnt])
			{
				ans.push_back("out");
				st.pop();
				cnt++;
			}
			else break;
		}
	}
	if(!st.empty())
	{
		cout<<"No."<<endl;
		cout<<"FINISH"<<endl;
		return;
	}
	cout<<"Yes."<<endl;
	for(int i=0;i<(int)ans.size();i++)
	{
		cout<<ans[i]<<endl;
	}
	cout<<"FINISH"<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	while(cin>>n>>o1>>o2){solve();}
	return 0;
}