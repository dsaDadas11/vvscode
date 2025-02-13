/*
 * @Author: dsaDadas11
 * @Date: 2024-10-09 22:05:45
 * @LastEditTime: 2024-10-09 22:07:45
 * @Description: go for it!
 */
/*
 解题思路：
 换行与行，列与列，但是本质上每一行和每一列的元素都是不变的，
 只要是不变的就合法，变就不合法了，
 用map存每一行和每一列的vector即可，
 不过要记得排下序使不同排列有相同的顺序
*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define int ll
using namespace std;
constexpr int N=2e5+7;
constexpr int M=2e3+7;
int n,m;
// 记录每一行每一列的元素
map<vector<int>,bool> row,col;
void solve()
{
    cin>>n>>m;
    // 清空一下
    row.clear(),col.clear();
    vector<vector<int> > a(n,vector<int>(m));
    vector<vector<int> > b(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>b[i][j];
        }
    }
    // 将a中每一行每一列元素记录下来
    for(int i=0;i<n;i++)
    {
        vector<int> v;
        for(int j=0;j<m;j++)
        {
            v.push_back(a[i][j]);
        }
        sort(v.begin(),v.end());
        row[v]=1;
    }
    for(int j=0;j<m;j++)
    {
        vector<int> v;
        for(int i=0;i<n;i++)
        {
            v.push_back(a[i][j]);
        }
        sort(v.begin(),v.end());
        col[v]=1;
    }
    // 在b中找
    for(int i=0;i<n;i++)
    {
        vector<int> v;
        for(int j=0;j<m;j++)
        {
            v.push_back(b[i][j]);
        }
        sort(v.begin(),v.end());
        if(row[v]==0)
        {
            cout<<"NO"<<endl;
            return;
        }
    }
    for(int j=0;j<m;j++)
    {
        vector<int> v;
        for(int i=0;i<n;i++)
        {
            v.push_back(b[i][j]);
        }
        sort(v.begin(),v.end());
        if(col[v]==0)
        {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1; cin>>T;
    while(T--){solve();}
    return 0;
}