/*
 * @Author: dsaDadas11
 * @Date: 2024-12-05 23:50:18
 * @LastEditTime: 2024-12-06 21:42:27
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
int m;
int cnt6,cnt2,cnt;
void solve()
{
    cin>>s;
    cnt=0,cnt2=0,cnt6=0;
    for(int i=0;i<(int)s.size();i++)
    {
        cnt+=(s[i] - '0');
    }
    if(cnt%9== 0) 
    {
        cout<<"YES"<<endl;
        return;
    }

    m=cnt%9;

    for(int i=0;i<(int)s.size();i++)
    {
        int t=s[i]-'0';
        if(t==2) cnt2++;
        else if(t==3) cnt6++;
    }

    while(m%9!=0)
    {
        if(cnt2==0&&cnt6==0)
        {
            break;
        }

        if(cnt2>=2&&(m+4)%9==0)
        {
            cnt2-=2;
            m=(m+4)%9;
        }
        else if(cnt2>=1&&(m+2)%9==0)
        {
            cnt2-=1;
            m=(m+2)%9;
        }
        else if(cnt6>0)
        {
            cnt6-=1;
            m = (m + 6) % 9;
        }
        else 
        {
            cnt2 -= 1;
            m = (m + 2) % 9;
        }
        m = m % 9;
    }
    if (m == 0) cout << "YES" << '\n';
    else cout << "NO" << '\n';

}

signed main()
{
    ios :: sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int TT = 1;
     cin >> TT;
    while(TT--)
    {
        solve();
    }
    return 0;
}

/*
只有2,3能变，并且贡献分别是 2 6
每加九次贡献就会重置，就相当于   (a + 9*x) % 9 = a
因此只需要算 0 - 9 ，0 - 10 也行

#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
string s;
void solve()
{
	cin>>s;
	int n=s.size();
	s=' '+s;
	int sum=0;
	int cnt2=0,cnt3=0;
	for(int i=1;i<=n;i++)
	{
		sum+=s[i]-'0';
		if(s[i]=='2') cnt2++;
		else if(s[i]=='3') cnt3++;
		sum%=9;
	}
	for(int i=0;i<=min(cnt2,10LL);i++)
	{
		for(int j=0;j<=min(cnt3,10LL);j++)
		{
			int tmp=sum+i*2+j*6;
			if(tmp%9==0)
			{
				cout<<"YES"<<endl;
				return;
			}
		}
	}
	cout<<"NO"<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1; cin>>T;
	while(T--){solve();}
	return 0;
}
*/