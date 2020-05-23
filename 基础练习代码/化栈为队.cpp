//ʵ��һ��MyQueue�࣬����������ջ��ʵ��һ�����С�
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
            s1.push(x);//��x��������ջ
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
    stack<int> s1;//����ջ
    stack<int> s2;//����ջ
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */