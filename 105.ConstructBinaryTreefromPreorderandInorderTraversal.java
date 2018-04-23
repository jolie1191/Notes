package com.company;

public class ConstructBinaryTreefromPreorderandInorderTraversal {



    public TreeNode buildTree(int[] preorder, int[] inorder) {
        if(preorder == null || inorder == null)
            return null;
        else if(preorder.length != inorder.length)
            return null;


        TreeNode root = buildHelper(preorder, inorder, 0 , preorder.length - 1, 0);

        return root;
    }

    //buildHelper: 在inorder中， 根据index i 到index j， 且preorder 中的index rootleft 为root 去build tree。
    public TreeNode buildHelper(int[] preorder, int[] inorder, int i, int j, int rootleft){

        if(i > j)
            return null;

        //粗心点： rootleft不能大于最后一个index
        if(rootleft > preorder.length - 1)
            return null;

        TreeNode root = new TreeNode(preorder[rootleft]);
        int margin = searchMargin(inorder, preorder[rootleft]);

        TreeNode left = buildHelper(preorder, inorder, i, margin - 1, rootleft + 1 );
        TreeNode right = buildHelper(preorder, inorder, margin + 1, j , rootleft + margin - i + 1);
                                                                        //margin - i == offset： 右子树的root节点index
        root.left = left;
        root.right = right;

        return root;

    }

    public int searchMargin(int[] inorder, int x){
        for(int i = 0; i < inorder.length; i++){
            if(x == inorder[i])
                return i;
        }

        return -1;
    }

}
