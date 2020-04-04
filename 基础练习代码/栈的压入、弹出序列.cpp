/*���������������У���һ�����б�ʾջ��ѹ��˳��
���жϵڶ��������Ƿ�Ϊ��ջ�ĵ���˳��
����ѹ��ջ���������־�����ȡ�
���磬���� {1,2,3,4,5} ��ĳջ��ѹջ���У�
���� {4,5,3,2,1} �Ǹ�ѹջ���ж�Ӧ��һ���������У�
�� {4,3,5,1,2} �Ͳ������Ǹ�ѹջ���еĵ������С�
*/
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = popped.size();
        int m = pushed.size();
        if(n != m) return false;
        stack<int> sk;
        int j = 0;
        for(int i = 0; i < m; i++){
            sk.push(pushed[i]);
            while(!sk.empty() && j < n && popped[j] == sk.top()){
                sk.pop();
                j++;
            }
        }
        return sk.empty();
    }
};

