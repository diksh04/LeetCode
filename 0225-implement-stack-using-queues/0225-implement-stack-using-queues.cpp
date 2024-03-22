class MyStack {
public:
    queue<int>q1,q2;
    MyStack() {
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        while(q1.size()>1)
        {
            int val = q1.front();
            q2.push(val);
            q1.pop();
        }
        int val = q1.front();
        q1.pop();
        while(!q2.empty())
        {
            int val = q2.front();
            q1.push(val);
            q2.pop();
        }
        return val;
    }
    
    int top() {
        while(q1.size()>1)
        {
            int val = q1.front();
            q2.push(val);
            q1.pop();
        }
        int val = q1.front();
        q1.pop();
        q2.push(val);
        while(!q2.empty())
        {
            int val = q2.front();
            q1.push(val);
            q2.pop();
        }
        return val;
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */