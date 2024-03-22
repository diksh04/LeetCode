class MyQueue {
public:
    stack<int>st1,st2;
    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        while(st1.size()>1)
        {
            int val = st1.top();
            st1.pop();
            st2.push(val);
        }
        int elm = st1.top();
        st1.pop();
        while(!st2.empty())
        {
            int val = st2.top();
            st2.pop();
            st1.push(val);
        }
        return elm;
    }
    
    int peek() {
        while(st1.size()>1)
        {
            int val = st1.top();
            st1.pop();
            st2.push(val);
        }
        int elm = st1.top();
        st1.pop();
        st2.push(elm);
        while(!st2.empty())
        {
            int val = st2.top();
            st2.pop();
            st1.push(val);
        }
        return elm;
    }
    
    bool empty() {
        return st1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */