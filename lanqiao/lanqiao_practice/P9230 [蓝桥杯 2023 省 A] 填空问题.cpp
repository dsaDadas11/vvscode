/*
 * @Author: dsaDadas11
 * @Date: 2024-04-11 21:56:47
 * @LastEditTime: 2024-04-11 22:02:01
 * @Description: go for it!
 */
#include<bits/stdc++.h>
using namespace std;

char pid;
int main() {
    cin >> pid;
    if(pid == 'A')
        puts("4430091");
    else
        puts("8335366");
    return 0;
}
/*
A.
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
void solve()
{
	string s;
	int ans=0;
	for(int i=1;i<=100000000;i++)
	{
		s=to_string(i);
		int len=s.size();
		if(len%2) continue;
		int ans1=0,ans2=0;
		for(int j=0;j<len/2;j++) ans1+=s[j]-'0';
		for(int j=len/2;j<len;j++) ans2+=s[j]-'0';
		if(ans1==ans2) ans++;
	}
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}

B.(dp写法)
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int dp[37][17];
int ans;
void solve()
{
	dp[0][0]=1;
	for(int i=1;i<=30;i++)
	{
		for(int j=0;j<=9;j++)
		{
			if(j==0)
			{
				for(int k=0;k<=9;k++)
				{
					dp[i][j]+=dp[i-1][k];
				}
			}
			else dp[i][j]=dp[i-1][j-1];
		}
		ans+=dp[i][7];
	}
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}

B.(dfs写法)
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int ans;
void dfs(int x,int sc)
{
	if(sc==70) ans++;
	if(sc==100||x>30) return;
	dfs(x+1,sc+10);
	dfs(x+1,0);
}
void solve()
{
	dfs(1,0);
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}
*/