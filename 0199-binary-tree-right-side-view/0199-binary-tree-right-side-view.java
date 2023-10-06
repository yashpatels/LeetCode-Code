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
    public List<Integer> rightSideView(TreeNode root) {

        if (root == null) return new ArrayList();

        Queue<TreeNode> q = new LinkedList();
        List<Integer> ans = new ArrayList();
        int prev=root.val;
        q.add(root);
        q.add(null);

        while (!q.isEmpty()){
            TreeNode x = new TreeNode();
            x = q.remove();
            if (x==null){
                ans.add(prev);
                if (!q.isEmpty()){
                    q.add(null);
                }
            } else {
                prev = x.val;
                if (x.left!=null) q.add(x.left);
                if (x.right!=null) q.add(x.right);
            }
        }
        return ans;
    
    }
}