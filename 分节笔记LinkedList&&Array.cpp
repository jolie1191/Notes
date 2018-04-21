
/*------important
大部分链表题（90%）： 结构（head） 会发生变化的，都会用到Dummy node
*/

/*1. 如何使用Dummy Node*/
dummy 作用： 在对LinkedList做完一系列的操作后，还能快做access 最后需要的头节点
ListNode* doStaff(ListNode* head)
{
  ListNode* dummy = new ListNode(0);
  dummy->next = head;
  
  //ListNode* curt = dummy;
  doOtherThing(curt);
  
  return dummy->next;
  
}

/*2. 什么时候需要使用Dummy node*/
/*
答： 当一系列的操作后，（链表结构）head会发生变化的时候， 用Dummy->next保存‘变化后’的头
*/





