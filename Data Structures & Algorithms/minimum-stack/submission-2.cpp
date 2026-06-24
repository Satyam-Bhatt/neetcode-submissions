class MinStack {
   public:
    stack<int> stackV;
    stack<int> minStack;

    MinStack() {}

    void push(int val) {
        if (minStack.empty())
            minStack.push(val);
        else if (val <= minStack.top())
            minStack.push(val);
        stackV.push(val);
    }

    void pop() {
        if (minStack.top() == stackV.top()) minStack.pop();
        stackV.pop();
    }

    int top() { return stackV.top(); }

    int getMin() { return minStack.top(); }
};
