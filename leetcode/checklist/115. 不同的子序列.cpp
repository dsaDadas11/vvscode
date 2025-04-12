/*
 * @Author: dsaDadas11
 * @Date: 2025-03-26 14:01:19
 * @LastEditTime: 2025-03-26 14:03:57
 * @Description: go for it!
 */
/*
 解题思路：
 用 dp[i][j]表示 s的前 i个字母能匹配 t的前 j个字母
 那么有 if(s[i]==t[j]) dp[i][j]+=dp[i-1][j-1]+dp[i-1][j]
 当 s[i]!=t[j]时，dp[i][j]只能由 s的前一个字符 dp[i-1][j]转移过来

 注意初始化边界为 dp[i][0]=1
*/
class Solution {
public:
    int numDistinct(string s, string t) {
        const long long mod=1e9+7;
        long long len1=s.length();
        long long len2=t.length();
        s=' '+s,t=' '+t;


        vector<vector<long long> > dp(len1+5,vector<long long>(len2+5));

        for(int i=0;i<=len1;i++) {
            dp[i][0]=1;
        }

        for(int i=1;i<=len1;i++) {
            for(int j=1;j<=len2;j++) {
                if(s[i]==t[j]) dp[i][j]+=dp[i-1][j-1];
                dp[i][j]+=dp[i-1][j];
                dp[i][j]%=mod;
            }
        }

        return dp[len1][len2]%mod;
    }
};