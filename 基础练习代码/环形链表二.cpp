/*����һ��������������ʼ�뻷�ĵ�һ���ڵ㡣?��������޻����򷵻�?null��

Ϊ�˱�ʾ���������еĻ�������ʹ������ pos ����ʾ����β���ӵ������е�λ�ã������� 0 ��ʼ����
 ��� pos �� -1�����ڸ�������û�л���

˵�����������޸ĸ���������*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;

            if(fast == slow)
            {
                fast = head;//������ָ������ʱ���ÿ�Ļָ���ͷ�ڵ㣬�߷ǻ�����
                while(fast != slow)
                {
                    fast = fast->next;
                    slow = slow->next;
                }
                return fast;
                break;
            }
        }
    return nullptr;
    }
};