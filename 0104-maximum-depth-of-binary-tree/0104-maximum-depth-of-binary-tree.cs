/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
    public int MaxDepth(TreeNode root) {
        if (root == null)
            return 0;

        int left_depth  = FindDepth(root.left, 1);
        int right_depth = FindDepth(root.right, 1);

        return Math.Max(left_depth, right_depth);
    }

    private int FindDepth(TreeNode root, int depth) {
        if (root == null)
            return depth;

        int l = FindDepth(root.left, depth+1);
        int r = FindDepth(root.right, depth+1);

        return Math.Max(l, r);
    }
}