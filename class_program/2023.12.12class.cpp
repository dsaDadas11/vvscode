#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
const int N=1e6+7;
const int M=2e3+7;
class Point
{
    protected:
        int x,y;
    public:
        friend ostream &operator<<(ostream &out,Point &p);
        friend istream &operator>>(istream &in,Point &p);
};
istream &operator>>(istream &in,Point &p)
{
    in>>p.x>>p.y;
    return in;
}
ostream &operator<<(ostream &out,Point &p)
{
    out<<p.x<<" "<<p.y;
    return out;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	Point o;
    cin>>o; //相当于operator>>(cin,o); 编译器看到的是operator
    operator<<(cout,o)<<endl; //相当于cout<<o<<endl;
    cout<<o<<endl;
	return 0;
}