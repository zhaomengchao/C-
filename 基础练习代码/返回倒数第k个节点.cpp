//ʵ��һ���㷨���ҳ����������е����� k ���ڵ㡣���ظýڵ��ֵ��������ָ�룩

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
    int kthToLast(ListNode* head, int k) {
        if(head->next == NULL)
        {
            return head->val;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        
        while(k)
        {
            fast = fast->next;
            k--;
        }

        while(fast)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return slow->val;
    }
};