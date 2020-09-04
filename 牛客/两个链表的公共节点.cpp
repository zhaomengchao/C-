/*
��������ĵ�һ���������
�������������ҳ����ǵĵ�һ��������㡣��ע����Ϊ�����������������Դ���������ݵ���ʾ����������ʽ��ʾ�ģ���֤������������ȷ�ģ�
*/
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        ListNode* p1 = pHead1;
        ListNode* p2 = pHead2;
        
        int len1 = 0;
        while(p1)
        {
            len1++;
            p1 = p1->next;
        }
        int len2 = 0;
        while(p2)
        {
            len2++;
            p2 = p2->next;
        }
        //����ָ��
        p1 = pHead1;
        p2 = pHead2;
        
        if(len1 > len2)
        {
            for(int i = 0; i < len1- len2;i++)
            {
                p1 = p1->next;
            }
        }
        else{
            for(int i = 0; i < len2-len1;i++)
            {
                p2 = p2->next;
            }
        }
        
        while(p1 != p2)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        
        
        
        return p1;
        
    }
};