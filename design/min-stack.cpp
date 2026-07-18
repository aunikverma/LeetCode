class MinStack {
    stack<long long> s;
    long long mini;

public:
    MinStack() { mini = INT_MAX; }

    void push(int val) {
        if (s.empty()) {
            s.push(val);
            mini = val;
        } else {
            if (val < mini) {
                long long v = 2LL * val - mini;
                s.push(v);
                mini = val;
            } else {
                s.push(val);
            }
        }
    }

    void pop() {
        if (s.empty())
            return;
        else {
            long long curr = s.top();
            s.pop();
            if (curr < mini) {
                mini = 2 * mini - curr;
            }
        }
        if (s.empty()) {
            mini = INT_MAX;
        }
    }

    int top() {
        if (s.empty())
            return -1;
        long long curr = s.top();
        if (curr < mini) {
            return mini;
        } else {
            return curr;
        }
    }

    int getMin() {
        if (s.empty())
            return -1;
        return mini;
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