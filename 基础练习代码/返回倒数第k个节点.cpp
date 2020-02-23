//实现一种算法，找出单向链表中倒数第 k 个节点。返回该节点的值。（快慢指针）

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