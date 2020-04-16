/*ջ��ѹ��͵�������*/

/*�ж�popped�����ǲ���pushed�ĳ�ջ����*/

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> res;

        int j = 0;
        for(int i = 0; i < pushed.size();i++)
        {
            res.push(pushed[i]);
            while(!res.empty() && j < popped.size() && res.top() == popped[j])
            {
                res.pop();
                j++;
            }
        }
        return res.empty();
    }
};