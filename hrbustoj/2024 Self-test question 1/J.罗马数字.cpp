/*
 * @Author: dsaDadas11
 * @Date: 2024-03-11 16:05:35
 * @LastEditTime: 2024-03-11 16:05:40
 * @Description: go for it!
 */
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e4+7;
constexpr int M=2e3+7;
void solve()
{
	string digits[107]={"","I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
	int number[107]={N,1,4,5,9,10,40,50,90,100,400,500,900,1000};
	int n;
	vector<string> ans;
	ans.push_back(" ");
	for(int i=1;i<=3999;i++)
	{
		string s="";
		int t=i;
		for(int j=13;j>=1;j--)
		{
			if(t>=number[j])
			{
				t-=number[j];
				s+=digits[j];
				j++;
			}
		}
		ans.push_back(s);
	}
	while(cin>>n)
	{
		cout<<ans[n]<<endl;
	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; //cin>>T;
	while(T--){solve();}
	return 0;
}