package com.company;


/*分治法：
* 1. if we want to make p and q have same structure and values,
* their left subtree and right subtree should be same*/
public class SameTree {

    public boolean isSameTree(TreeNode p, TreeNode q) {

        if(p == null && q == null)
            return true;
        else if(p == null || q == null){
            return false;
        }

        boolean left = isSameTree(p.left, q.left);
        boolean right = isSameTree(p.right, q.right);

        if(left && right && p.val == q.val)
            return true;
        else
            return false;
    }

}
