//����һ������ɾ������ĵ����� n ���ڵ㣬���ҷ��������ͷ��㡣
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* res = new ListNode(0);
        if(head == NULL)
        {
            return NULL;
        }
        res->next = head;
        ListNode* fast = res;
        ListNode* slow = res;
        for(int i = 0; i < n;i++)
        {
            fast = fast->next;
        }

        while(fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* tmp = slow->next;
        slow->next = slow->next->next;
        delete tmp;
        return res->next;
    }
};