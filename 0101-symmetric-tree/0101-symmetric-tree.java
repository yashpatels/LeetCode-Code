/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public boolean isSymmetric(TreeNode root) {

        TreeNode leftTree = root.left;
        TreeNode rightTree = root.right;

        if (rightTree==null && leftTree!=null) return false;
        if (rightTree!=null && leftTree==null) return false;
        if (rightTree==null && leftTree==null) return true;


        return isSameTree(leftTree, rightTree);
    }

    public boolean isSameTree(TreeNode p, TreeNode q) {

        if ((p==null && q!=null)){
            return false;
        } 
        if ((p!=null && q==null)){
            return false;
        } 
        if ((p==null && q==null)){
            return true;
        } 

        if (p.val != q.val){
            return false;
        }
        boolean bLeft = isSameTree(p.left, q.right);
        boolean bRight = isSameTree(p.right, q.left);
        return (bRight && bLeft);
        
    }
}