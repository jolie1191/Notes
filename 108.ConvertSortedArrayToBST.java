package com.company;

public class Main {

    /*
    * 总结：
    * 1. convert sorted array to BST
    * 2. sorted ---> BST 符合BST结构
    * 3. array左侧形成BST， 右侧形成BST，那么整个就是BST-->需要index索引
    * 4. 牵扯到index索引，首先判断i， j 界限： 如果i > j 结束 return null， i <= j 分治法*/

    public TreeNode sortedArrayToBST(int[] nums) {

        if(nums == null || nums.length == 0)
            return null;

        TreeNode root = TreeNodeHelper(nums, 0, nums.length - 1);

        return root;
    }

    public TreeNode TreeNodeHelper(int[] nums, int i, int j){

        if(nums == null || nums.length == 0)
            return null;

        if(i <= j ){
            int mid = i + (j - i)/2;// avoid overflow
            TreeNode left = TreeNodeHelper(nums, i, mid - 1);
            TreeNode right = TreeNodeHelper(nums, mid + 1, j);

            TreeNode root = new TreeNode(nums[mid]);
            root.left = left;
            root.right = right;

            return root;
        }

        return null;

    }

}
