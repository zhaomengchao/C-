class MaxQueue {
    queue<int> q;
    deque<int> p;
public:
    MaxQueue() {
    }
    
    int max_value() {
        if (p.empty())
            return -1;
        return p.front();
    }
    
    void push_back(int value) {
        while (!p.empty() && p.back() < value) {
            p.pop_back();
        }
        p.push_back(value);
        q.push(value);
    }
    
    int pop_front() {
        if (q.empty())
            return -1;
        int ans = q.front();
        if (ans == p.front()) {
            p.pop_front();
        }
        q.pop();
        return ans;
    }
};