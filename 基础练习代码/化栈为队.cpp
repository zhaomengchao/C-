//实现一个MyQueue类，该类用两个栈来实现一个队列。
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        if(s1.empty())
        {
            s1.push(x);
        }
        else
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            s1.push(x);//将x放入数据栈
            while(!s2.empty())
            {
                s1.push(s2.top());
                s2.pop();
            }
        }
        
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int res = peek();
        s1.pop();
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        return s1.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        if(s1.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    private:
    stack<int> s1;//数据栈
    stack<int> s2;//辅助栈
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */