class MinStack {
public:
    stack<int>mainStack;
    stack<int>minStack;
    MinStack() {
        //Djjjjjj
    }
    
    void push(int val) {
        if(minStack.empty() || minStack.top()>=val){
            minStack.push(val);
            mainStack.push(val);
        }else{
            mainStack.push(val);
        }
    }   
    
    void pop() {
        if(!minStack.empty() && mainStack.top()==minStack.top()){
            mainStack.pop();
            minStack.pop();
        }else{
            mainStack.pop();
        }
    }
    
    int top() {
        return mainStack.top();
    }
    
    int getMin() {
        return minStack.top();
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