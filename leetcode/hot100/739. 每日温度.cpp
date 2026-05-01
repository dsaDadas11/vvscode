/*
 * @Author: dsaDadas11
 * @Date: 2026-04-21 10:50:17
 * @LastEditTime: 2026-04-21 11:01:16
 * @Description: go for it!
 */
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();

        vector<vector<int>> pos(107);
        for (int i = 0; i < n; ++i) {
            pos[temperatures[i]].push_back(i);
        }

        vector<int> ans(n, 0);
        for (int i = 0; i < n; ++i) {
            int curTemp = temperatures[i];

            for (int j = curTemp + 1; j <= 100; ++j) {
                if(pos[j].size()==0) continue;
                int l=0,r=pos[j].size()-1;
                //if(i==3) cout<<"l: "<<l<<' '<<r<<endl;
                while(l<r)
                {
                    int mid=(l+r)>>1;
                    if(pos[j][mid]<i) l=mid+1;
                    else r=mid;
                }
                //if(i==3) cout<<"l: "<<l<<endl;
                l=pos[j][l];
                if(l<=i) continue;
                if(!ans[i]) ans[i]=l-i;
                else ans[i]=min(ans[i],l-i);
            }
        }
        return ans;
    }
};


/*
单调栈解法：
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty()&&temperatures[st.top()]<temperatures[i]) ans[st.top()]=i-st.top(),st.pop();
            st.push(i);
        }
        return ans;
    }
};
*/