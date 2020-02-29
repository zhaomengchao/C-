//合并两个有序列表
//输入：1->2->4, 1->3->4
//输出：1->1->2->3->4->4
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* ret = new ListNode(0);
        ListNode* head = ret;

        while(l1 && l2)
        {
            if(l1->val <= l2->val)
            {
                head->next = l1;
                l1 = l1->next;
            }
            else
            {
                head->next = l2;
                l2 = l2->next;
            }
            head = head->next;
        }

        if(l1 != NULL)
        {
            head->next = l1;
        }
        else
        {
            head->next = l2;
        }
        return ret->next;
    }
};
