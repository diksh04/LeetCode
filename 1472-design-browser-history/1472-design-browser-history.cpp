class BrowserHistory {
public:
    class Node{
        public:
            string url;
            Node* next;
            Node* prev;
            Node(string url)
            {
                this->url = url;
                next = NULL;
                prev = NULL;
            }
    };
    Node* curr;
    BrowserHistory(string homepage) {
        curr = new Node(homepage);
    }
    
    void visit(string url) {
        Node* temp = new Node(url);
        curr->next = temp;
        temp->prev = curr;
        curr = curr->next;
    }
    
    string back(int steps) {
        while(curr->prev!=NULL && steps > 0)
        {
            steps--;
            curr = curr->prev;
        }
        return curr->url;
    }
    
    string forward(int steps) {
        while(curr->next!=NULL && steps > 0)
        {
            steps--;
            curr = curr->next;
        }
        return curr->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */