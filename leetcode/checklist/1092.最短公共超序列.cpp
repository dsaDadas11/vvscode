/*
 * @Author: dsaDadas11
 * @Date: 2024-09-03 19:01:18
 * @LastEditTime: 2024-09-03 20:23:14
 * @Description: go for it!
 */
/*
 一开始把i,j看错了debug半天...
 解题思路：
 首先我们找这两个字符串的最长公共子序列,
 然后根据dp状态转移方程的性质添加到答案字符串中,
 最后反向输出即可
*/
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int lena=str1.size(),lenb=str2.size();
        str1=' '+str1,str2=' '+str2;
        int dp[1007][1007]={0};
        for(int i=1;i<=lena;i++)
        {
            for(int j=1;j<=lenb;j++)
            {
                if(str1[i]==str2[j]) dp[i][j]=dp[i-1][j-1]+1;
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        string s="";
        int i=lena,j=lenb;
        while(i>0&&j>0)
        {
            if(str1[i]==str2[j])
            {
                s.push_back(str1[i]);
                i--,j--;
            }
            else if(dp[i][j]==dp[i-1][j])
            {
                s.push_back(str1[i]);
                i--;
            }
            else if(dp[i][j]==dp[i][j-1])
            {
                s.push_back(str2[j]);
                j--;
            }
        }
        for(int k=i;k>=1;k--) s.push_back(str1[k]);
        for(int k=j;k>=1;k--) s.push_back(str2[k]);
        reverse(s.begin(),s.end());
        return s;
    }
};