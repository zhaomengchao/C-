//ɾ������Ľ�㣬ǰ��ָ�룬�ȴ���һ���սڵ�
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode *tmp = new ListNode(0), *pre = tmp, *cur = head;
        tmp->next = head;
        while (cur) {
            if (cur->val == val) {                
                pre->next = cur->next;
                break;
            }
            pre = cur;
            cur = cur->next;
        }
        return tmp->next;
    }
};
