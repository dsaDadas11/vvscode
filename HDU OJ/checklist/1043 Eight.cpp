/*
 * @Author: dsaDadas11
 * @Date: 2025-04-25 22:19:17
 * @LastEditTime: 2025-04-29 19:27:34
 * @Description: go for it!
 */
/*
 题目大意：
 相当于C 题的进阶版，目标棋局是固定的，12345678x，注意是多组输出

 解题思路：
 这道题的最优解法不是 A*算法，而是用目标棋局反向打表

 和 八数码难题不一样的地方
 1.在于这道题的 h函数只能用曼哈顿距离计算，用棋子不在目标位置的个数会 tle
 2.提前判断棋局是否无解，因为目标棋盘是全部正序的，
 我们可以观察到空格每上下移动对逆序对的贡献是+2，左右移动贡献为0，
 因此初始棋局的逆序对个数只能为偶数，
 只要初始棋盘的逆序对数量为奇数就是无解
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
//#define int ll
using namespace std;
constexpr int N=1e6+7;
constexpr int M=2e3+7;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
char dir[4]={'r','d','l','u'};
string s,t;
int calc(int x,int y)
{
    return x*3+y;
}
int h(string a) // 计算 h函数
{
    int ans=0;
    for(int i=0;i<9;i++)
    {
        if(a[i]=='x') continue;
        int t=a[i]-'1';
        ans+=abs(i/3-t/3)+abs(i%3-t%3);
    }
    return ans;
}
struct op
{
    string a;
    int stp;
    string ans;
    bool operator<(const op&that) const
    {
        // 维护小根堆
        return stp+h(a)>that.stp+h(that.a);
    }
};
bool check(int x,int y)
{
    return x>=0&&x<=2&&y>=0&&y<=2;
}
void bfs()
{
    t="12345678x";
    priority_queue<op> pq;
    unordered_set<string> se; // 记录棋局是否被访问
    pq.push({s,0,""});
    while(!pq.empty())
    {
        string v=pq.top().a;
        int stp=pq.top().stp;
        string res=pq.top().ans;
        pq.pop();
        if(h(v)==0) return cout<<res<<endl,void();
        int fx,fy;
        for(int i=0;i<=2;i++)
        {
            for(int j=0;j<=2;j++)
            {
                if(v[calc(i,j)]=='x') fx=i,fy=j;
            }
        }
        for(int i=0;i<4;i++)
        {
            int xx=fx+dx[i];
            int yy=fy+dy[i];
            if(!check(xx,yy)) continue;
            swap(v[calc(fx,fy)],v[calc(xx,yy)]);
            if(!se.count(v))
            {
                se.insert(v);
                pq.push({v,stp+1,res+dir[i]});
            }
            swap(v[calc(fx,fy)],v[calc(xx,yy)]);
        }
    }
}
void solve()
{
    char c;
    while(cin>>c)
    {
        s.push_back(c);
        for(int j=1;j<=2;j++)
        {
            cin>>c;
            s.push_back(c);
        }
        for(int i=1;i<=2;i++)
        {
            for(int j=0;j<=2;j++)
            {
                cin>>c;
                s.push_back(c);
            }
        }

        int cnt=0; // 记录逆序对数量，奇数无解
        for(int i=0;i<9;i++)
        {
            for(int j=i+1;j<9;j++)
            {
                if(s[i]=='x'||s[j]=='x') continue;
                if(s[i]>s[j]) cnt++;
            }
        }
        if(cnt%2) cout<<"unsolvable"<<endl;
        else bfs();
        s.clear();
    }
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; //cin>>T;
    while(T--){solve();}
    return 0;
}