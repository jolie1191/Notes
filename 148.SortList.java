public class SortList {

    //思路和mergeSort完全一样 O(nlogn)
    public ListNode sortList(ListNode head) {
        if(head == null)
            return null;
        if(head.next == null)
            return head;

        //Step 1: cut list into two
        //Step 2： sortList(lefthalf); sortList(righthalf);
        //merge two sorted list

        ListNode mid = divideMid(head);

        // ListNode sortLeft = sortList(head);
        // ListNode sortRight = sortList(mid);

        return merge(sortList(head), sortList(mid));

    }

    //find the mid point of list, and sperate the list
    //return mid
    //重点： 如何用快慢指针找到LinkedList中点， 并切割given LinkedList
    public ListNode divideMid(ListNode head){
        ListNode pre = head, slow = head, fast = head;

        while(fast != null && fast.next != null){
            pre = slow;
            slow = slow.next;
            fast = fast.next.next;
        }

        pre.next = null;

        return slow;
    }

    //重点： 如何merge two sorted LinkedList
    public ListNode merge(ListNode l1, ListNode l2){

        ListNode dummy = new ListNode(0);
        ListNode cur = dummy;

        while(l1 != null && l2 != null){
            if(l1.val < l2.val){
                cur.next = l1;
                l1 = l1.next;
            }else{
                cur.next = l2;
                l2 = l2.next;
            }
            cur = cur.next;
        }

        //衔接后半段
        if(l1 == null)
            cur.next = l2;
        if(l2 == null)
            cur.next = l1;

        return dummy.next;
    }

}
