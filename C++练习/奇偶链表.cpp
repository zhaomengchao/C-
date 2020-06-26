/*
奇偶链表
给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。
输入: 1->2->3->4->5->NULL
输出: 1->3->5->2->4->NULL
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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *pre=head,*cur=head->next;
        while(cur && cur->next){
            ListNode* tmp=pre->next;
            pre->next=cur->next;
            cur->next=cur->next->next;
            pre->next->next=tmp;
            
            pre=pre->next;
            cur=cur->next;
        }
        return head;
    }
};
