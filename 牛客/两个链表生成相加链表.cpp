/*
����������ÿһ���ڵ��ֵ���� 0 - 9 ֮�䣬��ô��������Ϳ��Դ���һ��������
���������������������ɴ��������������ֵ�Ľ������
���磺���� 1 Ϊ 9->3->7������ 2 Ϊ 6->3����������µĽ������Ϊ 1->0->0->0��
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
     * @param head1 ListNode�� 
     * @param head2 ListNode�� 
     * @return ListNode��
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