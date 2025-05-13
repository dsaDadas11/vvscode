/*
 * @Author: dsaDadas11
 * @Date: 2025-04-20 17:23:04
 * @LastEditTime: 2025-04-20 17:23:50
 * @Description: go for it!
 */
/*
 数字前面可能莫名其妙多个 '-'号。。。
*/
class Solution {
public:
    string s;
    stack<int> num;
    stack<char> op;
    void calc()
    {
        int num1=num.top();
        num.pop();
        int num2=num.top();
        num.pop();
        char p=op.top();
        op.pop();
        switch(p)
        {
        case '+':
            num.push(num1+num2);
            break;
            
        case '-':
            num.push(num2-num1);
            break;
            
        case '*':
            num.push(num1*num2);
            break;
            
        case '/':
            num.push(num2/num1);
            break;
            
        default:
            break;
        }
    }
    int calculate(string s) {
        map<char,int> pri;
        pri['+']=pri['-']=1;
        pri['*']=pri['/']=2;
        
        num.push(0);
        for(int i=0;i<s.size();i++)
        {
            while(s[i]==' ') s.erase(s.begin()+i);
        }
        //cout<<s<<endl;
        //return 0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>='0'&&s[i]<='9')
            {
                int j;
                string tmp="";
                for(j=i;j<s.size();j++)
                {
                    if(s[j]>='0'&&s[j]<='9')
                    {
                        tmp.push_back(s[j]);
                    }
                    else
                    {
                        j--;
                        break;
                    }
                }
                i=j;
                num.push(stol(tmp));
            }
            else
            {
                if(s[i]=='(')
                {
                    op.push(s[i]);
                    if(s[i+1]=='+'||s[i+1]=='-') num.push(0);
                    continue;
                }
                else if(s[i]==')')
                {
                    while(op.top()!='(') calc();
                    op.pop();
                }
                else
                {
                    while(!op.empty()&&pri[op.top()]>=pri[s[i]]) calc();
                    op.push(s[i]);
                }
                
            }
        }
        while(!op.empty()) calc();
        return num.top();
    }
};