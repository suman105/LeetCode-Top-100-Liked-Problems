class MedianFinder {
    private:
        priority_queue<int> left_half; // Max-Heap (stores smaller half)
        priority_queue<int, vector<int>, greater<int>> right_half; // Min-Heap (stores larger half)
    
    public:
        MedianFinder() {}
    
        void addNum(int num) {
            if (left_half.empty() || num <= left_half.top()) {
                left_half.push(num); // Add to max-heap
            } else {
                right_half.push(num); // Add to min-heap
            }
    
            // Balance the heaps (size difference should be at most 1)
            if (left_half.size() > right_half.size() + 1) {
                right_half.push(left_half.top());
                left_half.pop();
            } else if (right_half.size() > left_half.size()) {
                left_half.push(right_half.top());
                right_half.pop();
            }
        }
    
        double findMedian() {
            if (left_half.size() > right_half.size()) {
                return left_half.top(); // Odd count, median is top of max-heap
            } else {
                return (left_half.top() + right_half.top()) / 2.0; // Even count, median is avg of tops
            }
        }
    };
    