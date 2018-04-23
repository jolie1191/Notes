package com.company;

public class PopulatingNextRightPointersinEachNode {

    /*
    * Example:

        Given the following perfect binary tree,

             1--null
           /  \
          2 =  3 =
         / \  / \
        4  5  6  7
        After calling your function, the tree should look like:

             1 -> NULL
           /  \
          2 -> 3 -> NULL
         / \  / \
        4->5->6->7 -> NULL

*/
    public void connect(TreeLinkNode root) {

        if(root == null)
            return;

        //头结点的的(level0 到)level_1 的所有可能next的连接问题
        if(root.left != null){
            root.left.next = root.right;
            if(root.right != null && root.next != null){
                root.right.next = root.next.left;
            }
        }

        //root 的左右节点
        connect(root.left);
        connect(root.right);
    }

    //初始： 所有节点的.next to null!
    public void connect2(TreeLinkNode root){

        if(root == null)
            return;

        TreeLinkNode level_start = root;
        while(level_start != null){ //---------------------->控制level
             TreeLinkNode cur = level_start;
             while(cur != null){ // ===============>控制每一level中的每个节点next的(level0到)level_1的链接问题！
                 if(cur.left != null)
                     cur.left.next = cur.right;
                 if(cur.right != null && cur.next != null)
                     cur.right.next = cur.next.left;
                 cur = cur.next; //===============>控制每一level中的每个节点next的level_1的链接问题！
             }

             level_start = level_start.left; //--------------->控制level
         }
    }


}
