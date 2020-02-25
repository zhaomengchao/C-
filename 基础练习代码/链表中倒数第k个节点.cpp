//�����е�����k���ڵ㣨����ָ�룬����k����
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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* quick = head;
        ListNode* tail = head;

        while(k--)
        {
            quick = quick->next;
        }
        while(quick != NULL)
        {
            quick = quick->next;
            tail = tail->next;
        }

        return tail;
    }
};