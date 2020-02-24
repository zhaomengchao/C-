//判断是否为回文链表
//利用栈进行判断
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
    bool isPalindrome(ListNode* head) {
        ListNode* ret = head;
        stack<int> s_l;

        while(ret)
        {
            s_l.push(ret->val);
            ret = ret->next;
        }
        ret = head;
        while(ret)
        {
            if(s_l.top() != ret->val)
            {
                return false;
                break;
            }
            s_l.pop();
            ret = ret->next;
        }
        return true;
    }
};