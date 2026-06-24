class MinStack {
public:

    vector<int> stackV;
    stack<int> minStack;

    int minValue = 0;

    MinStack() {
        
    }
    
    void push(int val) {
        if(minStack.empty()) minStack.push(val);
        else if(val <= minStack.top()) minStack.push(val);
        stackV.push_back(val);
    }
    
    void pop() {

        if(minStack.top() == stackV[stackV.size() - 1]) minStack.pop();
        stackV.pop_back();
        
    }
    
    int top() {
        return stackV[stackV.size() - 1];
    }
    
    int getMin() {
        return minStack.top();
    }
};
