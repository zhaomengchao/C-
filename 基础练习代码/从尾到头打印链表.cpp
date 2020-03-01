//输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。
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
    vector<int> reversePrint(ListNode* head) {
        vector<int> tmp;
        stack<int> s;
        while(head != NULL)
        {
            s.push(head->val);
            head = head->next;
        }
        while(!s.empty())
        {
            tmp.push_back(s.top());
            s.pop();
        }
        return tmp;
    }
};