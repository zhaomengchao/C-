/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

class Solution {
/*
https://www.nowcoder.com/practice/f95dcdafbde44b22a6d741baf71653f6?tpId=188&&tqId=35153&rp=1&ru=/ta/job-code-high-week&qru=/ta/job-code-high-week/question-ranking
����һ������ɾ������ĵ�����n���ڵ㲢���������ͷָ��
���磬
 ����������Ϊ:1->2->3->4->5, n= 2.
 ɾ��������ĵ�����n���ڵ�֮��,�����Ϊ1->2->3->5.
��ע��
��Ŀ��֤nһ������Ч��
����������ʱ�临�Ӷ�Ϊ\ O(n) O(n)���㷨
*/
public:
    /**
     * 
     * @param head ListNode�� 
     * @param n int���� 
     * @return ListNode��
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
        
        for(int i = 0; i < size -1 ;i++)//ע��������ǰһ��λ��ͣ��
        {
            pre = pre->next;
        }
        pre->next = pre->next->next;
        
        return res;
    }
};