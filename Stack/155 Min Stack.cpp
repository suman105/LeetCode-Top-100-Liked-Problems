class MinStack {
    private:
        stack<pair<int,int>> s;
    public:
        MinStack() {
        }
        
        void push(int val) {
            int minVal = s.empty() ? val : min(val, s.top().second);
            s.push({val, minVal});
        }
        
        void pop() {
            s.pop();
        }
        
        int top() {
            return s.top().first;
        }
        
        int getMin() {
            return s.top().second;
        }
    };