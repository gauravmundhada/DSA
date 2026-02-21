/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxSum = INT_MIN;
    int solve(TreeNode* root) {
        if (!root) return 0;

        int l = solve(root->left);
        int r = solve(root->right);

        int a = l + r + root->val;
        int b = max(l, r) + root->val;
        int c = root->val;

        maxSum = max({maxSum, a, b, c});
        return max(b, c);
    }

    int maxPathSum(TreeNode* root) {
        solve(root);
        return maxSum;
    }
};

/*
3 possiblity either left subtree se milega ya right se ya khud ko include kr k left + right
*/