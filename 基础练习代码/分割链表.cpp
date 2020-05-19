//�ָ���������x��ֵ����������С�ڵ���x����x����ߣ�����x����x���ұ�
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
        ListNode* shead = new ListNode(0);
        ListNode* bhead = new ListNode(0);

        ListNode* p1 = shead,*p2 = bhead;
        ListNode* p = head;

        while(p)
        {
            if(p->val<x){
                p1->next=p;
                p1=p1->next;
            }else{
                p2->next=p;
                p2=p2->next;
            }
            p=p->next;

        }
        if(bhead)
        {
            p1->next = bhead->next;
        }
        p2->next = nullptr;
        return shead->next;

    }
};