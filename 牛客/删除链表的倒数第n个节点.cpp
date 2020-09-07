/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

class Solution {
/*
https://www.nowcoder.com/practice/f95dcdafbde44b22a6d741baf71653f6?tpId=188&&tqId=35153&rp=1&ru=/ta/job-code-high-week&qru=/ta/job-code-high-week/question-ranking
给定一个链表，删除链表的倒数第n个节点并返回链表的头指针
例如，
 给出的链表为:1->2->3->4->5, n= 2.
 删除了链表的倒数第n个节点之后,链表变为1->2->3->5.
备注：
题目保证n一定是有效的
请给出请给出时间复杂度为\ O(n) O(n)的算法
*/
public:
    /**
     * 
     * @param head ListNode类 
     * @param n int整型 
     * @return ListNode类
     */
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // write code here
        ListNode* phead = head;
        ListNode* pre = head;
        ListNode* res = pre;
        
        int size = 0;
        while(phead)
        {
            size++;
            phead = phead->next;
        }
        size = size - n;
        if(size == 0)
        {
            pre = pre->next;
            return pre;
        }
        
        for(int i = 0; i < size -1 ;i++)//注意走在他前一个位置停下
        {
            pre = pre->next;
        }
        pre->next = pre->next->next;
        
        return res;
    }
};