/*
[牛客网]–剑指Offer 从尾到头打印单链表
[题目描述]：
输入一个链表，按链表从尾到头的顺序返回一个ArrayList。

*/
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
       
        ListNode* pre = nullptr;
        ListNode* cur = head;//避免head为空时，出现野指针
        ListNode* tmp = cur;
        
        while(cur)
        {
            tmp  = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        
        vector<int> res;
        while(pre)
        {
            res.push_back(pre->val);
            pre = pre->next;
        }
        
            
        return res;
    }
};


/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        ListNode* pre = head;
        ListNode* cur = head;
        vector<int> res;
        if(head == nullptr)//一定注意判断head为空的问题,否则一直出现栈溢出等内存问题。
        {
            return res;
        }
        //ListNode* tmp = cur;
        while(head->next)
        {
            cur = head->next;
            head->next = cur->next;
            cur->next = pre;
            pre = cur;
        }
        while(cur)
        {
            res.push_back(cur->val);
            cur = cur->next;
        }
        
            
        return res;
        
    }
};
