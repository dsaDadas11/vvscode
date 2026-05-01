/*
 * @Author: dsaDadas11
 * @Date: 2026-04-21 11:29:29
 * @LastEditTime: 2026-04-21 17:17:59
 * @Description: go for it!
 */
class Solution {
static const int N=1e6+7;
static const int M=300+7;
int n,m;
int c[M][M];
bool check(int x)
{
	for(int i=1;i<=n-x+1;i++)
	{
		int sum=0;
		// 先放 x*x 个，然后滑窗
		for(int k1=i;k1<=i+x-1;k1++)
		{
			// 先放 x个
			for(int k2=1;k2<=x;k2++)
			{
				sum+=c[k1][k2];
			}
		}
		if(sum==x*x) return 1;
		
	//	if(x==3) cout<<"i: "<<i<<"    sum: "<<sum<<endl; 
		
		int l=1,r=x;
		while(r<m)
		{
			r++;
			for(int k1=i;k1<=i+x-1;k1++)
			{
				sum+=c[k1][r];
				sum-=c[k1][l];
			}
			l++;
			//if(x==3) cout<<"i: "<<i<<"    sum: "<<sum<<endl; 
			if(sum==x*x) return 1;
		}
	}
	return 0;
}
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        n=matrix.size();
        if(n==0) return 0;
        m=matrix[0].size();
        bool flag=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                c[i][j]=matrix[i-1][j-1]-'0';
                if(c[i][j]) flag=1;
            }
        }
        int l=1,r=min(n,m);
        while(l<r)
        {
            int mid=(l+r+1)>>1;
            if(check(mid)) l=mid;
            else r=mid-1;

            cout<<"l: "<<check(3)<<endl;
        }
        if(flag) return l*l;
        else return 0;
    }
};

/*
dp，时间复杂度 O(n*m)
class Solution {
static const int N=1e6+7;
static const int M=300+7;
int n,m;
int c[M][M];
int f[M][M];
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        n=matrix.size();
        if(n==0) return 0;
        m=matrix[0].size();
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                c[i][j]=matrix[i-1][j-1]-'0';
            }
        }
        int ans=0;

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(c[i][j]) f[i][j]=min({f[i-1][j],f[i][j-1],f[i-1][j-1]})+1;
                ans=max(ans,f[i][j]);
            }
        }

        return ans*ans;
    }
};
*/