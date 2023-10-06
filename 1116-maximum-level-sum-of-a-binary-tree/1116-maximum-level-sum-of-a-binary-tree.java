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
    public int maxLevelSum(TreeNode root) {

        if (root == null) return 1;
        if (root.left == null && root.right == null) return 1;

        int level = 0;
        int max = Integer.MIN_VALUE;
        int currentSum = 0;
        int ans=1;

        Queue<TreeNode> q = new LinkedList();
        q.add(root);
        q.add(null);

        while(!q.isEmpty()){
            TreeNode x = q.remove();
            
            if (x==null){
                System.out.println(currentSum +" " +max);
                level++;
                if (currentSum > max){
                    max = currentSum;
                    ans = level;
                }
                if (!q.isEmpty()){
                    q.add(null);
                }
                currentSum=0;

            } else {
                currentSum+=x.val;
                if (x.left!=null) q.add(x.left);
                if (x.right!=null) q.add(x.right);
            }
        }
        if (currentSum > max){
            max = currentSum;
            ans = level;
        }
        return ans;
        
    }
}