/*
 * @Author: dsaDadas11
 * @Date: 2024-07-22 15:54:25
 * @LastEditTime: 2024-07-22 15:54:28
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=5e5+7;
constexpr int M=2e3+7;
string s;
void solve()
{
	cin>>s;
	int pos1=s.find("://");
	string ans1=s.substr(0,pos1);
	pos1+=3;
	int pos2=s.find("/",pos1);
	string ans2=s.substr(pos1,pos2-pos1);
	pos2++;
	int p=pos2;
	vector<string> ans3;
	while((p=s.find("/",p))!=s.npos)
	{
		ans3.push_back(s.substr(pos2,p-pos2));
		pos2=p+1;
		p++;
	}
	cout<<ans1<<endl;
	cout<<ans2<<endl;
	int len=ans3.size();
	for(int i=0;i<len;i++)
	{
		string t=ans3[i];
		if(t.find("=")!=t.npos)
		{
			cout<<t<<endl;
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}