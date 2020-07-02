//Á´±íÏà¼Ó

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
        int carry = 0;
        int tmp = 0;
        
        ListNode* sum = NULL;
        ListNode* cur = NULL;
        ListNode* last = NULL;
        
        while ( l1 || l2) {
            if ( l1 && l2 ){
                tmp = l1 -> val + l2 -> val + carry;
            } else {
                tmp = l1 ? l1 -> val : l2 -> val;
                tmp += carry;
            }
            
            l1 = l1 ? l1 -> next : l1;
            l2 = l2 ? l2 -> next : l2;
            
            carry = tmp >= 10 ? 1 : 0;
            tmp = tmp >= 10 ? tmp - 10 : tmp;
            
            cur = new ListNode(tmp);
            sum = sum ? sum : cur;
            if ( last ){
                last -> next = cur;
                last = cur;
            } else {
                last = cur;
            }
        }
                
        if ( carry > 0 ){
            last -> next = new ListNode(1);
        }
        
        return sum;
    
    }
};
