//����ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ����СԪ�ص� min �����ڸ�ջ�У�
//���� min��push �� pop ��ʱ�临�Ӷȶ��� O(1)��
//-2 0 -3
class MinStack {
private:
    stack<int> s1;
    stack<int> s2;
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        s1.push(x);

        if(s2.empty() || s2.top() > x)
        {
            s2.push(x);
        }
        else
        {
            s2.push(s2.top());
        }
    }
    
    void pop() {
        s1.pop();
        s2.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int min() {
        return s2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */