/*
[ţ����]�C��ָOffer ��β��ͷ��ӡ������
[��Ŀ����]��
����һ�������������β��ͷ��˳�򷵻�һ��ArrayList��

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
        ListNode* cur = head;//����headΪ��ʱ������Ұָ��
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
        if(head == nullptr)//һ��ע���ж�headΪ�յ�����,����һֱ����ջ������ڴ����⡣
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
