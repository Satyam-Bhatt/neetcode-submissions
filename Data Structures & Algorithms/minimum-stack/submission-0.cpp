class MinStack {
public:

    vector<int> stackV;

    bool allocateMin = true;
    int minValue = 0;

    MinStack() {
        
    }
    
    void push(int val) {
        if(allocateMin || val < minValue) minValue = val;
        allocateMin = false;
        stackV.push_back(val);
    }
    
    void pop() {
        stackV.pop_back();
        // DO something if min is popped
    }
    
    int top() {
        return stackV[stackV.size() - 1];
    }
    
    int getMin() {
        return minValue;
    }
};
