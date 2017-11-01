/*
Problem Description:
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
*/

class MinStack {
public:
    vector<int> stack,min_values;
    /** initialize your data structure here. */
    MinStack() {
        stack.clear();
        min_values.emplace_back(INT_MAX);
    }
    
    void push(int x) {
        stack.emplace_back(x);
        min_values.emplace_back(min(min_values[min_values.size()-1],x));
    }
    
    void pop() {
        stack.erase(stack.begin()+stack.size()-1);
        min_values.erase(min_values.begin()+min_values.size()-1);
    }
    
    int top() {
        return stack[stack.size()-1];
    }
    
    int getMin() {
        return min_values[min_values.size()-1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */