/*
假设链表中每一个节点的值都在 0 - 9 之间，那么链表整体就可以代表一个整数。
给定两个这种链表，请生成代表两个整数相加值的结果链表。
例如：链表 1 为 9->3->7，链表 2 为 6->3，最后生成新的结果链表为 1->0->0->0。
*/
/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param head1 ListNode类 
     * @param head2 ListNode类 
     * @return ListNode类
     */
    ListNode* addInList(ListNode* head1, ListNode* head2) {
        // write code here
        ListNode* A = head1;
        ListNode* B = head2;
 
        stack<int> tmpA,tmpB;
        while(A){
            tmpA.push(A->val);
            A = A->next;
        }
        while(B){
            tmpB.push(B->val);
            B = B->next;
        }
 
        int per = 0;
        ListNode* L = new ListNode(0);
        while(!tmpA.empty() || !tmpB.empty() || per != 0){
            int x = 0, y = 0;
            if(!tmpA.empty()){
                x = tmpA.top();
                tmpA.pop();
            }
            if(!tmpB.empty()){
                y = tmpB.top();
                tmpB.pop();
            }
            int sum = x + y + per;
            per = sum / 10;
            ListNode* node = new ListNode(sum%10);
            node->next = L->next;
            L->next = node;
        }
        return L->next;
        
    }
};