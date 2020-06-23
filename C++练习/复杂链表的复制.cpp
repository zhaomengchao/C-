
/*
¸´ÔÓÁ´±íµÄ¸´ÖÆ
https://leetcode-cn.com/problems/fu-za-lian-biao-de-fu-zhi-lcof/
*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
 
 void copyNode(Node* head)
 {
     Node*p=head;
     while(p)
     {
         Node* pcopy=new Node(0);
         pcopy->val=p->val;
         pcopy->next=p->next;
         pcopy->random=NULL;
         p->next=pcopy;
         p=pcopy->next;
     }
 }
 void copyRandom(Node* head)
 {
     Node* p=head;
     while(p)
     {
         Node* pcopy=p->next;
         if(p->random!=NULL)
         {
             pcopy->random=p->random->next;
         }
         p=pcopy->next;
     }
 }
 Node* fengelist(Node* head)
 {
     Node* p=head;
     Node* copyhead=NULL;
     Node* copyheadp=NULL;
     if(p)
     {
         copyhead=copyheadp=p->next;
         p->next=copyheadp->next;
         p=p->next;
     }
     while(p)
     {
         copyheadp->next=p->next;
         copyheadp=copyheadp->next;
         p->next=copyheadp->next;
         p=p->next;
     }
     return copyhead;
 }
    Node* copyRandomList(Node* head) {
        if(head==NULL)
        {
            return head;
        }
        copyNode(head);
        copyRandom(head);
       return  fengelist(head);

    }
};
