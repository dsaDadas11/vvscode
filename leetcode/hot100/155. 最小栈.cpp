/*
 * @Author: dsaDadas11
 * @Date: 2026-05-05 16:39:05
 * @LastEditTime: 2026-05-05 16:52:16
 * @Description: go for it!
 */

// 辅助栈存最小值
class MinStack {
public:

    stack<int> st,mst;
    int minn;
    MinStack() {
        while(!st.empty()) st.pop();
        while(!mst.empty()) mst.pop();
    }
    
    void push(int val) {
        if(st.empty()) minn=val;
        else minn=min(mst.top(),val);
        st.push(val);
        mst.push(minn);
    }
    
    void pop() {
        st.pop();
        mst.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mst.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */










/*

class MinStack {
public:

    multiset<int> se;
    stack<int> st;
    MinStack() {
        se.clear();
        while(!st.empty()) st.pop();
    }
    
    void push(int val) {
        se.insert(val);
        st.push(val);
    }
    
    void pop() {
        int val=st.top();
        st.pop();
        se.erase(se.find(val));
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return *se.begin();
    }
};
 */