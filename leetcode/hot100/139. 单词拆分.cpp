/*
 * @Author: dsaDadas11
 * @Date: 2026-05-17 16:28:22
 * @LastEditTime: 2026-05-17 16:42:24
 * @Description: go for it!
 */
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> f(s.size()+7,0);
        for(int i=0;i<s.size();i++)
        {
            for(int j=0;j<wordDict.size();j++)
            {
                string t=wordDict[j];
                if(i+t.size()-1>s.size()-1) continue;
                bool flag=1;
                for(int k=0;k<t.size();k++)
                {
                    if(s[i+k]!=t[k])
                    {
                        flag=0;
                        break;
                    } 
                }
                // cout<<t<<' '<<flag<<endl;
                if(flag&&!f[i+t.size()-1]) // 防止被其他点覆盖
                {
                    f[i+t.size()-1]=(i==0?1:f[i-1]==1);
                }
            }
        }

        // for(int i=0;i<s.size();i++) cout<<f[i]<<' ';
        // cout<<endl;
        return f[s.size()-1];
    }
};

/*
 dp做法，用 j来划分 [0,i-1]的位置，判断 [0,j-1] [j,i-1]能够拼接
 dp[i]表示 前 i-1个位置是否匹配完成
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> se;
        for(int j=0;j<wordDict.size();j++)
        {
            se.insert(wordDict[j]);
        }
        vector<int> dp(s.size()+7,0);
        dp[0]=1;
        for(int i=1;i<=s.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(dp[j]&&se.find(s.substr(j,i-j))!=se.end())
                {
                    dp[i]=1;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};
*/