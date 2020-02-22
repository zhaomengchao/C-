//输入: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
//输出: 7 -> 8 -> 0 -> 7
//如果输入链表不能修改该如何处理？换句话说，你不能对列表中的节点进行翻转。


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
        stack<int> st_sum;//用于存放节点之和
        int sum = 0;
        bool flag = false;
		//栈1.2用于存放每个节点
        stack<ListNode*> s1;
        stack<ListNode*> s2;
            while(l1 != NULL)
            {
                s1.push(l1);
                l1 = l1->next;
            }
            while(l2 != NULL)
            {
                s2.push(l2);
                l2 = l2->next;
            }
        while(!s1.empty() || !s2.empty())
        {
            sum = 0;
            if(!s1.empty())
            {
                sum += s1.top()->val;
                s1.pop();
            }
            if(!s2.empty())
            {
                sum += s2.top()->val;
                s2.pop();
            }
            if(flag)
            {
                sum++;
            }
            flag = sum >= 10 ? true:false;
            st_sum.push(sum%10);
            
        }
        if(flag)
        {
            st_sum.push(1);
        }
        ListNode *phead = new ListNode(st_sum.top());//建立单链表用于存储输出的值
        st_sum.pop();
        ListNode *ret = phead;
        while(!st_sum.empty())
        {
            ListNode* tmp = new ListNode(st_sum.top());
            st_sum.pop();
            ret->next = tmp;
            ret = ret->next;
        }
        return phead;
        
    }
};