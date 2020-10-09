/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */
//给定一个链表，请判断该链表是否为回文结构。
class Solution {
public:
    /**
     * 
     * @param head ListNode类 the head
     * @return bool布尔型
     */
    bool isPail(ListNode* head) {
        // write code here
        vector<int> res;
        ListNode* cur = head;
        while(cur)
        {
            res.push_back(cur->val);
            cur = cur->next;
        }
        int i = 0; 
        int j = res.size()-1;
        
        while( i < j)
        {
            if(res[i] == res[j])
            {
                i++;
                j--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};