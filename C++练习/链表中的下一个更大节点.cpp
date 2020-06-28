  /*�����е���һ������ڵ�
  https://leetcode-cn.com/problems/next-greater-node-in-linked-list/
  */
  vector<int> nextLargerNodes(ListNode* head) {

        //���������������
        vector<int> res;
        while (head)
        {
            res.push_back(head->val);
            head = head->next;
        }

        stack<int> stack;

        //�����������
        for (int i = (int)res.size() - 1; i >= 0; --i)
        {
            int cur = res.at(i); //���ݴ浱ǰԪ��

            while (!stack.empty() && cur >= stack.top()) //ע��: ���ںŲ����� ����ʱҲ��Ҫ��ջ ���������ϸ���ڵ���
            {
                stack.pop();  //��̭С�� ���¸����
            }
            
            res.at(i) = (stack.empty() ? 0 : stack.top()); //ջ�� �ұ�û�и����

            stack.push(cur);
        }

        return res;
    }
};
//����ջ����ʹ�ø������飬ֱ���޸Ľ������ ʱ�临�Ӷ�O(N) �ռ临�Ӷ�O(N)
