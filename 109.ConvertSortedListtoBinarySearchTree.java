

public class ConvertSortedListtoBinarySearchTree {

    public TreeNode sortedListToBST(ListNode head) {

        //根据BFS的性质，对于一个sorted list它的中点一定是BFS的root
        //找到中点，再根据D&Q

        if(head == null)
            return null;
        if(head.next == null) // !!! 只有一个节点, 如果不判断这一句，searchMidByFastSlow会陷入死循环
            return new TreeNode(head.val);

        ListNode mid = searchMidByFastSlow(head);
        TreeNode root = new TreeNode(mid.val);

        TreeNode leftTree = sortedListToBST(head); //  截断前半段和后半段
        TreeNode rightTree = sortedListToBST(mid.next);

        root.left = leftTree;
        root.right = rightTree;

        return root;

    }

    //快慢指针在LinkedList中的应用
    public ListNode searchMidByFastSlow(ListNode head){
        ListNode pre = head;
        ListNode slow = head;
        ListNode fast = head;

        while(fast != null && fast.next != null){
            pre = slow;
            slow = slow.next;
            fast = fast.next.next;
        }

        pre.next = null;

        return slow;
    }

}
