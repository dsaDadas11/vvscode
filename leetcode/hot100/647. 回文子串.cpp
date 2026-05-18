/*
 * @Author: dsaDadas11
 * @Date: 2026-05-17 18:03:11
 * @LastEditTime: 2026-05-17 19:08:36
 * @Description: go for it!
 */
// 暴力 O(n^3)
class Solution {
public:
    int countSubstrings(string s) {
        int len=s.size();
        s=' '+s;
        int ans=0;
        for(int i=1;i<=len;i++)
        {
            for(int j=i;j<=len;j++)
            {
                int k1=i,k2=j;
                while(s[k1]==s[k2]&&k1<=k2) k1++,k2--;
                if(k1>k2) ans++;
            }
        }
        return ans;
    }
};

/*
 中心扩展法 O(n^2)
class Solution {
public:
    int countSubstrings(string s) {
        int len=s.size();
        s=' '+s;
        int ans=0;
        for(int i=1;i<=len;i++)
        {
            // 奇数位
            ans++;
            int l=i-1,r=i+1;
            while(l>=1&&r<=len&&s[l]==s[r]) l--,r++,ans++;

            // 偶数位 
            l=i-1,r=i;
            while(l>=1&&r<=len&&s[l]==s[r]) l--,r++,ans++;
        }
        return ans;
    }
};


 manacher O(n)
class Solution {
public:
    int countSubstrings(string s) {
        string t="$#";
        for(int i=0;i<s.size();i++)
        {
            t+=s[i];
            t+='#';
        }
        t+='&';

        vector<int> p(t.size()+5,0);
        int r=0,c;
        for(int i=1;i<t.size()-1;i++)
        {
            if(i<r) p[i]=min(p[2*c-i],r-i);
            else p[i]=1;
            while(t[i-p[i]]==t[i+p[i]]) p[i]++;
            if(i+p[i]>r)
            {
                r=i+p[i];
                c=i;
            }
        }

        int ans=0;
        for(int i=1;i<t.size()-1;i++) ans+=p[i]/2;
        return ans;
    }
};
*/