private:
        stack<int> s1;
        stack<int> s2;

public:
    /** Initialize your data structure here. */
    MyQueue() {
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (s2.empty()) {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int res = s2.top();
        s2.pop();
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        int res = this->pop();
        s2.push(res);
        return res;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty() && s2.empty();
    }