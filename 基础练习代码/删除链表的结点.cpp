//删除链表的结点，前后指针，先创建一个空节点
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
