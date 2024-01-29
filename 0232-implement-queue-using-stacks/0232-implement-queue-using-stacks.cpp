class MyQueue {
public:
    stack<int>mainS,helperS;
    MyQueue() {
        
    }
    
    void push(int x) {
        mainS.push(x);
    }
    
    int pop() {
        while(mainS.size()>1)
        {
            int val = mainS.top();
            mainS.pop();
            helperS.push(val);
        }
        int rem = mainS.top();
        mainS.pop();
        while(helperS.size()>0)
        {
            int val = helperS.top();
            helperS.pop();
            mainS.push(val);
        }
        return rem;
    }
    
    int peek() {
        while(mainS.size()>1)
        {
            int val = mainS.top();
            mainS.pop();
            helperS.push(val);
        }
        int rem = mainS.top();
        mainS.pop();
        helperS.push(rem);
        while(helperS.size()>0)
        {
            int val = helperS.top();
            helperS.pop();
            mainS.push(val);
        }
        return rem;
    }
    
    bool empty() {
        return mainS.size()==0;
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