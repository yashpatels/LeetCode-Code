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
    public List<String> binaryTreePaths(TreeNode root) {
        
        List<String> ans = new ArrayList();

        dfs(root, ans, String.valueOf(root.val));

        return ans;

    }

    void dfs(TreeNode root, List<String> ans, String currentPath){
        if (root.left == null && root.right == null){
            ans.add(currentPath);
            return;
        }
    
        if (root.left!=null){
            dfs(root.left, ans, currentPath+"->"+String.valueOf(root.left.val));
        }
        if (root.right!=null){
            dfs(root.right, ans, currentPath+"->"+String.valueOf(root.right.val));
        }
    }
}