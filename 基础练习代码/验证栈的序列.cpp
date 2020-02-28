/*���룺pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
�����true
���ͣ����ǿ��԰�����˳��ִ�У�
push(1), push(2), push(3), push(4), pop() -> 4,
push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
*/
//��֤ջ������
//˼�룺��ջ����ջ�ȶ���poppedÿ��Ԫ�أ���ͬ��ջ������ͬ�����Ƚϣ�������ջΪ�գ���������ȷ

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int size = pushed.size();
        int k = 0;
        
        for(int i = 0; i < size; i++)
        {
            s.push(pushed[i]);//push����һ����

            //�жϵ�һ���Ƿ���popped�е�һ�����Ƿ����
            while((!s.empty()) && (k < size) && s.top() == popped[k])
            {
                s.pop();
                k++;
            }
        }
        if(!s.empty())
        {
            return false;
        }
        return true;
    }
};