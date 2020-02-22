//链表相加，指针+标志位+新链表
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(-1);//用于存放新的链表
        ListNode* h = head;
        int sum  = 0;
        bool flag = false;

        while(l1 || l2)
        {
            sum = 0;//每次循环上来，sum都必须为0
            if(l1 != nullptr)
            {
                sum+= l1->val;
                l1 = l1->next;
            }
            if(l2 != nullptr)
            {
                sum+= l2->val;
                l2 = l2->next;
            }

            if(flag)
            {
                sum++;
            }
            h->next = new ListNode(sum % 10);
            h = h->next;

            flag = sum >= 10 ? true:false;
        }
        if(flag)//999+1
        {
            h->next = new ListNode(1);
        }
        return head->next;
    }
};