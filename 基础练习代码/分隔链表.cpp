/*����һ�������һ���ض�ֵ x����������зָ���ʹ������С�� x �Ľڵ㶼�ڴ��ڻ���� x �Ľڵ�֮ǰ��
 ��Ӧ����������������ÿ���ڵ�ĳ�ʼ���λ�á�
 ʾ��:
 ����: head = 1->4->3->2->5->2, x = 3
 ���: 1->2->2->4->3->5*/

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
    ListNode* partition(ListNode* head, int x) {
        ListNode* start  = new ListNode(0);
        ListNode* end = new ListNode(0);

        ListNode* p = start, *q = end;
        if(head == NULL)
        {
            return NULL;
        }

        while(head)
        {
            if(head->val < x)
            {
                p->next = head;
                head = head->next;
                p = p->next;
            }
            else
            {
                q->next = head;
                head = head->next;
                q = q->next;
            }
        }
        q->next = NULL;
        p->next = end->next;

        return start->next;
    }
};