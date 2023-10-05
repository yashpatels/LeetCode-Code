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
    public TreeNode deleteNode(TreeNode root, int key) {
        if (root == null) return null;
        if (root.val == key && root.right == null && root.left == null) return null;

        TreeNode parent = null;
        TreeNode current = root;

        while (current!=null){
            if (current.val == key){
                if (parent == null){
                    TreeNode temp = root.right;
                    root = root.left;
                    if (root == null){
                        root = temp;
                    } else {
                        root = addRightValue(root, temp);
                    }
                    break;
                } else {
                    if (parent.left == current){
                        parent.left = current.left;
                        if (parent.left!=null){
                            parent.left = addRightValue(parent.left, current.right);
                        } else {
                            parent.left = current.right;
                            // parent.right = null;
                        }
                    } else {
                        parent.right = current.left;
                        if (parent.right!=null){
                            parent.right = addRightValue(parent.right, current.right);
                        } else {
                            parent.right = current.right;
                            // parent.left = null;
                        }
                    }
                }
                break;
            }
            if (current.val > key){
                parent = current;
                current = current.left;
            } else {
                parent = current;
                current = current.right;
            }
        }
        return root;
    }

    public TreeNode addRightValue(TreeNode root, TreeNode toAdd){
        if (root == null) return toAdd;
        if (toAdd == null) return root;
        // System.out.println(root.val +" "+toAdd.val);

        TreeNode current = root;
        TreeNode parent = null;
        while (current != null){
            parent = current;
            if (current.val <= toAdd.val){
                current = current.right;
            } else {
                current = current.left;
            }
        }
        if (parent.val <= toAdd.val){
            parent.right = toAdd;
        } else {
            parent.left = toAdd;
        }
        return root;
    }


}