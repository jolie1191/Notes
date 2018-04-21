/*

Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

*/

/*
1. 思路： 
- 分成k个k个的去reverse
- 使用dummy node，题目处理完后方便access head节点
- reverseNextK(head, k): 从head的之后的一个节点开始，reverse k 个节点， 并return下次需要开始reverse的第一个节点的前一个节点

a->n1->n2->n3->...->nk
每次reverse k个节点(n1->n2->n3->...>nk)， 收到影响的节点也包括a, 所以需要一个Dummy node（dummy node永远在这，不会变）


*/


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
        
        ListNode* curt = dummy;
        while(curt != NULL)
        {
            curt = reverNextK(curt,k);
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
