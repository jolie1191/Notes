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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        head = dummy;
        while(head != NULL)
        {
            head = reverNextK(head,k);
        }
        
        return dummy->next;
    }
    
    //head->n1->n2->...nk->nk+1...
    //head->nk ->nk-1->.n1->nk+1...
    //return n1
    ListNode* reverNextK(ListNode* head, int k)
    {
        ListNode* n1 = head->next;
        ListNode* toKpointer = head;
        //检查是都有K个节点
        for(int i = 0; i < k; i++)
        {
            toKpointer = toKpointer->next;
            if(toKpointer == NULL)
                return NULL;
        }
        
        //reverse
        ListNode* kplus = toKpointer->next;
        //从前往后reverse: n1<-n2<-n3
        ListNode* prev = NULL;
        ListNode* cur = n1;
        while(cur != kplus)
        {
            ListNode* tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }
        
        //connect head nk n1 nk+1
        head->next = prev;
        n1->next = kplus;
        
        return n1;
    }
};
