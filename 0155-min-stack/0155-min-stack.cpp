class MinStack {
    stack<int>s1;
    stack<int>s2;
public:
    MinStack() {
        
    }
    
    void push(int x) {
        if(s1.size()==0){
            s1.push(x);
            s2.push(x);
        }
        else{
            s1.push(x);
            if(x<=s2.top())
            s2.push(x);
            
        }
    }
    
    void pop() {
        if(s1.size()==0)
        return;
        else{
            int ele=s1.top();
            s1.pop();
            if(ele==s2.top())
            s2.pop();
        }
 
    }
    
    int top() {
        if(s1.size()==0)
            return -1;
        return s1.top();
        
    }
    
    int getMin() {
         if(s2.empty())
        return -1;
    return s2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */