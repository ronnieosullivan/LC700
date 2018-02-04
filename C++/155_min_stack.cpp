// Preferred solution: 
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        minVal = INT_MAX;
    }
    
    void push(int x) {
        if (x <= minVal) {
            st.push(minVal);
            minVal = x;
        }
        st.push(x);
    }
    
    void pop() {
        int t = st.top(); st.pop();
        if (t == minVal) {
            minVal = st.top(); st.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minVal;
    }
private:
    stack<int> st;
    int minVal;
};

// Solution 2:
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        st.push({x, st.empty() ? x : min(x, st.top().second)});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
private:
    stack<pair<int, int>> st;
};