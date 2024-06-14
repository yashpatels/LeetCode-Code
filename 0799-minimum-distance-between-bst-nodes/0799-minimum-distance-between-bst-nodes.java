
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
    int rootx;
    int ans=Integer.MAX_VALUE;
    void inOrder(TreeNode root) {
        if (root == null) return;

        if (root.left!=null) {
            inOrder(root.left);
        }

        if (rootx!=root.val) {
            ans = Math.min(Math.abs(root.val-rootx), ans);
            rootx=root.val;
        }

        if (root.right!=null) {
            inOrder(root.right);
        }
    }

    public int minDiffInBST(TreeNode root) {
        if (root == null) return 0;
        rootx=root.val;
        inOrder(root);
        return ans;

    }
}