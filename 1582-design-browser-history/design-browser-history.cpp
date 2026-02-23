class BrowserHistory {
public:
    stack<string>st1, st2;
    BrowserHistory(string homepage) {
        st1.push(homepage);
    }
    
    void visit(string url) {
        while(!st2.empty()){
            st2.pop();
        }
        st1.push(url);
    }
    
    string back(int steps) {
        int count = 0;
        while(count<steps && st1.size()>1){
            st2.push(st1.top());
            st1.pop();
            count++;
        }
        return st1.top();
    }
    
    string forward(int steps) {
        int count = 0;
        while(count<steps && !st2.empty()){
            st1.push(st2.top());
            st2.pop();
            count++;
        }
        return st1.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */