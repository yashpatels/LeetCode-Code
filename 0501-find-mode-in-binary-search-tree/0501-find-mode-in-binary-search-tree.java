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
    HashMap<Integer, Integer> hm = new HashMap<>();
    public int[] findMode(TreeNode root) {
        // int[] ans;
        List<Integer> arrlist = new ArrayList<Integer>();
        
        bfs(root);

        int maxF = Integer.MIN_VALUE;

        for (Map.Entry<Integer,Integer> mapElement : hm.entrySet()) {
            if (mapElement.getValue() > maxF) maxF = mapElement.getValue();
        }

        for (Map.Entry<Integer,Integer> mapElement : hm.entrySet()) {
            if (mapElement.getValue() == maxF) arrlist.add(mapElement.getKey());
        }

        int[] ans = new int[arrlist.size()];
        for (int i=0; i<arrlist.size(); i++) {
            ans[i] = arrlist.get(i);
        }
        return ans;
    }

    public void bfs(TreeNode root) {
        if (root == null) return;

        if (hm.containsKey(root.val)) hm.put(root.val, hm.get(root.val)+1);
        else hm.put(root.val, 1);

        if (root.left!=null){
            bfs(root.left);
        }
        if (root.right!=null){
            bfs(root.right);
        }
    }
}