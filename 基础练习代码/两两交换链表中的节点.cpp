/*
给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

 

示例:

给定 1->2->3->4, 你应该返回 2->1->4->3.

*/
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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* pre = head;
        ListNode* cur = head->next;
        ListNode* next = head->next->next;
        head = cur;
        while(cur){
            cur->next = pre;
            pre->next = next?next->next?next->next:next:next;
            pre = next;
            cur = next?next->next:nullptr;
            next = cur?cur->next:nullptr;
        }
        return head;
    }
};

