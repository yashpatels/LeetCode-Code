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
    public TreeNode invertTree(TreeNode root) {

        TreeNode x = root;

        invertTrees(x);
        
        return root;
    }

    public void invertTrees(TreeNode root){
        if (root == null) return;

        TreeNode rightTree = root.right;
        TreeNode leftTree = root.left;

        root.right = leftTree;
        root.left = rightTree;

        invertTrees(root.left);
        invertTrees(root.right);
    }
}