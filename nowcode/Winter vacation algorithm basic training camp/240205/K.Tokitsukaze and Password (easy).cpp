/*
 * @Author: dsaDadas11
 * @Date: 2024-02-06 19:13:55
 * @LastEditTime: 2024-02-06 19:14:01
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
	int n; cin>>n;
	string s,y; cin>>s>>y;
	set<string> ans;
	for(char a='0';a<='9';a++)
	{
		for(char b='0';b<='9';b++)
		{
			for(char c='0';c<='9';c++)
			{
				for(char d='0';d<='9';d++)
				{
					for(char _='0';_<='9';_++)
					{
						set<char>se{a,b,c,d};
						if(se.size()!=4) continue;
						string s1=s;
						for(auto &x:s1)
						{
							if(x=='a') x=a;
							if(x=='b') x=b;
							if(x=='c') x=c;
							if(x=='d') x=d;
							if(x=='_') x=_;
						}
						if(n>1&&s1[0]=='0') continue;
						if(s1<=y&&stoi(s1)%8==0) ans.insert(s1);
					}
				}
			}
		}
	}
	cout<<ans.size()<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}