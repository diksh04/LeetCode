class BrowserHistory {
public:
    stack<string>st1,st2;
    BrowserHistory(string homepage) {
        st1.push(homepage);
    }
    
    void visit(string url) {
        st1.push(url);
        while(!st2.empty())
        {
            st2.pop();
        }
    }
    
    string back(int steps) {
        string ans = "";
        while(st1.size()>1 && steps--)
        {
            st2.push(st1.top());
            st1.pop();
        }
        ans = st1.top();
        return ans;
    }
    
    string forward(int steps) {
        string ans = "";
        while(!st2.empty() && steps--)
        {
            st1.push(st2.top());
            st2.pop();
        }
        ans = st1.top();
        return ans;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */